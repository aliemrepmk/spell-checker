#include <iostream>

#include "dictionary.hpp"

int main() {
  Dictionary dictionary;

  dictionary.load_from_file("dictionary.txt");

  std::cout << dictionary.get_dictionary().search("classroom") << std::endl;

  return 0;
}
