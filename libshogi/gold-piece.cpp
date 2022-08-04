#include <libshogi/gold-piece.hpp>

namespace shogi {
GoldPiece::GoldPiece(int x, int y, PieceColor color)
    : ShogiPiece(x, y, color) {}

bool GoldPiece::move(int newX, int newY) noexcept {
  if ((newY == 1 || newY == 0) && (newX >= -1 || newX <= 1)) {
    return true;
  } else if (newY == -1 && newX == 0) {
    return true;
  }
  return false;
}
void GoldPiece::promote() noexcept {}
} // namespace shogi