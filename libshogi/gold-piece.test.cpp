#include <catch2/catch.hpp>
#include <memory>
#include <sstream>

#include <libshogi/gold-piece.hpp>

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

SCENARIO("black gold general moving in a normal pattern") {
  GIVEN("A central gold general piece") {
    std::unique_ptr<shogi::ShogiPiece> centerPiece =
        std::make_unique<shogi::GoldPiece>(
            5, 5, shogi::ShogiPiece::PieceColor::Black);

    WHEN("the gold general is moved forward") {
      centerPiece->movePiece(5, 6);
      THEN("the gold general moves forward") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 6});
      }
    }

    WHEN("the gold general is moved backward") {
      centerPiece->movePiece(5, 4);
      THEN("the gold general moves backward") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 4});
      }
    }

    WHEN("the gold general is moved up-right") {
      centerPiece->movePiece(6, 6);
      THEN("the gold general moves up-right") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{6, 6});
      }
    }
  }
}

SCENARIO("black gold general moving in non-standad pattern") {
  GIVEN("A central gold general piece") {
    std::unique_ptr<shogi::ShogiPiece> centerPiece =
        std::make_unique<shogi::GoldPiece>(
            5, 5, shogi::ShogiPiece::PieceColor::Black);

    WHEN("the gold general is moved too far forward") {
      centerPiece->movePiece(5, 7);
      THEN("the gold general is not moved") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 5});
      }
    }

    WHEN("the gold general is moved back-left") {
      centerPiece->movePiece(4, 4);
      THEN("the gold general is not moved") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 5});
      }
    }
  }

  GIVEN("A corner gold general piece") {
    std::unique_ptr<shogi::ShogiPiece> cornerPiece =
        std::make_unique<shogi::GoldPiece>(
            1, 1, shogi::ShogiPiece::PieceColor::Black);

    WHEN("the gold general is moved off the board") {
      cornerPiece->movePiece(0, 1);
      THEN("the gold general remains in place") {
        REQUIRE(cornerPiece->getPosition() == std::pair<int, int>{1, 1});
      }
    }
  }
}

// -----------------
// White piece tests
// -----------------

SCENARIO("white gold general moving in a normal pattern") {
  GIVEN("A central gold general piece") {
    std::unique_ptr<shogi::ShogiPiece> centerPiece =
        std::make_unique<shogi::GoldPiece>(
            5, 5, shogi::ShogiPiece::PieceColor::White);

    WHEN("the gold general is moved forward") {
      centerPiece->movePiece(5, 4);
      THEN("the gold general moves forward") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 4});
      }
    }

    WHEN("the gold general is moved backward") {
      centerPiece->movePiece(5, 6);
      THEN("the gold general moves backward") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 6});
      }
    }

    WHEN("the gold general is moved up-right") {
      centerPiece->movePiece(4, 4);
      THEN("the gold general moves up-right") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{4, 4});
      }
    }
  }
}

SCENARIO("white gold general moving in non-standad pattern") {
  GIVEN("A central gold general piece") {
    std::unique_ptr<shogi::ShogiPiece> centerPiece =
        std::make_unique<shogi::GoldPiece>(
            5, 5, shogi::ShogiPiece::PieceColor::White);

    WHEN("the gold general is moved too far forward") {
      centerPiece->movePiece(5, 3);
      THEN("the gold general is not moved") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 5});
      }
    }

    WHEN("the gold general is moved back-left") {
      centerPiece->movePiece(6, 6);
      THEN("the gold general is not moved") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 5});
      }
    }
  }

  GIVEN("A corner gold general piece") {
    std::unique_ptr<shogi::ShogiPiece> cornerPiece =
        std::make_unique<shogi::GoldPiece>(
            9, 9, shogi::ShogiPiece::PieceColor::White);

    WHEN("the gold general is moved off the board") {
      cornerPiece->movePiece(9, 10);
      THEN("the gold general remains in place") {
        REQUIRE(cornerPiece->getPosition() == std::pair<int, int>{9, 9});
      }
    }
  }
}
