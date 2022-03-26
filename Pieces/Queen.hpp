#include "Piece.hpp"

namespace Pieces {
	struct Queen : public Piece {
		using Piece::Piece;

		PieceType const type = PieceType::Queen;

		Bitboard getMoveRange();
		operator std::string() const { return "Queen"; }
	};
}