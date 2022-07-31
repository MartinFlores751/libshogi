#pragma once

#include <libshogi/shogi-piece.hpp>

namespace shogi {
/**
 * @brief Implementation of Knight Piece from shogi.
 *
 */
class KnightPiece final : public ShogiPiece {
public:
  /**
   * @brief Construct a new Knight Piece object, passing all items to ShogiPiece
   * constructor.
   *
   * @param x X-Coordinate of piece.
   * @param y Y-Coordinate of piece.
   * @param color Piece sidedness.
   */
  KnightPiece(int x, int y, PieceColor color);
  virtual ~KnightPiece() = default;

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
   * @brief Promotes Knight to 'Narikei', effectively a gold general.
   *
   */
  void promote() noexcept override;
};
} // namespace shogi