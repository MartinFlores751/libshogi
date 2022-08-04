#include <libshogi/lance-piece.hpp>

namespace shogi {
LancePiece::LancePiece(int x, int y, PieceColor color)
    : ShogiPiece(x, y, color) {}

bool LancePiece::move(int newX, int newY) noexcept {
  return (newX == 0 && newY >= 1) ? true : false;
}
void LancePiece::promote() noexcept {}
} // namespace shogi