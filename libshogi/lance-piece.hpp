#pragma once

#include <libshogi/shogi-piece.hpp>

namespace shogi {
/**
 * @brief Implementation of Lance Piece from shogi.
 *
 */
class LancePiece final : public ShogiPiece {
public:
  /**
   * @brief Construct a new Lance Piece object, passing all items to ShogiPiece
   * constructor.
   *
   * @param x X-Coordinate of piece.
   * @param y Y-Coordinate of piece.
   * @param color Piece sidedness.
   */
  LancePiece(int x, int y, PieceColor color);
  virtual ~LancePiece() = default;

private:
  /**
   * @brief Verifies piece ranges foreward.
   *
   * @param newX Desired X-Coordinate.
   * @param newY Desired Y-Coordinate.
   * @return true If the move is valid.
   * @return false If the move is invalid.
   */
  bool move(int newX, int newY) noexcept override;

  /**
   * @brief Promotes Lance to 'narikyou', effectively a gold general.
   *
   */
  void promote() noexcept override;
};
} // namespace shogi