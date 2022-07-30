#include <libshogi/shogi-piece.hpp>

namespace shogi {
ShogiPiece::ShogiPiece(int x, int y, PieceColor color)
    : x{x}, y{y}, color{color} {}

void ShogiPiece::movePiece(int newX, int newY) noexcept {
  bool isValidMove = move(newX, newY);
  if (isValidMove) {
    if ((newX >= 1 && newX <= 9) && (newY >= 1 && newY <= 9)) {
      x = newX;
      y = newY;
    }
  }
}
} // namespace shogi