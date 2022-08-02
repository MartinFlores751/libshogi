#pragma once

#include <utility>

namespace shogi {

/**
 * @brief A NVI for shogi pieces to extend.
 *
 */
class ShogiPiece {
public:
  /**
   * @brief Used to represent sidedness of shogi pieces.
   *
   */
  enum class PieceColor { Black, White };

  /**
   * @brief Construct a new Shogi Piece object.
   *
   * @param x X-Coordinate of shogi piece.
   * @param y Y-Coordinate of shogi piece.
   * @param color Represents sidedness of piece.
   */
  ShogiPiece(int x, int y, PieceColor color);
  virtual ~ShogiPiece() = default;

  /**
   * @brief Helper method to get sidedness of current piece.
   *
   * @return PieceColor
   */
  PieceColor pieceColor() const noexcept { return color; }

  /**
   * @brief Get the Position object.
   *
   * @return std::pair<int, int> Represents X and Y Coordinates respectively.
   */
  std::pair<int, int> getPosition() const noexcept {
    return std::make_pair(x, y);
  }

  /**
   * @brief Given a valid move, move piece to desired location on board.
   *
   * @param newX Intended X Coordinate destination.
   * @param newY Intended Y Coordinate destination.
   */
  void movePiece(int newX, int newY) noexcept;

private:
  int x;
  int y;
  PieceColor color;

  /**
   * @brief Get the relative movement of piece
   *
   * @param newX Desired X Coordinate
   * @param newY Desired Y Coordinate
   * @return std::pair<int, int> Relative movement from 'view' of Piece.
   */
  std::pair<int, int> computeRelativeMovement(int newX, int newY);

  /**
   * @brief To be implemented by derived classes, specifying move
   * behaviors.
   *
   * @param x Intended X Coordinate destination.
   * @param y Intended Y Coordinate destination.
   * @return true If move is able to be performed.
   * @return false If move is invalid.
   */
  virtual bool move(int x, int y) noexcept = 0;

  /**
   * @brief To be implemented by derived classes, specifying promotion
   * behaviours
   *
   */
  virtual void promote() noexcept = 0;
};
} // namespace shogi