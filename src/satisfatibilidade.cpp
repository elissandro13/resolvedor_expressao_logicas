#include "../include/arvoreBinaria.hpp"
#include "../include/no.hpp"
#include "../include/satisfatibilidade.hpp"
#include <iostream>



void satisfatibilidade(std::string expressao, std::string valores) {
    ArvoreBinaria arvore{expressao, valores};

    if(arvore.esta_construida()) {
        arvore.avaliar(arvore.pega_raiz(), 0);
        if(arvore.pega_raiz()->ressultado_expressao() == 1) {
            std::cout << "1 " << arvore.pega_raiz()->pega_vetor_valores() << std::endl;
        }  else {
            std::cout << "0" << std::endl;
        }
    }

}