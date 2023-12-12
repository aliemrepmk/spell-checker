#pragma once

#include <memory>
#include <string_view>

#include "trie_node.hpp"

class Trie {
 public:
  Trie();

  void insert(std::string_view str);

  bool search(std::string_view str) const;

 private:
  std::unique_ptr<TrieNode> m_root;
};
