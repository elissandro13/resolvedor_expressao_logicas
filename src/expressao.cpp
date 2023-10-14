#include "pilha.hpp"
#include "expressao.hpp"
#include <iostream>
#include <sstream>

// Controla ordem de prioridade das diferente operações
int prioridade(char op) {
    if (op == '~')
        return 3;
    if (op == '&')
        return 2;
    if (op == '|')
        return 1;    

    return 0;
}

// Realiza as operações
int operacao(int a, int b, char op) {
    //std::cout << " A: " << a << " " << op << " " << "B : " << b << std::endl;
    switch (op) {
        case '&':
            return a & b;
        case '|':
            return a | b;
        case '~':
            return a == 0 ? 1 : 0;
        default:
            return -1;
    }
}

// Fluxo para diferenciar as operações and e or da negado
void ressolve(Pilha<int> *pilha_valores, Pilha<char> *pilha_operadores) {

    if(pilha_operadores->pegaTopo() == '~') {
        pilha_valores->empilha(operacao(pilha_valores->desempilha(), -1, pilha_operadores->desempilha()));
        //std::cout << " Ressultado: " << pilha_valores->pegaTopo() << std::endl;

    }

    else {
        pilha_valores->empilha(operacao(pilha_valores->desempilha(), pilha_valores->desempilha(), pilha_operadores->desempilha()));
        //std::cout << " Ressultado: " << pilha_valores->pegaTopo() << std::endl;
    }

}

// Loop principal para construir as pilhas dos valores e dos operadores
int ressolver_expressao(std::string expressao, std::string valores) {
    Pilha<int> pilha_valores;
    Pilha<char> pilha_operadores;


    std::string::size_type i = 0;

    std::string exp = expressao;

    std::istringstream ss(exp);
    std::string sub_string;

    while(getline(ss, sub_string, ' ')) {

	    std::cout << "-" << sub_string << "-" << std::endl;
       
    
    }

    while (i < expressao.size())
    {
       char c = expressao[i];
       //std::cout << "Olha ai: " << c << std::endl;
       switch (c)
       {
        case ' ':
                break;

            case '(':
                pilha_operadores.empilha(c);
                break;
            
            case ')':
                while(!pilha_operadores.vazio() && pilha_operadores.pegaTopo() != '(') ressolve(&pilha_valores, &pilha_operadores);
                if(!pilha_operadores.vazio()) pilha_operadores.desempilha(); 
                break;
            
        
        default:
            if(isdigit(c)) {
                int pos = c - '0';
                pilha_valores.empilha(valores[pos] - '0');

            } else {
                
                while(!pilha_operadores.vazio() && !pilha_valores.vazio() && (prioridade(pilha_operadores.pegaTopo()) > prioridade(c))) 
                    ressolve(&pilha_valores, &pilha_operadores);
                pilha_operadores.empilha(c);
            }
                break;
       }
        i++;
    }
    
    while (!pilha_operadores.vazio()) ressolve(&pilha_valores, &pilha_operadores);
    return pilha_valores.pegaTopo();

};
