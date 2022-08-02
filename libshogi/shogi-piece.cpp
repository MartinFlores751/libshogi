#include <libshogi/shogi-piece.hpp>

namespace shogi {
ShogiPiece::ShogiPiece(int x, int y, PieceColor color)
    : x{x}, y{y}, color{color} {}

void ShogiPiece::movePiece(int newX, int newY) noexcept {
  auto positionChange = computeRelativeMovement(newX, newY);
  bool isValidMove = move(positionChange.first, positionChange.second);

  // Perform bounds checking
  if (isValidMove) {
    if ((newX >= 1 && newX <= 9) && (newY >= 1 && newY <= 9)) {
      x = newX;
      y = newY;
    }
  }
}

std::pair<int, int> ShogiPiece::computeRelativeMovement(int newX, int newY) {
  auto position = getPosition();
  auto color = pieceColor();

  std::pair<int, int> positionChange{newX - position.first,
                                     newY - position.second};

  // Flip to White's perspective
  if (ShogiPiece::PieceColor::White == color) {
    positionChange.first *= -1;
    positionChange.second *= -1;
  }

  return positionChange;
}
} // namespace shogi