#include <catch2/catch.hpp>
#include <memory>
#include <sstream>

#include <libshogi/lance-piece.hpp>

namespace Catch {
template <> struct StringMaker<std::pair<int, int>> {
  static std::string convert(const std::pair<int, int> &item) {
    std::stringstream stream{};
    stream << "first: " << item.first << ", second: " << item.second;

    return stream.str();
  }
};
} // namespace Catch

// ----------------
// Black piece test
// ----------------

SCENARIO("black lance moving in a normal pattern") {
  GIVEN("A central lance piece") {
    std::unique_ptr<shogi::ShogiPiece> centerPiece =
        std::make_unique<shogi::LancePiece>(
            5, 5, shogi::ShogiPiece::PieceColor::Black);

    WHEN("the lance is moved up") {
      centerPiece->movePiece(5, 7);
      THEN("the lance moves up") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 7});
      }
    }
  }
}

SCENARIO("black lance moving in non-standad pattern") {
  GIVEN("A central lance piece") {
    std::unique_ptr<shogi::ShogiPiece> centerPiece =
        std::make_unique<shogi::LancePiece>(
            5, 5, shogi::ShogiPiece::PieceColor::Black);

    WHEN("the lance is moved backward") {
      centerPiece->movePiece(5, 4);
      THEN("the lance is not moved") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 5});
      }
    }
  }

  GIVEN("A corner lance piece") {
    std::unique_ptr<shogi::ShogiPiece> cornerPiece =
        std::make_unique<shogi::LancePiece>(
            1, 1, shogi::ShogiPiece::PieceColor::Black);

    WHEN("the lance is moved off the board") {
      cornerPiece->movePiece(1, 10);
      THEN("the lance remains in place") {
        REQUIRE(cornerPiece->getPosition() == std::pair<int, int>{1, 1});
      }
    }
  }
}

// ----------------
// White piece test
// ----------------

SCENARIO("white lance moving in a normal pattern") {
  GIVEN("A central lance piece") {
    std::unique_ptr<shogi::ShogiPiece> centerPiece =
        std::make_unique<shogi::LancePiece>(
            5, 5, shogi::ShogiPiece::PieceColor::White);

    WHEN("the lance is moved up") {
      centerPiece->movePiece(5, 3);
      THEN("the lance moves up") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 3});
      }
    }
  }
}

SCENARIO("white lance moving in non-standad pattern") {
  GIVEN("A central lance piece") {
    std::unique_ptr<shogi::ShogiPiece> centerPiece =
        std::make_unique<shogi::LancePiece>(
            5, 5, shogi::ShogiPiece::PieceColor::White);

    WHEN("the lance is moved backward") {
      centerPiece->movePiece(5, 6);
      THEN("the lance is not moved") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 5});
      }
    }
  }

  GIVEN("A corner lance piece") {
    std::unique_ptr<shogi::ShogiPiece> cornerPiece =
        std::make_unique<shogi::LancePiece>(
            9, 9, shogi::ShogiPiece::PieceColor::White);

    WHEN("the lance is moved off the board") {
      cornerPiece->movePiece(9, 0);
      THEN("the lance remains in place") {
        REQUIRE(cornerPiece->getPosition() == std::pair<int, int>{9, 9});
      }
    }
  }
}