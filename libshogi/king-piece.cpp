#include <libshogi/king-piece.hpp>

namespace shogi {
KingPiece::KingPiece(int x, int y, PieceColor color)
    : ShogiPiece(x, y, color) {}

bool KingPiece::move(int newX, int newY) noexcept {
  // No movement is invalid
  if (newX == 0 && newY == 0) {
    return false;
  }

  // Moving in any adjacent block
  if ((newX >= -1 && newX <= 1) && (newY >= -1 && newY <= 1)) {
    return true;
  }

  // No other move is valid
  return false;
}
void KingPiece::promote() noexcept {}
} // namespace shogi