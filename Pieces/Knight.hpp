#include "Piece.hpp"

namespace Pieces {
	struct Knight : public Piece {
		using Piece::Piece;

		bool canCastle = true;

		PieceType const type = PieceType::Knight;

		Bitboard getMoveRange() const;

		operator std::string() const { return "Knight"; }
	};
}