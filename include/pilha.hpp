#ifndef PILHA_H
#define PILHA_H

template <class T>

// Cada elemento da pilha. Tem um valor T e aponta para o próximo elemento T.
struct No {
  T elemento;
  No<T>* proximo;
};

template <class T> class Pilha 

{
    public:
        // Contrutor da TAD Pilha
        Pilha();
        // Verifica se Pilha está vazia. Retorna true se sim;
        bool vazio();
        // Retorna tamanho da pilha
        int tamanho();
        // Retorna o elemento do topo
        T pegaTopo();
        // Retorna o elemento do topo e remove ele da pilha
        T desempilha();
        // Adiciona um elemento T no topo da pilha
        void empilha(T x);
        // Desaloca um elemento da pilha
        void Remover();
         // Desconstrutor da Pilha. Enquando vazio() não for true
        ~Pilha();

    private:
        // Raiz/Base da pilha
        No<T>* primeiro;


};


#endif