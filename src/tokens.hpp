#pragma once

#include <unordered_map>
#include <string>

enum Token{
    open_parenthisis,
    close_parenthisis,
    exit,
    int_literal,
    no_token,
    str_bound,
};

std::unordered_map<std::string, Token> token_matching = {
    {"exit", Token::exit},
};
