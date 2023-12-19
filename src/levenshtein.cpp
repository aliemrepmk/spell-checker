#include "levenshtein.hpp"

#include <algorithm>
#include <vector>

int levenshtein::calculate_distance(std::string_view source,
                                    std::string_view target) {
  size_t source_length = source.length();
  size_t target_length = target.length();

  std::vector<int> previous_row(target_length + 1, 0);
  std::vector<int> current_row(target_length + 1, 0);

  for (int j = 0; j <= target_length; j++) {
    previous_row.at(j) = j;
  }

  for (int i = 1; i <= source_length; i++) {
    current_row.at(0) = i;

    for (int j = 1; j <= target_length; j++) {
      if (source.at(i - 1) == target.at(j - 1)) {
        current_row.at(j) = previous_row.at(j - 1);
        continue;
      }

      int cost = std::min(previous_row.at(j), previous_row.at(j - 1));
      current_row.at(j) = 1 + std::min(current_row.at(j - 1), cost);
    }

    previous_row = current_row;
  }

  return current_row[target_length];
}

bool levenshtein::Comparator::operator()(std::string_view str1,
                                         std::string_view str2) const {
  return calculate_distance(str1, m_target) <
         calculate_distance(str2, m_target);
}

void levenshtein::Comparator::set_target(std::string target) {
  m_target = std::move(target);
}
