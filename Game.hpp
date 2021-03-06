
#include <array>
#include <tuple>
#include "Pieces/Piece.hpp"
#include "Gameboard.hpp"
#include <iostream>

class Game {
	GameBoard gameBoard;

	
	Bitboard genMoves(Piece const& piece) const;

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

public:

	//Debug functions
	Bitboard getMovesFromPos(Pos pos) const;
	Bitboard getBitBoard() const { return gameBoard.getWholeBoard(); }
	void movePiece(Pos start, Pos end);

	std::string gameOutput() const;
};
