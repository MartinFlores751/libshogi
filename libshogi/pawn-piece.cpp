#include <libshogi/pawn-piece.hpp>
#include <math.h>

namespace shogi {
PawnPiece::PawnPiece(int x, int y, PieceColor color)
    : ShogiPiece(x, y, color) {}

bool PawnPiece::move(int newX, int newY) noexcept {
  std::pair<int, int> pos{getPosition()};

  if (newY == pos.first + 1)
    return true;

  return false;
}
void PawnPiece::promote() noexcept {}
} // namespace shogi