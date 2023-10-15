#ifndef NO_H
#define NO_H

#include <string>


class NoArvore {

    // Vetor dos valores "00010"
    std::string valores;
    // Ressutlado da expressão de cada nó
    int ressultado;

    public:

        // Nó filho esquerdo.
        NoArvore *esq;
        // Nó filho direito.
        NoArvore *dir;
        // Construtor do Nó.
        NoArvore(std::string valores);
        // Função que altera um elemento do vetor valores de acordo com a posição passada.
        void define_valor_index(char novo_valor, int posicao);
        // Get da variável ressultado
        int ressultado_expressao();
        // Set da variável ressultado
        void definine_ressultado_expressao(int expressao_ressultado);
        // Pecorre o vetor valores e retorna 'a' ou 'e'
        char pega_paramentro();
        // Retorna o vetor valores
        std::string pega_vetor_valores();
        // Atualiza a variável do vetor de valores
        void define_vetor_valores(std::string v);
};


#endif 