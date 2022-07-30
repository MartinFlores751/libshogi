#include <libshogi/rook-piece.hpp>

namespace shogi {
RookPiece::RookPiece(int x, int y, PieceColor color)
    : ShogiPiece(x, y, color) {}

bool RookPiece::move(int newX, int newY) noexcept {
  std::pair<int, int> pos{getPosition()};

  if (newX != pos.first && newY != pos.second) {
    return false;
  }

  return true;
}
void RookPiece::promote() noexcept {}
} // namespace shogi