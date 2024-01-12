#pragma once

#include <memory>
#include <string>

#include "trie_node.hpp"

class Trie {
 public:
  Trie();

  void insert(const std::string& str);

  bool search(const std::string& str) const;

 private:
  std::unique_ptr<TrieNode> m_root;
};
