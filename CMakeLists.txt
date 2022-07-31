cmake_minimum_required(VERSION 3.20)
project(ShogiLib
        VERSION 0.3.0
        LANGUAGES CXX)

enable_testing()

# Require C++20 with disabled extensions
set_property(GLOBAL
	     PROPERTY CMAKE_CXX_STANDARD 20)
set_property(GLOBAL
	     PROPERTY CMAKE_CXX_STANDARD_REQUIRED ON)
set_property(GLOBAL
	     PROPERTY CMAKE_CXX_EXTENSIONS OFF)

# Enable additional compilation flags
set_property(GLOBAL
	     APPEND_STRING
	     PROPERTY CMAKE_CXX_FLAGS "-Wall -Werror")

add_subdirectory(libshogi)
