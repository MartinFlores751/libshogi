#include <libshogi/knight-piece.hpp>

namespace shogi {
KnightPiece::KnightPiece(int x, int y, PieceColor color)
    : ShogiPiece(x, y, color) {}

bool KnightPiece::move(int newX, int newY) noexcept {
  std::pair<int, int> pos{getPosition()};

  if ((newY == (pos.second + 2)) &&
      (newX == pos.first - 1 || newX == pos.first + 1)) {
    return true;
  }

  return false;
}
void KnightPiece::promote() noexcept {}
} // namespace shogi