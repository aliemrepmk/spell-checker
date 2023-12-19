#include <iostream>
#include <string>

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
    }

  } while (word != "exit");

  return 0;
}
