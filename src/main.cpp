#include <string.h>
#include <iostream>
#include "../include/expressao.hpp" 
#include <sstream>


using std::cout;
using std::cin;


int main(int argc,char ** argv){

    //cout << "asdas" << std::endl;

    if (argc != 4){     
        throw std::runtime_error("O programa precisa de 3 argumentos");
        return 0;
    } 

    std::string p; // formula;
    std::string s; // valores das variaveis;
    p =  argv[2];
    s =  argv[3];
    std::string op = argv[1];

    //std::string op = "-a";
    //p = "0 | 1" ; 
    //s = "01";
        /*** 
   
    cout << argv[1][1] << std::endl; ***/

    
   

    if (op.compare("-a") == 0) {
        cout << ressolver_expressao(p, s) << std::endl;
    } else if(op.compare("-s") == 0) {
        //cout << satisfatibilidade() << std::endl;
    } else {
        throw std::runtime_error("Argument passado inválido. Use -a para avaliação das expressões ou -s para testes a satisfabilidade.");
    }

    return 0;
}