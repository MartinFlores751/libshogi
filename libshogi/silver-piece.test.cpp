#include <catch2/catch.hpp>
#include <memory>
#include <sstream>

#include <libshogi/silver-piece.hpp>

namespace Catch {
template <> struct StringMaker<std::pair<int, int>> {
  static std::string convert(const std::pair<int, int> &item) {
    std::stringstream stream{};
    stream << "first: " << item.first << ", second: " << item.second;

    return stream.str();
  }
};
} // namespace Catch

// -----------------
// Black piece tests
// -----------------

SCENARIO("black silver general moving in a normal pattern") {
  GIVEN("A central silver general piece") {
    std::unique_ptr<shogi::ShogiPiece> centerPiece =
        std::make_unique<shogi::SilverPiece>(
            5, 5, shogi::ShogiPiece::PieceColor::Black);

    WHEN("the silver general is moved forward") {
      centerPiece->movePiece(5, 6);
      THEN("the silver general moves forward") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 6});
      }
    }

    WHEN("the silver general is moved back-left") {
      centerPiece->movePiece(4, 4);
      THEN("the silver general is not moved") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{4, 4});
      }
    }

    WHEN("the silver general is moved up-right") {
      centerPiece->movePiece(6, 6);
      THEN("the silver general moves up-right") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{6, 6});
      }
    }
  }
}

SCENARIO("black silver general moving in non-standad pattern") {
  GIVEN("A central silver general piece") {
    std::unique_ptr<shogi::ShogiPiece> centerPiece =
        std::make_unique<shogi::SilverPiece>(
            5, 5, shogi::ShogiPiece::PieceColor::Black);

    WHEN("the silver general is moved too far forward") {
      centerPiece->movePiece(5, 7);
      THEN("the silver general is not moved") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 5});
      }
    }

    WHEN("the silver general is moved backward") {
      centerPiece->movePiece(5, 4);
      THEN("the silver general is not moved") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 5});
      }
    }
  }

  GIVEN("A corner silver general piece") {
    std::unique_ptr<shogi::ShogiPiece> cornerPiece =
        std::make_unique<shogi::SilverPiece>(
            1, 1, shogi::ShogiPiece::PieceColor::Black);

    WHEN("the silver general is moved off the board") {
      cornerPiece->movePiece(0, 0);
      THEN("the silver general remains in place") {
        REQUIRE(cornerPiece->getPosition() == std::pair<int, int>{1, 1});
      }
    }
  }
}

// -----------------
// White piece tests
// -----------------

SCENARIO("white silver general moving in a normal pattern") {
  GIVEN("A central silver general piece") {
    std::unique_ptr<shogi::ShogiPiece> centerPiece =
        std::make_unique<shogi::SilverPiece>(
            5, 5, shogi::ShogiPiece::PieceColor::White);

    WHEN("the silver general is moved forward") {
      centerPiece->movePiece(5, 4);
      THEN("the silver general moves forward") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 4});
      }
    }

    WHEN("the silver general is moved back-left") {
      centerPiece->movePiece(6, 6);
      THEN("the silver general is not moved") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{6, 6});
      }
    }

    WHEN("the silver general is moved up-right") {
      centerPiece->movePiece(4, 4);
      THEN("the silver general moves up-right") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{4, 4});
      }
    }
  }
}

SCENARIO("white silver general moving in non-standad pattern") {
  GIVEN("A central silver general piece") {
    std::unique_ptr<shogi::ShogiPiece> centerPiece =
        std::make_unique<shogi::SilverPiece>(
            5, 5, shogi::ShogiPiece::PieceColor::White);

    WHEN("the silver general is moved too far forward") {
      centerPiece->movePiece(5, 3);
      THEN("the silver general is not moved") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 5});
      }
    }

    WHEN("the silver general is moved backward") {
      centerPiece->movePiece(5, 6);
      THEN("the silver general is not moved") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 5});
      }
    }
  }

  GIVEN("A corner silver general piece") {
    std::unique_ptr<shogi::ShogiPiece> cornerPiece =
        std::make_unique<shogi::SilverPiece>(
            9, 9, shogi::ShogiPiece::PieceColor::Black);

    WHEN("the silver general is moved off the board") {
      cornerPiece->movePiece(10, 10);
      THEN("the silver general remains in place") {
        REQUIRE(cornerPiece->getPosition() == std::pair<int, int>{9, 9});
      }
    }
  }
}
