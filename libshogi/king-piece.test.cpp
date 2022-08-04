#include <catch2/catch.hpp>
#include <memory>
#include <sstream>

#include <libshogi/king-piece.hpp>

namespace Catch {
template <> struct StringMaker<std::pair<int, int>> {
  static std::string convert(const std::pair<int, int> &item) {
    std::stringstream stream{};
    stream << "first: " << item.first << ", second: " << item.second;

    return stream.str();
  }
};
} // namespace Catch

// --------------------
// Black piece movement
// --------------------

SCENARIO("black king moving in a normal pattern") {
  GIVEN("A central king piece") {
    std::unique_ptr<shogi::ShogiPiece> centerPiece =
        std::make_unique<shogi::KingPiece>(
            5, 5, shogi::ShogiPiece::PieceColor::Black);

    WHEN("the king is moved forward") {
      centerPiece->movePiece(5, 6);
      THEN("the king moves forward") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 6});
      }
    }

    WHEN("the king is moved backward") {
      centerPiece->movePiece(5, 4);
      THEN("the king moves backward") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 4});
      }
    }

    WHEN("the king is moved up-left") {
      centerPiece->movePiece(6, 6);
      THEN("the king moves up-left") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{6, 6});
      }
    }
  }
}

SCENARIO("black king moving in non-standad pattern") {
  GIVEN("A central king piece") {
    std::unique_ptr<shogi::ShogiPiece> centerPiece =
        std::make_unique<shogi::KingPiece>(
            5, 5, shogi::ShogiPiece::PieceColor::Black);

    WHEN("the king is moved too far forward") {
      centerPiece->movePiece(5, 7);
      THEN("the king is not moved") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 5});
      }
    }
  }

  GIVEN("A corner king piece") {
    std::unique_ptr<shogi::ShogiPiece> cornerPiece =
        std::make_unique<shogi::KingPiece>(
            1, 1, shogi::ShogiPiece::PieceColor::Black);

    WHEN("the king is moved off the board") {
      cornerPiece->movePiece(0, 0);
      THEN("the king remains in place") {
        REQUIRE(cornerPiece->getPosition() == std::pair<int, int>{1, 1});
      }
    }
  }
}

// --------------------
// White piece movement
// --------------------

SCENARIO("white king moving in a normal pattern") {
  GIVEN("A central king piece") {
    std::unique_ptr<shogi::ShogiPiece> centerPiece =
        std::make_unique<shogi::KingPiece>(
            5, 5, shogi::ShogiPiece::PieceColor::White);

    WHEN("the king is moved forward") {
      centerPiece->movePiece(5, 4);
      THEN("the king moves forward") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 4});
      }
    }

    WHEN("the king is moved backward") {
      centerPiece->movePiece(5, 6);
      THEN("the king moves backward") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 6});
      }
    }

    WHEN("the king is moved up-left") {
      centerPiece->movePiece(4, 4);
      THEN("the king moves up-left") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{4, 4});
      }
    }
  }
}

SCENARIO("white king moving in non-standad pattern") {
  GIVEN("A central king piece") {
    std::unique_ptr<shogi::ShogiPiece> centerPiece =
        std::make_unique<shogi::KingPiece>(
            5, 5, shogi::ShogiPiece::PieceColor::White);

    WHEN("the king is moved too far forward") {
      centerPiece->movePiece(5, 3);
      THEN("the king is not moved") {
        REQUIRE(centerPiece->getPosition() == std::pair<int, int>{5, 5});
      }
    }
  }

  GIVEN("A corner king piece") {
    std::unique_ptr<shogi::ShogiPiece> cornerPiece =
        std::make_unique<shogi::KingPiece>(
            9, 9, shogi::ShogiPiece::PieceColor::Black);

    WHEN("the king is moved off the board") {
      cornerPiece->movePiece(10, 10);
      THEN("the king remains in place") {
        REQUIRE(cornerPiece->getPosition() == std::pair<int, int>{9, 9});
      }
    }
  }
}