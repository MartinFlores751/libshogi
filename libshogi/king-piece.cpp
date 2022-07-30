#include <libshogi/king-piece.hpp>

namespace shogi {
KingPiece::KingPiece(int x, int y, PieceColor color)
    : ShogiPiece(x, y, color) {}

bool KingPiece::move(int newX, int newY) noexcept {
  std::pair<int, int> pos{getPosition()};
  if (newX >= pos.first - 1 && newX <= pos.first + 1) {
    if (newY >= pos.second - 1 && newY <= pos.second + 1) {
      return true;
    }
  }
  return false;
}
void KingPiece::promote() noexcept {}
} // namespace shogi