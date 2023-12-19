#pragma once

#include <string>
#include <string_view>
#include <utility>

namespace levenshtein {
int calculate_distance(std::string_view source, std::string_view target);

class Comparator {
 public:
  bool operator()(std::string_view str1, std::string_view str2) const;

  void set_target(std::string target);

 private:
  std::string m_target;
};
}  // namespace levenshtein
