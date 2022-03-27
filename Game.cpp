#include <bit>
#include <optional>
#include "Game.hpp"
#include "Pieces/PieceMoveTables.hpp"


void Game::genMoves(Piece const& piece) {

	//This works for now I guess
	//if ()
};

/*Consdier using a hardware accelerated approach later*/

PieceMoveData Game::genStraightData(Piece const& piece) const {

	//Change later
	Bitboard moveRange = 0x00;
	std::array<Pos, 8> attacks = {{POS_NONE, POS_NONE, POS_NONE, POS_NONE,
							 POS_NONE, POS_NONE, POS_NONE, POS_NONE}};
	//...
	return std::make_pair(moveRange, attacks);
}

PieceMoveData Game::genDiagonalData(Piece const& piece) const {
	Bitboard moveRange = 0x00;
	std::array<Pos, 8> attacks = {{POS_NONE, POS_NONE, POS_NONE, POS_NONE,
							 POS_NONE, POS_NONE, POS_NONE, POS_NONE}};
	//...
	return std::make_pair(moveRange, attacks);
}


//<Bitboard move, (optional) attack position>
/*Wether to use MSB or use LSB for finding
the nearest intersected piece*/
std::pair<Bitboard, std::optional<Pos>> 
	Game::genMoveDataPart(Bitboard rangePart, bool useMSB) const {

		/*Select the closest piece to the piece
	we are generating move data for...*/
	uint8_t targetBitIdx = useMSB ? 
			63 - std::countl_zero(rangePart) : std::countr_zero(rangePart);


	Bitboard targetPiece = 0b01;
	/*Select the closest piece to the piece
	we are generating move data for...*/
	targetPiece <<= targetBitIdx;
	//If it's on the board
	targetPiece &= gameBoard.getWholeBoard();

	if (!targetPiece)
		std::make_pair(rangePart, std::nullopt);


	Bitboard rangePartIdx = useMSB ? 
			63 - std::countl_zero(rangePart) 
				: std::countr_zero(rangePart);


	Bitboard clipMask = rangePart;

	if (useMSB) {
		clipMask <<= targetBitIdx - rangePartIdx;
	} else {
		clipMask >>= rangePartIdx - targetBitIdx;
	}

	rangePart &= ~clipMask;

	//x >> 3 divides x by 8 and discards remainder
	return std::make_pair(
				rangePart,
				std::make_optional<Pos>(Pos {targetBitIdx % 8, targetBitIdx >> 3})
			);
}