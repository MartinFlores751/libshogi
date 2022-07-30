#pragma once

#include <libshogi/shogi-piece.hpp>

namespace shogi {
/**
 * @brief Implementation of Rook piece.
 *
 */
class RookPiece final : public ShogiPiece {
public:
  /**
   * @brief Construct a new Rook Piece object, passing arguments to ShogiPiece.
   *
   * @param x X-Coordinate.
   * @param y Y-Coordinate.
   * @param color Piece sidedness.
   */
  RookPiece(int x, int y, PieceColor color);
  virtual ~RookPiece() = default;

private:
  /**
   * @brief Verifies movement is consistent with actual Rook piece.
   *
   * @param newX Desired X-Coordinate.
   * @param newY Desired Y-Coordinate.
   * @return true If move is valid.
   * @return false If move is invalid.
   */
  bool move(int newX, int newY) noexcept override;

  /**
   * @brief Promote to Dragon.
   *
   */
  void promote() noexcept override;
};
} // namespace shogi