#pragma once

#include <libshogi/shogi-piece.hpp>

namespace shogi {
/**
 * @brief Implementation of Silver General Piece from shogi.
 *
 */
class SilverPiece final : public ShogiPiece {
public:
  /**
   * @brief Construct a new Silver General Piece object, passing all items to
   * ShogiPiece constructor.
   *
   * @param x X-Coordinate of piece.
   * @param y Y-Coordinate of piece.
   * @param color Piece sidedness.
   */
  SilverPiece(int x, int y, PieceColor color);
  virtual ~SilverPiece() = default;

private:
  /**
   * @brief Verifies movement of 1 block in the forward direction, as well as
   * the rearward diagonals
   *
   * @param newX Desired X-Coordinate.
   * @param newY Desired Y-Coordinate.
   * @return true If the move is valid.
   * @return false If the move is invalid.
   */
  bool move(int newX, int newY) noexcept override;

  /**
   * @brief A Silver General promotes to effectively a Gold General.
   *
   */
  void promote() noexcept override;
};
} // namespace shogi