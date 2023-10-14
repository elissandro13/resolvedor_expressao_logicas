#ifndef PILHA_H
#define PILHA_H

template <class T>

struct No {
  T elemento;
  No<T>* proximo;
};

template <class T> class Pilha 

{
    public:
        Pilha();
        bool vazio();
        int tamanho();
        T pegaTopo();
        T desempilha();
        void empilha(T x);
        void Remover();
        ~Pilha();

    private:
        No<T>* primeiro;


};


#endif