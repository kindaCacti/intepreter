#pragma once;

#include <string>
#include <vector>

#include "interpreter_sup.hpp"
#include "tokenizer.hpp"
#include "tokens.hpp"

struct Interpreter{
    Interpreter(): tokenizer(), inside_str_literal(false) {}

    void feed(char a){
        if(breaking_chars.find(a) != breaking_chars.end()){
            Token buffer_token = tokenizer.tokenize(buffer);
            Token char_token = tokenizer.tokenizeChar(a);
            buffer.clear();

            if(buffer_token != no_token){
                token_buffer.push_back(buffer_token);
            }
            if(char_token != no_token){
                token_buffer.push_back(buffer_token);
            }

            addInvExpecting(char_token);
            addInvExpecting(buffer_token);
            
            return;
        }

        buffer.push_back(a);
    }

    void addInvExpecting(Token token){
        Token inv_token = tokenizer.getInvToken(token);

        if(inv_token == Token::no_token) return;

        expecting_stack.push_back(inv_token);
    }

private:
    std::string buffer;
    std::vector<Token> token_buffer, expecting_stack;
    Tokenizer tokenizer;
    bool inside_str_literal;
};