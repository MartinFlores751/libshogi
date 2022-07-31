#include <catch2/catch.hpp>
#include <memory>
#include <sstream>

#include <libshogi/rook-piece.hpp>

namespace Catch {
template <> struct StringMaker<std::pair<int, int>> {
  static std::string convert(const std::pair<int, int> &item) {
    std::stringstream stream{};
    stream << "first: " << item.first << ", second: " << item.second;

    return stream.str();
  }
};
} // namespace Catch

SCENARIO("rook moving in a normal pattern") {
  GIVEN("A central rook piece") {
    std::unique_ptr<shogi::ShogiPiece> centerPiece =
        std::make_unique<shogi::RookPiece>(
            5, 5, shogi::ShogiPiece::PieceColor::Black);

    WHEN("the rook is moved forward") {
      centerPiece->movePiece(5, 8);
      THEN("the rook moves forward") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 8});
      }
    }

    WHEN("the rook is moved backward") {
      centerPiece->movePiece(5, 1);
      THEN("the rook moves backward") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 1});
      }
    }
  }
}

SCENARIO("rook moving in non-standad pattern") {
  GIVEN("A central rook piece") {
    std::unique_ptr<shogi::ShogiPiece> centerPiece =
        std::make_unique<shogi::RookPiece>(
            5, 5, shogi::ShogiPiece::PieceColor::Black);

    WHEN("the rook is moved up-left") {
      centerPiece->movePiece(6, 6);
      THEN("the rook remains in place") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 5});
      }
    }
  }

  GIVEN("A corner rook piece") {
    std::unique_ptr<shogi::ShogiPiece> cornerPiece =
        std::make_unique<shogi::RookPiece>(
            1, 1, shogi::ShogiPiece::PieceColor::Black);

    WHEN("the rook is moved off the board") {
      cornerPiece->movePiece(0, 1);
      THEN("the rook remains in place") {
        REQUIRE(cornerPiece->getPosition() == std::pair<int, int>{1, 1});
      }
    }
  }
}