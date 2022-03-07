#include "Piece.hpp"

namespace Pieces {
	struct Rook : public Piece {
		Rook(Pos _pos) { pos = _pos; };
		/*Permanently set to false if piece has 
		moved and / or castled*/
		bool canCastle = true;

		//PieceType const type = Pieces::Rook;

		//Bitboard genCastle();
		Bitboard getMoveRange();
		operator std::string() const { return "Queen"; }
	};
}