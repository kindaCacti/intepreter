#pragma once

#include <unordered_map>

#include "tokens.hpp"

std::unordered_map<Token, Token> inv_tokens = {
    {Token::open_parenthisis, Token::close_parenthisis},
};