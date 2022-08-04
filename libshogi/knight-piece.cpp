#include <libshogi/knight-piece.hpp>

namespace shogi {
KnightPiece::KnightPiece(int x, int y, PieceColor color)
    : ShogiPiece(x, y, color) {}

bool KnightPiece::move(int newX, int newY) noexcept {
  if ((newY == 2) && (newX == -1 || newX == 1)) {
    return true;
  }
  return false;
}
void KnightPiece::promote() noexcept {}
} // namespace shogi