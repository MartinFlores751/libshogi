#include <catch2/catch.hpp>
#include <memory>
#include <sstream>

#include <libshogi/pawn-piece.hpp>

namespace Catch {
template <> struct StringMaker<std::pair<int, int>> {
  static std::string convert(const std::pair<int, int> &item) {
    std::stringstream stream{};
    stream << "first: " << item.first << ", second: " << item.second;

    return stream.str();
  }
};
} // namespace Catch

SCENARIO("pawn moving in a normal pattern") {
  GIVEN("A central pawn piece") {
    std::unique_ptr<shogi::ShogiPiece> centerPiece =
        std::make_unique<shogi::PawnPiece>(
            5, 5, shogi::ShogiPiece::PieceColor::Black);

    WHEN("the pawn is moved forward") {
      centerPiece->movePiece(5, 6);
      THEN("the pawn moves forward") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 6});
      }
    }
  }
}

SCENARIO("pawn moving in non-standad pattern") {
  GIVEN("A central pawn piece") {
    std::unique_ptr<shogi::ShogiPiece> centerPiece =
        std::make_unique<shogi::PawnPiece>(
            5, 5, shogi::ShogiPiece::PieceColor::Black);

    WHEN("the pawn is moved far forward") {
      centerPiece->movePiece(5, 7);
      THEN("the pawn is not moved") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 5});
      }

      WHEN("the pawn is moved left") {
        centerPiece->movePiece(4, 5);
        THEN("the pawn is not moved") {
          REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 5});
        }
      }
    }

    WHEN("the pawn is moved backward") {
      centerPiece->movePiece(5, 4);
      THEN("the pawn is not moved") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 5});
      }
    }
  }
}