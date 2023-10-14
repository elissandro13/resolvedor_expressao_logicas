#ifndef EXPRESSAO_H
#define EXPRESSAO_H


#include "../include/pilha.hpp"
#include <iostream>


bool isOperador(std::string c);

bool isNumber(std::string c);

int prioridade(char op);

int operacao(int a, int b, std::string op);

void ressolve(Pilha<int> *pilha_valores, Pilha<std::string> *pilha_operadores);

int ressolver_expressao(std::string expressao, std::string valores);



#endif
