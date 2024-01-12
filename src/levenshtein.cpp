#include "levenshtein.hpp"

int levenshtein::v1::calculate_distance(const std::string& source,
                                        const std::string& target) {
  int source_length = static_cast<int>(source.length());
  int target_length = static_cast<int>(target.length());

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

int levenshtein::calculate_distance(const std::string& source,
                                    const std::string& target) {
  int source_length = static_cast<int>(source.length());
  int target_length = static_cast<int>(target.length());

  int d[source_length + 1][target_length + 1];

  for (int i = 0; i < source_length; ++i) {
    d[i][0] = i;
  }

  for (int i = 0; i < target_length; ++i) {
    d[0][i] = i;
  }

  for (int i = 1; i <= source_length; ++i) {
    for (int j = 1; j <= target_length; ++j) {
      int cost = 0;

      if (source[i - 1] != target[j - 1]) {
        cost = 1;
      }

      int first = std::min(d[i - 1][j] + 1, d[i][j - 1] + 1);
      d[i][j] = std::min(d[i - 1][j - 1] + cost, first);

      if (i > 1 && j > 1 && source[i - 1] == target[j - 2] &&
          source[i - 2] == target[j - 1]) {
        d[i][j] = std::min(d[i][j], d[i - 2][j - 2] + cost);
      }
    }
  }

  return d[source.length()][target.length()];
}

bool levenshtein::Comparator::operator()(const std::string& str1,
                                         const std::string& str2) const {
  return calculate_distance(str1, m_target) <
         calculate_distance(str2, m_target);
}

void levenshtein::Comparator::set_target(std::string target) {
  m_target = std::move(target);
}
