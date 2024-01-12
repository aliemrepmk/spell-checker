#pragma once

#include <algorithm>
#include <string>
#include <utility>
#include <vector>

#define LEVENSHTEIN_MAX_DISTANCE 4
#define ALPHABET_SIZE 26

namespace levenshtein {

int calculate_distance(const std::string& source, const std::string& target);

namespace v1 {
int calculate_distance(const std::string& source, const std::string& target);
}

class Comparator {
 public:
  bool operator()(const std::string& str1, const std::string& str2) const;

  void set_target(std::string target);

 private:
  std::string m_target;
};
}  // namespace levenshtein
