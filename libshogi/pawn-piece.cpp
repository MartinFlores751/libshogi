#include <libshogi/pawn-piece.hpp>
#include <math.h>

namespace shogi {
PawnPiece::PawnPiece(int x, int y, PieceColor color)
    : ShogiPiece(x, y, color) {}

bool PawnPiece::move(int newX, int newY) noexcept {
  return newX == 0 && newY == 1; // Ensure Pawn only moves 1 block forward
}
void PawnPiece::promote() noexcept {}
} // namespace shogi