#include <iostream>
#include <string>
#include <vector>

#include "dictionary.hpp"

int main() {
  Dictionary dictionary;

  dictionary.load_from_file("dictionary.txt");

  std::string word;
  do {
    std::cout << "Please enter a word: ";
    std::cin >> word;

    if (!dictionary.get_dictionary().search(word)) {
      std::cout << "Word is mispelled" << std::endl;

      std::vector<std::string> suggestions = dictionary.get_suggestions(word);
      if (suggestions.empty()) {
        std::cout << "No suggestion found for word: " << word << std::endl;
        continue;
      }

      for (const auto& suggestion : suggestions) {
        std::cout << "\tSuggestion: " << suggestion << std::endl;
      }
    }
  } while (word != "exit");

  return 0;
}
