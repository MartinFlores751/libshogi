#pragma once

#include <libshogi/shogi-piece.hpp>

namespace shogi {
/**
 * @brief Implementation of Gold General Piece from shogi.
 *
 */
class GoldPiece final : public ShogiPiece {
public:
  /**
   * @brief Construct a new Gold General Piece object, passing all items to
   * ShogiPiece constructor.
   *
   * @param x X-Coordinate of piece.
   * @param y Y-Coordinate of piece.
   * @param color Piece sidedness.
   */
  GoldPiece(int x, int y, PieceColor color);
  virtual ~GoldPiece() = default;

private:
  /**
   * @brief Verifies movement within 1 block in any direction, asside from
   * rearward diagonals.
   *
   * @param newX Desired X-Coordinate.
   * @param newY Desired Y-Coordinate.
   * @return true If the move is valid.
   * @return false If the move is invalid.
   */
  bool move(int newX, int newY) noexcept override;

  /**
   * @brief A Gold General does not promote.
   *
   */
  void promote() noexcept override;
};
} // namespace shogi