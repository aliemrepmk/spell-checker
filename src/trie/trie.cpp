#include "trie.hpp"

Trie::Trie() : m_root{std::make_unique<TrieNode>()} {}

void Trie::insert(std::string_view str) {
  TrieNode* current = m_root.get();

  for (char ch : str) {
    current->add_child(ch);
    current = current->get_child(ch);
  }

  current->set_end();
}

bool Trie::search(std::string_view str) {
  TrieNode* current = m_root.get();

  for (char ch : str) {
    if (!current->contains_child(ch)) {
      return false;
    }

    current = current->get_child(ch);
  }

  return current->is_end();
}
