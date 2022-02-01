#include "Piece.hpp"

namespace Pieces {
	struct Bishop : public Piece {
		Bishop(Pos _pos) { pos = _pos; };

		Bitboard genMoves();
	};
}