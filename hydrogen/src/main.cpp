#include <iostream>
#include <sstream> // Include for std::stringstream
#include <fstream>
#include <vector>
#include <optional>

using namespace std;

enum class TokenType{
    _return,
    int_lit,
    semi
};

struct Token{
    TokenType type;
    optional<string> value;
};

vector<Token> tokenize(const string& str){
    for(char c : str){
        cout << c << endl;
    }
}


int main(int argc, char* argv[]){
    if(argc != 2){
        cerr << "Incorrect usage. Correct usage is ..." << endl;
        cerr << "hydro <input.hy>" << endl;
        return EXIT_FAILURE;
    }

    string contents;
    {
        stringstream contents_stream;
        fstream input(argv[1], ios::in);
        contents_stream << input.rdbuf();
        contents = contents_stream.str();
        
    }


    vector<Token> t = tokenize(contents);
    return EXIT_FAILURE;
}
