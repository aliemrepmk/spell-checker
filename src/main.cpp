#include "dictionary.hpp"

int main() {
  Dictionary dictionary;

  dictionary.load_from_file("dictionary.txt");

  return 0;
}
