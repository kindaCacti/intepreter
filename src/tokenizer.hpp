#pragma once

#include <string>
#include <optional>

#include "tokens.hpp"
#include "tokenizer_sup.hpp"

struct Tokenizer{
    Token tokenize(std::string& value){
        return Token::no_token;
    }

    Token tokenizeChar(char value){
        if(value == '(') return Token::open_parenthisis;
        if(value == ')') return Token::close_parenthisis;
        if(value == '"') return Token::str_bound;
        return no_token;
    }

    Token getInvToken(Token token){
        auto it = inv_tokens.find(token);
        if(it == inv_tokens.end()) return Token::no_token;
        return it->second;
    }
};