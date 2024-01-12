cmake_minimum_required(VERSION 3.20)

project(spell-checker LANGUAGES CXX)

set(BINARY_DIR "${CMAKE_SOURCE_DIR}/bin/")

add_subdirectory("src")

set_target_properties(
  spell-checker
  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${BINARY_DIR}"
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

configure_file(
  "${CMAKE_SOURCE_DIR}/assets/words_alpha.txt"
  "${BINARY_DIR}/dictionary.txt"
  COPYONLY
)
