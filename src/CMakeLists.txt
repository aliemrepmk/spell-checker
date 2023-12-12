add_executable(spell-checker "main.cpp")

target_sources(
  spell-checker
  PRIVATE
    "levenshtein.hpp"
    "levenshtein.cpp"
    "dictionary.hpp"
    "dictionary.cpp"
)

add_subdirectory("trie")
