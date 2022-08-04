#include <libshogi/rook-piece.hpp>

namespace shogi {
RookPiece::RookPiece(int x, int y, PieceColor color)
    : ShogiPiece(x, y, color) {}

bool RookPiece::move(int newX, int newY) noexcept {
  return (newX == 0 && newY != 0) || (newY == 0 && newX != 0) ? true : false;
}
void RookPiece::promote() noexcept {}
} // namespace shogi