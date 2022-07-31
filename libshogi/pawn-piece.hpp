#pragma once

#include <libshogi/shogi-piece.hpp>

namespace shogi {
/**
 * @brief Implementation of Pawn Piece from shogi.
 *
 */
class PawnPiece final : public ShogiPiece {
public:
  /**
   * @brief Construct a new Pawn Piece object, passing all items to ShogiPiece
   * constructor.
   *
   * @param x X-Coordinate of piece.
   * @param y Y-Coordinate of piece.
   * @param color Piece sidedness.
   */
  PawnPiece(int x, int y, PieceColor color);
  virtual ~PawnPiece() = default;

private:
  /**
   * @brief Verifies piece steps forward.
   *
   * @param newX Desired X-Coordinate.
   * @param newY Desired Y-Coordinate.
   * @return true If the move is valid.
   * @return false If the move is invalid.
   */
  bool move(int newX, int newY) noexcept override;

  /**
   * @brief Promotes Pawn to 'tokin', effectivly a gold general.
   *
   */
  void promote() noexcept override;
};
} // namespace shogi