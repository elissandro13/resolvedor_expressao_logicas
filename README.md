# Resolvedor de expressões Lógicas
Um resolvedor de expressões lógicas e avaliador de condições para satisfabilidade.


## Estrtura
*  |- src
*  |- bin
*  |- obj
*  |- include
*  Makefile

## Uso
 * make all
 * ./bin/main

## Entrdas
* Uma string, podendo assumir dois valores, “-a” - se o problema a ser resolvido é
o de avaliação de expressões booleanas “-s”, se o problema a ser resolvido é o
de satisfabilidade.
* Uma string P contendo a representação da expressão booleana.
* O terceiro é uma string S contendo a valoração da expressão, caso o primeiro
parâmetro seja “-s”, essa string pode conter os caracteres “e” (existe) e “a”
(para-todo). Caso o problema seja apenas resolver a avaliação de expressão, a
saída será apenas 0 ou apenas 1. Caso contrário, doiscasos podem ser
retornados:
** 0, caso não exista uma expressão que retorne 1.



## Alguns exemplos de entradas
* . / tp1 . out −a "0 | 1" 01
* . / tp1 . out −a "~ ( 0 | 1 ) & 2" 101
* . / tp1 . out −s "0 | 1 & 2" e00
