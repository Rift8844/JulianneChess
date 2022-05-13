#include <bit>
#include <optional>
#include <array>
#include <algorithm>
#include <sstream>
#include "Game.hpp"
#include "Pieces/PieceMoveTables.hpp"


//ok i know its not the best code but like
//who cares ig youll like figure it out or sum
//if you wanna read it XD
Bitboard Game::genMoves(Piece const& piece) const {
	Bitboard moveSpace = 0x00;

	switch (piece.getType()) {

		case (PieceType::King) : {
			moveSpace = genKingMoves(piece);
			break;
		}

		case (PieceType::Queen) : {
			moveSpace = genStraightMoves(piece) | genDiagonalMoves(piece);
			break;
		}

		case (PieceType::Rook) : {
			moveSpace = genStraightMoves(piece);
			moveSpace |= genCastleMoves(piece.getColor());

			break;
		}

		case (PieceType::Bishop) : {
			moveSpace = genDiagonalMoves(piece);
			break;
		}

		case (PieceType::Knight) : {
			moveSpace = genKnightMoves(piece);
			break;
		}

		case (PieceType::Pawn) : {
			moveSpace = genPawnMoves(piece);
			break;
		}
	}

	moveSpace &= ~gameBoard.getColorBoard(piece.getColor());

	return moveSpace;
}





Bitboard Game::genStraightMoves(Piece const& piece) const {
	Bitboard moveSpace = 0x00;

	moveSpace |= genMoveSpacePart(Pieces::MoveTables::upStraight
		[piece.getPos().column][piece.getPos().row], true);

	moveSpace |= genMoveSpacePart(Pieces::MoveTables::downStraight
		[piece.getPos().column][piece.getPos().row], false);

	moveSpace |= genMoveSpacePart(Pieces::MoveTables::leftStraight
		[piece.getPos().column][piece.getPos().row], true);

	moveSpace |= genMoveSpacePart(Pieces::MoveTables::rightStraight
		[piece.getPos().column][piece.getPos().row], false);	

	return moveSpace;
}

Bitboard Game::genDiagonalMoves(Piece const& piece) const {
	Bitboard moveSpace = 0x00;

	moveSpace |= genMoveSpacePart(Pieces::MoveTables::upRight
		[piece.getPos().column][piece.getPos().row], true);

	moveSpace |= genMoveSpacePart(Pieces::MoveTables::upLeft
		[piece.getPos().column][piece.getPos().row], true);

	moveSpace |= genMoveSpacePart(Pieces::MoveTables::downRight
		[piece.getPos().column][piece.getPos().row], false);

	moveSpace |= genMoveSpacePart(Pieces::MoveTables::downLeft
		[piece.getPos().column][piece.getPos().row], false);	

	return moveSpace;
}

/*Wether to use MSB or use LSB for finding
the nearest intersected piece*/
Bitboard Game::genMoveSpacePart(Bitboard rangePart, bool spansUp) const {

	Bitboard intersect = rangePart & gameBoard.getWholeBoard();

	if (!intersect)
		return rangePart;

	/*Select the closest piece to the piece
	we are generating move data for...*/
	uint8_t targetBitIdx = spansUp ? 
			std::countr_zero(intersect) :
			63 - std::countl_zero(intersect);
	
	Bitboard targetPiece = 0b01;
	targetPiece <<= targetBitIdx;

	Bitboard rangePartIdx = spansUp ? 
			std::countr_zero(rangePart) :
			63 - std::countl_zero(rangePart);


	Bitboard clipMask = rangePart;

	//Make branchless later
	if (spansUp) {
		clipMask <<= targetBitIdx - rangePartIdx;
	} else {
		clipMask >>= rangePartIdx - targetBitIdx;
	}

	/*
	Bitboard tailClipMask = 0b1;

	tailClipMask <<= spansUp ? 
			std::countr_zero(intersect) :
			63 - std::countl_zero(intersect);
	*/

	//Preserve the target piece bit
	Bitboard moveSpacePart = rangePart & ~clipMask /*& ~tailClipMask*/ | targetPiece;

	return moveSpacePart;
}


Bitboard Game::genPawnMoves(Piece const& piece) const {
	Bitboard moveSpace = 0x00;

	bool movesUp = piece.getColor() == Color::White;

	Bitboard moveTile = movesUp ? 
		piece.getBBoard() << 8 : piece.getBBoard() >> 8;

	/*No need to check if the pawn is at the end of the board,
	since it will always be promoted to a different piece*/
	if (!(moveTile & gameBoard.getWholeBoard()))nne
		moveSpace |= moveTile;


	moveTile = movesUp ? 
		piece.getBBoard() << 7 : piece.getBBoard() >> 7;

	if (moveTile & gameBoard.getColorBoard(!piece.getColor())) {
		moveSpace |= moveTile;
	}


	moveTile = movesUp ? 
		piece.getBBoard() << 9 : piece.getBBoard() >> 9;

	if (moveTile & gameBoard.getColorBoard(!piece.getColor())) {
		moveSpace |= moveTile;
	}


	return moveSpace;
}

//Shoud I ditch these?!?
Bitboard Game::genKnightMoves(Piece const& piece) const {
	return piece.getMoveRange();
}

Bitboard Game::genKingMoves(Piece const& piece) const  {
	return piece.getMoveRange() | genCastleMoves(piece.getColor());
}


void Game::movePiece(Pos start, Pos end) {

	if (!(genMoves(gameBoard.getPiece(start)) & end.asBitBoard())) {
		std::cerr << "Error: invalid move" << std::endl;
		//throw std::exception();
		return;
	}

	gameBoard.movePiece(start, end);
}


Bitboard genCastleMoves(Color color) {
	Bitboard castleMask = 0x00;
	uint8_t const row = color == Color::Black ? 7 : 0;

	//Mask of space between the king and the rooks
	Bitboard const lSpaceMask = 0x70 << row * 8;
	Bitboard const rSpaceMask = 0x06 << row * 8;

	Bitboard const lCastleMask = 0x88 << row * 8;
	Bitboard const rCastleMask = 0x09 << row * 8;

	bool checkConds = [](Piece* piece, PieceType type) = {
		return piece && piece->getType() == type && !piece->hasMoved();
	};

	Piece* king = gameBoard.getPiece({4, row});

	if (!checkConds(king, PieceType::King))
		return 0x00;

	std::pair<Piece*, Piece*> rooks = std::make_pair(
			gameBoard.getPiece({0, row}), 
			gameBoard.getPiece({7, row})
		);

	if (checkConds(rooks.first, PieceType::Rook) && 
		!(gameBoard.getWholeBoard() & lSpaceMask)) {
		castleMask |= lCastleMask;
	}

	if (!checkConds(rooks.second, PieceType::Rook) &&
		!(gameBoard.getWholeBoard() & rSpaceMask)) {
		castleMask |= rCastleMask;
	}

	return castleMask;
}

/*
00000000
00000000
00000000
00000000
00000000
00000000
00000000
00000110
*/


Bitboard Game::getMovesFromPos(Pos pos) const {
	return genMoves(gameBoard.getPiece(pos));
}








std::string Game::gameOutput() const {
	std::ostringstream stream;

	stream << "Will Smith vs Chris Rock:\n\n";
	stream << gameBoard;

	return stream.str();
}