# === Project Definition ===

cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(CombatSimulator CXX)

set(CMAKE_CXX_STANDARD 11)

# === Configuration ===

# === Libraries ===

add_library(random src/random/random.cpp)
include_directories("${PROJECT_SOURCE_DIR}/src/random")

add_library(army src/army/Army.cpp)
include_directories("${PROJECT_SOURCE_DIR}/src/army")

add_library(turn src/turn/Turn.cpp)
include_directories("${PROJECT_SOURCE_DIR}/src/turn")

# === Executables ===

add_executable(main src/main.cpp)
target_link_libraries(main army random turn)
