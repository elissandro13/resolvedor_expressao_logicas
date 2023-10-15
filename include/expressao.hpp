#ifndef EXPRESSAO_H
#define EXPRESSAO_H


#include "../include/pilha.hpp"
#include <iostream>

// Verificar se a string é um dos operadores (~, | and &)
bool isOperador(std::string c);

// Verificar se a string é um número
bool isNumber(std::string c);

// Controla ordem de prioridade das diferente operações (~, | and &)
int prioridade(char op);

// Realiza as operações
int operacao(int a, int b, std::string op);

// Fluxo para diferenciar as operações and e or da negado. Chama a função operacao com os parâmetros corretos.
void ressolve(Pilha<int> *pilha_valores, Pilha<std::string> *pilha_operadores);

// Fluxo para diferenciar as operações and e or da negado. Chama a função operacao com os parâmetros corretos.
int ressolver_expressao(std::string expressao, std::string valores);



#endif
