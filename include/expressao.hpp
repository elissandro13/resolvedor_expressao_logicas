#ifndef EXPRESSAO_H
#define EXPRESSAO_H


#include "../include/pilha.hpp"
#include <iostream>


int prioridade(char op);

int operacao(int a, int b, char op);

void ressolve(Pilha<int> *pilha_valores, Pilha<char> *pilha_operadores);

int ressolver_expressao(std::string expressao, std::string valores);



#endif
