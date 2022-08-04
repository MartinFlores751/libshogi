#include <libshogi/silver-piece.hpp>

namespace shogi {
SilverPiece::SilverPiece(int x, int y, PieceColor color)
    : ShogiPiece(x, y, color) {}

bool SilverPiece::move(int newX, int newY) noexcept {
  if (newY == 1 && (newX >= -1 || newX <= +1)) {
    return true;
  } else if (newY == -1 && (newX == 1 || newX == -1)) {
    return true;
  }
  return false;
}
void SilverPiece::promote() noexcept {}
} // namespace shogi