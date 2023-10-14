#include "pilha.hpp"
#include "expressao.hpp"
#include <iostream>
#include <sstream>


bool isOperador(std::string c) {

    if(c.compare("|") == 0) 
        return true;
    else if(c.compare("&") == 0) 
        return true;
    else if(c.compare("~") == 0) 
        return true;

    return false;

};

bool isNumber(std::string c) {
    if(!isOperador(c) && c.compare(" ") != 0 && c.compare("  ") != 0 && c.compare("(") != 0 && c.compare(")") != 0)
        return true;
    return false;
};

// Controla ordem de prioridade das diferente operações
int prioridade(std::string c) {
    char op = c[0];
    if (op == '~')
        return 3;
    if (op == '&')
        return 2;
    if (op == '|')
        return 1;    

    return 0;
}

// Realiza as operações
int operacao(int a, int b, std::string op) {
    std::cout << " A: " << a << " " << op << " " << "B : " << b << std::endl;
    char c = op[0];
    switch (c) {
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
void ressolve(Pilha<int> *pilha_valores, Pilha<std::string> *pilha_operadores) {

    if(pilha_operadores->pegaTopo().compare("~") == 0) {
        pilha_valores->empilha(operacao(pilha_valores->desempilha(), -1, pilha_operadores->desempilha()));
        std::cout << " Ressultado: " << pilha_valores->pegaTopo() << std::endl;

    }

    else {
        pilha_valores->empilha(operacao(pilha_valores->desempilha(), pilha_valores->desempilha(), pilha_operadores->desempilha()));
        std::cout << " Ressultado: " << pilha_valores->pegaTopo() << std::endl;
    }

}

// Loop principal para construir as pilhas dos valores e dos operadores
int ressolver_expressao(std::string expressao, std::string valores) {
    Pilha<int> pilha_valores;
    Pilha<std::string> pilha_operadores;


    std::string::size_type i = 0;

    std::string exp = expressao;

    std::istringstream ss(exp);
    std::string sub_string;

    while(getline(ss, sub_string, ' ')) {

	    std::string c = sub_string;
       std::cout << "Olha ai: " << c << std::endl;

       if(c.compare(" ") == 0) {
            continue;
       } else if(c.compare("(") == 0) {
            pilha_operadores.empilha(c);

       } else if(c.compare(")") == 0) {
            std::cout << "Entrou )" << std::endl;
            while(!pilha_operadores.vazio() && pilha_operadores.pegaTopo().compare("(") != 0) ressolve(&pilha_valores, &pilha_operadores);
            if(!pilha_operadores.vazio()) pilha_operadores.desempilha(); 
                

       } else {
          if(isNumber(c)) {
                int pos = std::stoi(c);
                pilha_valores.empilha(valores[pos] - '0');
                std::cout << "Valor colocado na pilha: "<< pilha_valores.pegaTopo() << std::endl;
          } else {
                while(isOperador(c) && !pilha_operadores.vazio() && !pilha_valores.vazio() && (prioridade(pilha_operadores.pegaTopo()) > prioridade(c))) 
                    ressolve(&pilha_valores, &pilha_operadores);
                pilha_operadores.empilha(c);
          }
       }
       
    
    
       
    
    }
    while (!pilha_operadores.vazio()) ressolve(&pilha_valores, &pilha_operadores);
    return pilha_valores.pegaTopo();
 /***

    while (i < expressao.size())
    {
       char c = sub_string;
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
  ***/
};
