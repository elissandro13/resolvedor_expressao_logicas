#include "../include/no.hpp"
#include <iostream>


// Construtor do Nó.
NoArvore::NoArvore(std::string valores) {
    this->valores = valores;
    esq = dir = nullptr;

};

// Função que altera um elemento do vetor valores de acordo com a posição passada.
void NoArvore::define_valor_index(char novo_valor, int posicao) {
    this->valores[posicao] = novo_valor;
    //std::cout <<" imrpimindo de dentro " << this->pega_vetor_valores() << std::endl;
};
// Get da variável ressultado
int NoArvore::ressultado_expressao() {
    return this->ressultado;
};
// Set da variável ressultado
void NoArvore::definine_ressultado_expressao(int expressao_ressultado) {
    this->ressultado = expressao_ressultado;

};
// Pecorre o vetor valores e retorna 'a' ou 'e'
char NoArvore::pega_paramentro() {
    for(unsigned i = 0; i < this->valores.size(); i++){
        if (this->valores[i] == 'a' || this->valores[i] == 'e') return this->valores[i];

    }
    return ' ';
};
// Retorna o vetor valores
std::string NoArvore::pega_vetor_valores() {
    return this->valores;

};

// Atualiza a variável do vetor de valores
void NoArvore::define_vetor_valores(std::string v) {
    this->valores = v;
};

