#ifndef ARVORE_H
#define ARVORE_H

#include <string>
#include "no.hpp"


class ArvoreBinaria {

    // Vetores com valores e a expressao a ser ressolvida. "(~1 | 0)"" e "01"
    std::string  expressao, valores;
    // No raiz da ávore
    NoArvore* raiz;

    public:
        // Construtor da Clase Árvore
        ArvoreBinaria(const std::string &expressao, const std::string &valores);
        // Desconstrutor da Ávores. Chama a função remover() para desalocar os nós.
        ~ArvoreBinaria();
        // Construtor da arvore de soluções. Cada Nó filho é uma alteração no possível vetor de valores.
        NoArvore* construir_arvore_solucao(std::string valores, int index);
        // Verifica o valor do Nó raiz para saber se a ávores já foi construída.
        bool esta_construida();
        // Desaloca um Nó.
        void remover(NoArvore *no);
        // Pecorre toda a árvore definindo os valores do ressultado da expressão, de acordo com o ressultado dos filhos.
        void avaliar(NoArvore *no, unsigned int profundidade); // preciso contar o Nivel? Revisar
        // Retorna Nó raiz
        NoArvore* pega_raiz() const;
};



#endif