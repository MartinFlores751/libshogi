#include <libshogi/knight-piece.hpp>
#include <math.h>

namespace shogi {
KnightPiece::KnightPiece(int x, int y, PieceColor color)
    : ShogiPiece(x, y, color) {}

bool KnightPiece::move(int newX, int newY) noexcept {
  std::pair<int, int> pos{getPosition()};

  if ((newX == pos.first) || (newY == pos.second)) {
    return false;
  }

  float slope = std::abs((newX - pos.first) / (newY - pos.second));
  return slope == 1 ? true : false;
}
void KnightPiece::promote() noexcept {}
} // namespace shogi