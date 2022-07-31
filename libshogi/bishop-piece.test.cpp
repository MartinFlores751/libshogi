#include <catch2/catch.hpp>
#include <memory>
#include <sstream>

#include <libshogi/bishop-piece.hpp>

namespace Catch {
template <> struct StringMaker<std::pair<int, int>> {
  static std::string convert(const std::pair<int, int> &item) {
    std::stringstream yass{};
    yass << "first: " << item.first << ", second: " << item.second;

    return yass.str();
  }
};
} // namespace Catch

SCENARIO("bishop moving in a normal pattern") {
  GIVEN("A central bishop piece") {
    std::unique_ptr<shogi::ShogiPiece> centerPiece =
        std::make_unique<shogi::BishopPiece>(
            5, 5, shogi::ShogiPiece::PieceColor::Black);

    WHEN("the bishop is moved up-right") {
      centerPiece->movePiece(6, 6);
      THEN("the bishop moves up-right") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{6, 6});
      }
    }

    WHEN("the bishop is moved up-left") {
      centerPiece->movePiece(1, 9);
      THEN("the bishop moves up-left") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{1, 9});
      }
    }
  }
}

SCENARIO("bishop moving in non-standad pattern") {
  GIVEN("A central bishop piece") {
    std::unique_ptr<shogi::ShogiPiece> centerPiece =
        std::make_unique<shogi::BishopPiece>(
            5, 5, shogi::ShogiPiece::PieceColor::Black);

    WHEN("the bishop is moved forward") {
      centerPiece->movePiece(5, 7);
      THEN("the bishop is not moved") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 5});
      }
    }

    WHEN("the bishop is moved backward") {
      centerPiece->movePiece(5, 4);
      THEN("the bishop is not moved") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 5});
      }
    }
  }

  GIVEN("A corner bishop piece") {
    std::unique_ptr<shogi::ShogiPiece> cornerPiece =
        std::make_unique<shogi::BishopPiece>(
            1, 1, shogi::ShogiPiece::PieceColor::Black);

    WHEN("the bishop is moved off the board") {
      cornerPiece->movePiece(0, 0);
      THEN("the bishop remains in place") {
        REQUIRE(cornerPiece->getPosition() == std::pair<int, int>{1, 1});
      }
    }
  }
}