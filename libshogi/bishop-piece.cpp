#include <libshogi/bishop-piece.hpp>

namespace shogi {
BishopPiece::BishopPiece(int x, int y, PieceColor color)
    : ShogiPiece(x, y, color) {}

bool BishopPiece::move(int newX, int newY) noexcept {
  if (newX == 0 || newY == 0) {
    return false;
  }

  // Remainder greater than 0 implies not a 1/1 slope
  int remainder = newX % newY;

  return remainder == 0 ? true : false;
}
void BishopPiece::promote() noexcept {}
} // namespace shogi