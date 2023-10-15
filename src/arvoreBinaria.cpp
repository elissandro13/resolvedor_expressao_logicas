#include <iostream>
#include "../include/arvoreBinaria.hpp"
#include "../include/expressao.hpp"
#include "../include/no.hpp"



// Construtor da Clase Árvore
ArvoreBinaria::ArvoreBinaria(const std::string &expressao, const std::string &valores) {
    this->expressao = expressao;
    this->valores = valores;
    this->raiz = construir_arvore_solucao(valores, 0);

};
// Desconstrutor da Ávores. Chama a função remover() para desalocar os nós.
ArvoreBinaria::~ArvoreBinaria() {
    remover(this->raiz);
};

// Construtor da arvore de soluções. Cada Nó filho é uma alteração no possível vetor de valores.
NoArvore* ArvoreBinaria::construir_arvore_solucao(std::string valores, int index) {
    NoArvore* no = new NoArvore(valores);

    for (unsigned i = index; i < valores.length(); i++)
    {
        if(valores[i] == 'e' || valores[i] == 'a') {
            std::string valores_esq = valores;
            valores_esq[i] = '0';
            no->esq = construir_arvore_solucao(valores_esq, i + 1);

            std::string valores_dir = valores;
            valores_dir[i] = '1';
            no->dir = construir_arvore_solucao(valores_dir, i + 1);

            break;
        }
    }
    
    //std::cout << "Estado final: " << no->pega_vetor_valores() << "-" << no->ressultado_expressao() << std::endl;
    return no;

};

// Verifica o valor do Nó raiz para saber se a ávores já foi construída.
bool ArvoreBinaria::esta_construida() {
    return !(this->raiz == nullptr);

};
// Desaloca um Nó.
void ArvoreBinaria::remover(NoArvore *no) {
    if(no) {
        remover(no->esq);
        remover(no->dir);
        delete no;

    }

};
// Pecorre toda a árvore definindo os valores do ressultado da expressão, de acordo com o ressultado dos filhos.
 // preciso contar o Nivel? Revisar
void ArvoreBinaria::avaliar(NoArvore *no, unsigned int profundidade) {
    if(no) {
        avaliar(no->esq, profundidade+1);
        avaliar(no->dir, profundidade+1);

        /***
         
        if(no->esq != nullptr && no->dir != nullptr) {

            std::cout << "Profundidade: " << profundidade << " Filho esquerdo: " << no->esq->pega_vetor_valores() << "-" << no->esq->ressultado_expressao() << "Filho direito" << no->dir->pega_vetor_valores() << "-" << no->dir->ressultado_expressao() << std::endl;
            std::cout << "Pai " << no->pega_vetor_valores() << "-" << no->ressultado_expressao() << std::endl;
        
        } 
        ***/

        // Se os dois próximos nós estão vaizios, chequei nas folhas da ávore (Ùltimos filhos);
        if(no->esq == nullptr && no->dir == nullptr) {
            no->definine_ressultado_expressao(ressolver_expressao(this->expressao, no->pega_vetor_valores()));
        } else if(no->esq->ressultado_expressao() == 1 && no->dir->ressultado_expressao() == 1) {
            // Se os dois filhos forem verdadeiros (1) vou usar o parãmetro 'a'

            no->definine_ressultado_expressao(1); 
            for (unsigned i = 0; i < no->pega_vetor_valores().length(); i++)
            {
                if(no->esq->pega_vetor_valores()[i] == no->dir->pega_vetor_valores()[i]) {
                    no->define_valor_index(no->esq->pega_vetor_valores()[i], i);
                } else {
                    no->define_valor_index('a', i);
                    //std::cout << "Estado fora " << no->pega_vetor_valores();
                }
            }
            
        } else if(no->esq->ressultado_expressao() == 0 && no->dir->ressultado_expressao() == 0) {
            // Dois filhos falsos, o ressultado do pai é falso            
            
            no->definine_ressultado_expressao(0); 
        } else {
            // Um dos dois verdadeiros. Avaliar se quero uma reposta 'a' ou 'e'
            char param = no->pega_paramentro();
            if (param == 'a') {
                no->definine_ressultado_expressao(0); 
            } else {
                no->definine_ressultado_expressao(1);

                if(no->esq->ressultado_expressao() == 1) {
                    no->define_vetor_valores(no->esq->pega_vetor_valores());
                } else {
                    no->define_vetor_valores(no->dir->pega_vetor_valores());
                }
            }

        }
         
    }

};

// Retorna Nó raiz
NoArvore* ArvoreBinaria::pega_raiz() const {
    return this->raiz;
};