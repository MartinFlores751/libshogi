#include <libshogi/lance-piece.hpp>

namespace shogi {
LancePiece::LancePiece(int x, int y, PieceColor color)
    : ShogiPiece(x, y, color) {}

bool LancePiece::move(int newX, int newY) noexcept {
  std::pair<int, int> pos{getPosition()};

  return false;
}
void LancePiece::promote() noexcept {}
} // namespace shogi