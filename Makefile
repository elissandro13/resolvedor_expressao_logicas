CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/pilha.o $(OBJ)/expressao.o $(OBJ)/arvoreBinaria.o $(OBJ)/no.o $(OBJ)/satisfatibilidade.o $(OBJ)/main.o 
HDRS = $(INC)/pilha.hpp $(INC)/expressao.hpp $(INC)/arvoreBinaria.hpp $(INC)/no.hpp $(INC)/satisfatibilidade.hpp
CFLAGS = -g -Wall -c -I$(INC)

EXE = $(BIN)/main

 
.PHONY: all debug clean 

all: $(BIN)/tp1.out

debug: $(BIN)/tp1_teste.out
	

#colocar -pg para debugar

$(BIN)/tp1_teste.out: $(OBJS)
	$(CC) -o $(BIN)/tp1_teste.out $(OBJS) $(LIBS)

$(BIN)/tp1.out: $(OBJS)
	$(CC)  -o $(BIN)/tp1.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/satisfatibilidade.o: $(HDRS) $(SRC)/satisfatibilidade.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/satisfatibilidade.o $(SRC)/satisfatibilidade.cpp

$(OBJ)/arvoreBinaria.o: $(HDRS) $(SRC)/arvoreBinaria.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/arvoreBinaria.o $(SRC)/arvoreBinaria.cpp

$(OBJ)/no.o: $(HDRS) $(SRC)/no.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/no.o $(SRC)/no.cpp

$(OBJ)/expressao.o: $(HDRS) $(SRC)/expressao.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/expressao.o $(SRC)/expressao.cpp  

$(OBJ)/pilha.o: $(HDRS) $(SRC)/pilha.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/pilha.o $(SRC)/pilha.cpp
	
clean:
	rm -f $(BIN)/*.out $(EXE) $(OBJS) gmon.out
