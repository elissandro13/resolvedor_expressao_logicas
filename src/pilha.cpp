#include <iostream>
#include <string.h>
#include "pilha.hpp"

using namespace std;

// Verifica se Pilha está vazia. Retorna true se sim;
template <class T> Pilha<T>::Pilha() {
    primeiro = nullptr;

};

// Retorna tamanho da pilh
template <class T> bool Pilha<T>::vazio() {
    return (primeiro == nullptr);
};

// Retorna o elemento do top
template <class T> int Pilha<T>::tamanho() {
    if(vazio())
        return 0;

    int cont = 1;
    for(No<T>* tmp = primeiro; tmp->proximo != nullptr; tmp = tmp->proximo){
        cont++;
        
    }

    return cont;
};

// Retorna o elemento do topo
template <class T> T Pilha<T>::pegaTopo() {
    return primeiro->elemento;
};

// Desaloca um elemento da pilha
template <class T> void Pilha<T>::Remover() {
    if(vazio())
        return;

    No<T>* tmp = primeiro;
    primeiro = primeiro->proximo;
    delete tmp;

};

// Retorna o elemento do top e remove ele da pilha
template <class T> T Pilha<T>::desempilha() {
    if(vazio())
        return 0;
    No<T>* tmp = primeiro;
    primeiro = primeiro->proximo;
    T num = tmp->elemento;
    delete tmp;

    return num;
};


// Adiciona um elemento T no topo da pilha
template <class T> void Pilha<T>::empilha(T x) {
    if(tamanho() == 0)
    {
        No<T>* tmp = new No<T>{x,nullptr};
        primeiro = tmp;

    } else {
        No<T>* tmp = new No<T>{x,primeiro};
        primeiro = tmp;
    }
};

 // Desconstrutor da Pilha. Enquando vazio() não for true
template <class T> Pilha<T>::~Pilha() {
    while(!vazio())
        Remover();
}

// Pré declara as templete class. Necessário para o compilador entender os diferentes tipos de pilha que serão utilizados
template class Pilha<char>;
template class Pilha<int>;
template class Pilha<std::string>;