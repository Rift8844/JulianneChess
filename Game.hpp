
#include <array>
#include <tuple>
#include "Pieces/Piece.hpp"
#include "Gameboard.hpp"
#include <optional>
#include <iostream>

enum class GameStatus {
	WhiteTurn,
	BlackTurn,
	BlackWin,
	WhiteWin,
	//DrawAgreement,
	Stalemate
	//InsuffMaterial,
	//ThreeFoldRep,
	//FiftyMove,
	//DeadPos
};

class Game {

	GameBoard gameBoard;

	int numMoves = 0;

	GameStatus status = GameStatus::WhiteTurn;
	
	struct Cache {
		Bitboard boardIntersect;
		Bitboard moveSpace;
	};
	
	//Cache each piece's move space, along with a list of it's
	//board intersections to check if it's old moves are still valid

	//For optimization reasons, this also stores moves that would put 
	//the piece's team's king in check even though it is ILLEGAL
	std::unordered_map<const Piece*, Cache> pieceDatCache;
	
	Bitboard genMoves(Piece const& piece);

	//Generate movespace and attack possibilities pair

	//Note: NONE of these test for CHECK! This must be
	//Implemented later
	Bitboard genStraightMoves(Piece const& piece) const;
	Bitboard genDiagonalMoves(Piece const& piece) const;

	Bitboard genKnightMoves(Piece const& piece) const;
	Bitboard genPawnMoves(Piece const& piece) const;
	Bitboard genKingMoves(Piece const& piece) const;

	//Generates **KING'S** castle moves
	Bitboard genCastleMoves(Piece const& piece) const;

	/*Generate movespace a move part range, and wether 
	it points upwards or downwards*/
	Bitboard genMoveSpacePart(Bitboard rangePart, bool spanUp) const;

	//NEEEEEEDS to be optimized!
	bool isCheck(Color color, std::optional<Pos> kingPosHint = std::nullopt);

	//Exclusively used for check detecting functions...
	//doesn't behave the same as the rest of the move gen functions
	Bitboard genPawnThreat(Piece const& piece) const;

	void updateGameStatus();

public:

	//Debug functions
	Bitboard getMovesFromPos(Pos pos);
	Bitboard getBitBoard() const { return gameBoard.getWholeBoard(); }

	void movePiece(Pos start, Pos end);
	void undoMove() { gameBoard.undoMove(); numMoves--; }
	void redoMove() { gameBoard.redoMove(); numMoves++; }

	std::string gameOutput();

	Game();
};
