#include <libshogi/gold-piece.hpp>

namespace shogi {
GoldPiece::GoldPiece(int x, int y, PieceColor color)
    : ShogiPiece(x, y, color) {}

bool GoldPiece::move(int newX, int newY) noexcept {
  std::pair<int, int> pos{getPosition()};
  int forwardDistance{newY - pos.second};
  // Handle foreward cases
  if (forwardDistance == 1 || forwardDistance == 0) {
    if (newX >= pos.first - 1 || newX <= pos.first + 1) {
      return true;
    }
  } else if (forwardDistance == -1 && newX == pos.first) {
    return true;
  }
  return false;
}
void GoldPiece::promote() noexcept {}
} // namespace shogi