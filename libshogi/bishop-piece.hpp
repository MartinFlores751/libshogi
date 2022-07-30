#pragma once

#include <libshogi/shogi-piece.hpp>

namespace shogi {
/**
 * @brief Implementation of Bishop Piece from shogi.
 *
 */
class BishopPiece final : public ShogiPiece {
public:
  /**
   * @brief Construct a new Bishop Piece object, passing all items to ShogiPiece
   * constructor.
   *
   * @param x X-Coordinate of piece.
   * @param y Y-Coordinate of piece.
   * @param color Piece sidedness.
   */
  BishopPiece(int x, int y, PieceColor color);
  virtual ~BishopPiece() = default;

private:
  /**
   * @brief Verifies piece ranges diagonally.
   *
   * @param newX Desired X-Coordinate.
   * @param newY Desired Y-Coordinate.
   * @return true If the move is valid.
   * @return false If the move is invalid.
   */
  bool move(int newX, int newY) noexcept override;

  /**
   * @brief Promotes Bishop to Horse.
   *
   */
  void promote() noexcept override;
};
} // namespace shogi