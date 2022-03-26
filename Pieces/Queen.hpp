#include "Piece.hpp"

namespace Pieces {
	struct Queen : public Piece {
		Queen(Pos _pos) { pos = _pos; };

		PieceType const type = PieceType::Queen;

		Bitboard getMoveRange();
		std::array<Pos, 8> genAttackList(GameBoard const& gb);

		operator std::string() const { return "Queen"; }
	};
}