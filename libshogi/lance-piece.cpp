#include <libshogi/lance-piece.hpp>

namespace shogi {
LancePiece::LancePiece(int x, int y, PieceColor color)
    : ShogiPiece(x, y, color) {}

bool LancePiece::move(int newX, int newY) noexcept {
  std::pair<int, int> pos{getPosition()};

  if (newX != pos.first || pos.second >= newY) {
    return false;
  }

  return true;
}
void LancePiece::promote() noexcept {}
} // namespace shogi