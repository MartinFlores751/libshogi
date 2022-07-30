#pragma once

#include <libshogi/shogi-piece.hpp>

namespace shogi {
/**
 * @brief Implementation of King Piece from shogi.
 *
 */
class KingPiece final : public ShogiPiece {
public:
  /**
   * @brief Construct a new King Piece object, passing all items to ShogiPiece
   * constructor.
   *
   * @param x X-Coordinate of piece.
   * @param y Y-Coordinate of piece.
   * @param color Piece sidedness.
   */
  KingPiece(int x, int y, PieceColor color);
  virtual ~KingPiece() = default;

private:
  /**
   * @brief Move within 1 block in any direction.
   *
   * @param newX Desired X-Coordinate.
   * @param newY Desired Y-Coordinate.
   * @return true If the move is valid.
   * @return false If the move is invalid.
   */
  bool move(int newX, int newY) noexcept override;

  /**
   * @brief A king does not promote.
   *
   */
  void promote() noexcept override;
};
} // namespace shogi