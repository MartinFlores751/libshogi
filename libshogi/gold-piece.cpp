#include <libshogi/gold-piece.hpp>

namespace shogi {
GoldPiece::GoldPiece(int x, int y, PieceColor color)
    : ShogiPiece(x, y, color) {}

bool GoldPiece::move(int newX, int newY) noexcept { return false; }
void GoldPiece::promote() noexcept {}
} // namespace shogi