#include <catch2/catch.hpp>
#include <memory>
#include <sstream>

#include <libshogi/knight-piece.hpp>

namespace Catch {
template <> struct StringMaker<std::pair<int, int>> {
  static std::string convert(const std::pair<int, int> &item) {
    std::stringstream stream{};
    stream << "first: " << item.first << ", second: " << item.second;

    return stream.str();
  }
};
} // namespace Catch

SCENARIO("knight moving in a normal pattern") {
  GIVEN("A central knight piece") {
    std::unique_ptr<shogi::ShogiPiece> centerPiece =
        std::make_unique<shogi::KnightPiece>(
            5, 5, shogi::ShogiPiece::PieceColor::Black);

    WHEN("the knight is moved in a 'right L'") {
      centerPiece->movePiece(6, 7);
      THEN("the knight moves up-right") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{6, 7});
      }
    }

    WHEN("the knight is moved in a 'left L'") {
      centerPiece->movePiece(4, 7);
      THEN("the knight moves up-left") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{4, 7});
      }
    }
  }
}

SCENARIO("knight moving in non-standad pattern") {
  GIVEN("A central knight piece") {
    std::unique_ptr<shogi::ShogiPiece> centerPiece =
        std::make_unique<shogi::KnightPiece>(
            5, 5, shogi::ShogiPiece::PieceColor::Black);

    WHEN("the knight is moved forward") {
      centerPiece->movePiece(5, 7);
      THEN("the knight is not moved") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 5});
      }
    }

    WHEN("the knight is moved backward") {
      centerPiece->movePiece(5, 4);
      THEN("the knight is not moved") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 5});
      }
    }
  }

  GIVEN("A corner knight piece") {
    std::unique_ptr<shogi::ShogiPiece> cornerPiece =
        std::make_unique<shogi::KnightPiece>(
            1, 1, shogi::ShogiPiece::PieceColor::Black);

    WHEN("the knight is moved off the board") {
      cornerPiece->movePiece(0, 3);
      THEN("the knight remains in place") {
        REQUIRE(cornerPiece->getPosition() == std::pair<int, int>{1, 1});
      }
    }
  }
}