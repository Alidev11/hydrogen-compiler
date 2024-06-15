#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <optional>

// enumeration of tokens
enum class TokenType
{
    exit,
    int_lit,
    semi
};

// type of the token: tokentype as an enum and its value is optional
struct Token
{
    TokenType type;
    optional<string> value{};
};

using namespace std;
class Tokenizer
{
public:
    inline Tokenizer(const string &src) : m_src(move(src))
    {
    }

    inline vector<Token> tokenize()
    {
        string buf;
        while(peak().has_value()){
            if(isalpha(peak().value())){
                buf.push_back(consume());
                while(peak().has_value() && isalnum(peak().value())){
                    buf.push_back(consume());
                }
            }
        }


        for (int i = 0; i < str.length(); i++)
        {
            char c = str.at(i);
            if (isalpha(c))
            {
                buf.push_back(c);
                i++;
                while (isalnum(str.at(i)))
                {
                    buf.push_back(str.at(i));
                    i++;
                }
                i--;

                if (buf == "exit")
                {
                    tokens.push_back({.type = TokenType::exit});
                    buf.clear();
                    continue;
                }
                else
                {
                    cerr << "You messed up!" << endl;
                    exit(EXIT_FAILURE);
                }
            }
            else if (isdigit(c))
            {
                buf.push_back(c);
                i++;
                while (isdigit(str.at(i)))
                {
                    buf.push_back(str.at(i));
                    i++;
                }
                i--;
                tokens.push_back({.type = TokenType::int_lit, .value = buf});
                buf.clear();
            }
            else if (c == ';')
            {
                tokens.push_back({.type = TokenType::semi});
            }
            else if (isspace(c))
            {
                continue;
            }
            else
            {
                cerr << "You messed up!" << endl;
                exit(EXIT_FAILURE);
            }
        }
        return tokens;
    }

private:
    [[nodiscard]] optional<char> peak(int ahead = 1) const{
        if(m_index + ahead >= m_src.length()){
            return {};
        }else{
            return m_src.at(m_index);
        }
    }

    char consume() {
        retrn m_src.at(m_indec++);
    }

    const string m_src;
    int m_index;
}