#pragma once

#include <memory>
#include <unordered_map>
#include <utility>

class TrieNode {
 public:
  TrieNode();

  TrieNode* get_child(char ch) const;

  bool is_end() const;
  bool contains_child(char ch) const;

  void set_end();
  void add_child(char ch);

 private:
  std::unordered_map<char, std::unique_ptr<TrieNode>> m_children;

  bool m_is_end;
};
