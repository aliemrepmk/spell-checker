#pragma once

#include <string_view>

namespace levenshtein {
int calculate_distance(std::string_view source, std::string_view target);
}
