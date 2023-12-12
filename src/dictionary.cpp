#include "dictionary.hpp"

void Dictionary::load_from_file(std::string_view filename) {
  std::ifstream input_file(filename.data(), std::ios::binary);

  if (!input_file.is_open()) {
    std::cerr << "Could not open dictionary file: " << filename << std::endl;
    return;
  }

  std::cout << "Reading dictionary file..." << std::endl;

  std::string word;
  while (std::getline(input_file, word)) {
    m_trie.insert(word);
  }

  if (!input_file.eof() && input_file.fail()) {
    std::cerr << "Error while reading dictionary file: " << filename
              << std::endl;
    return;
  }

  std::cout << "Completed." << std::endl;

  input_file.close();
}