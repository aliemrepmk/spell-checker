#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <string_view>

#include "trie/trie.hpp"

class Dictionary {
 public:
  void load_from_file(std::string_view filename);

 private:
  Trie m_trie;
};