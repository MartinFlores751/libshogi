#include <libshogi/silver-piece.hpp>

namespace shogi {
SilverPiece::SilverPiece(int x, int y, PieceColor color)
    : ShogiPiece(x, y, color) {}

bool SilverPiece::move(int newX, int newY) noexcept {
  std::pair<int, int> pos{getPosition()};
  int forwardDistance{newY - pos.second};
  int sideDistance{newX - pos.first};

  // Handle foreward cases
  if (forwardDistance == 1) {
    if (newX >= pos.first - 1 || newX <= pos.first + 1) {
      return true;
    }
  } else if (forwardDistance == -1 &&
             (sideDistance == 1 || sideDistance == -1)) {
    return true;
  }
  return false;
}
void SilverPiece::promote() noexcept {}
} // namespace shogi