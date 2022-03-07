#include "Piece.hpp"

namespace Pieces {
	struct Queen : public Piece {
		Queen(Pos _pos) { pos = _pos; };

		//PieceType const type = Pieces::Queen;

		Bitboard getMoveRange();
		operator std::string() const { return "Queen"; }
	};
}