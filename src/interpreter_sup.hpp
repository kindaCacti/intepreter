#pragma once

#include <unordered_set>

// breaking chars are characters that are a splitting point between two tokens
std::unordered_set<char> breaking_chars = {' ', '(', ')'};