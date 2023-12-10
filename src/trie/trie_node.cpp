#include "trie_node.hpp"

TrieNode::TrieNode() : m_is_end{false} {}

TrieNode* TrieNode::get_child(char ch) const {
  if (!contains_child(ch)) {
    return nullptr;
  }

  return m_children.at(ch).get();
}

bool TrieNode::is_end() const { return m_is_end; }

bool TrieNode::contains_child(char ch) const {
  return m_children.find(ch) != m_children.end();
}

void TrieNode::set_end() { m_is_end = true; }

void TrieNode::add_child(char ch) {
  if (!contains_child(ch)) {
    m_children.insert(std::make_pair(ch, std::make_unique<TrieNode>()));
  }
}
