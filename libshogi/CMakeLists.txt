# --------------
# libshogi build
# --------------
add_library(shogi shogi-piece.cpp king-piece.cpp rook-piece.cpp bishop-piece.cpp gold-piece.cpp silver-piece.cpp knight-piece.cpp)
target_include_directories(shogi PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)

# ---------
# Test code
# ---------
find_package(Catch2
	     REQUIRED)

add_executable(king-piece-unit test-main.cpp king-piece.test.cpp)
target_include_directories(king-piece-unit PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(king-piece-unit PRIVATE Catch2::Catch2 shogi)
add_test(NAME kingPieceUnit COMMAND king-piece-unit)

add_executable(rook-piece-unit test-main.cpp rook-piece.test.cpp)
target_include_directories(rook-piece-unit PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(rook-piece-unit PRIVATE Catch2::Catch2 shogi)
add_test(NAME rookPieceUnit COMMAND rook-piece-unit)

add_executable(bishop-piece-unit test-main.cpp bishop-piece.test.cpp)
target_include_directories(bishop-piece-unit PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(bishop-piece-unit PRIVATE Catch2::Catch2 shogi)
add_test(NAME bishopPieceUnit COMMAND bishop-piece-unit)

add_executable(gold-piece-unit test-main.cpp gold-piece.test.cpp)
target_include_directories(gold-piece-unit PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(gold-piece-unit PRIVATE Catch2::Catch2 shogi)
add_test(NAME goldPieceUnit COMMAND gold-piece-unit)

add_executable(silver-piece-unit test-main.cpp silver-piece.test.cpp)
target_include_directories(silver-piece-unit PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(silver-piece-unit PRIVATE Catch2::Catch2 shogi)
add_test(NAME silverPieceUnit COMMAND silver-piece-unit)

add_executable(knight-piece-unit test-main.cpp knight-piece.test.cpp)
target_include_directories(knight-piece-unit PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(knight-piece-unit PRIVATE Catch2::Catch2 shogi)
add_test(NAME knightPieceUnit COMMAND knight-piece-unit)
