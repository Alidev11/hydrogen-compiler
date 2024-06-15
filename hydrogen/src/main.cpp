#include "./tokenization.hpp"

using namespace std;


//our lexer function. It returns a vector that contains tokens 
//with their type(return, int, semi colomn) and value 
vector<Token> tokenize(const string& str){
    
}


//basic function that translates tokens to assembly
string tokens_to_asm(vector<Token>& tokens){
    stringstream output;
    output << "global _start \n_start:\n";

    for(int i = 0; i < tokens.size(); i++){
        const Token& token = tokens.at(i);
        if(token.type == TokenType::exit){
             if(i+1 < tokens.size() && tokens.at(i+1).type == TokenType::int_lit){
                if(i+2 < tokens.size() && tokens.at(i+2).type == TokenType::semi){
                    output << "     mov rax, 60\n";
                    output << "     mov rdi, " << tokens.at(i+1).value.value() << "\n";
                    output << "     syscall";
                }
             }
        }
    }
    return output.str();
}

//main takes two arguments(main.exe and test.hy) 
int main(int argc, char* argv[]){
    // if we put only one argument it will output an error
    if(argc != 2){
        cerr << "Incorrect usage. Correct usage is ..." << endl;
        cerr << "hydro <input.hy>" << endl;
        return EXIT_FAILURE;
    }
    // else it will read test.hy as a string stream and then convert it to string

    string contents;
    {
        stringstream contents_stream;
        fstream input(argv[1], ios::in);
        contents_stream << input.rdbuf();
        contents = contents_stream.str();
        
    }

    // create an array of tokens
    vector<Token> tokens = tokenize(contents);

    {
        //output an assembly file
        fstream file("./out.asm", ios::out);
        file << tokens_to_asm(tokens);
    }


    system("nasm out.asm -felf64");
    system("ld -o out out.o");
    return EXIT_FAILURE;
}
