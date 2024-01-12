#pragma once

#include <string>
#include <string_view>
#include <utility>

#define LEVENSHTEIN_MAX_DISTANCE 4
#define ALPHABET_SIZE 26

namespace levenshtein {

int calculate_distance(std::string_view source, std::string_view target);

namespace v1 {
int calculate_distance(std::string_view source, std::string_view target);
}

class Comparator {
 public:
  bool operator()(std::string_view str1, std::string_view str2) const;

  void set_target(std::string target);

 private:
  std::string m_target;
};
}  // namespace levenshtein