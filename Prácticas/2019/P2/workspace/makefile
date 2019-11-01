##########################################################################
# makefile
##########################################################################
OBJ=obj
BIN=bin
SRC=src
INC=include
##########################################################################
$(BIN)/test_ingredientes: $(OBJ)/test_ingredientes.o $(OBJ)/ingredientes.o $(OBJ)/ingrediente.o $(OBJ)/vector_dinamico.o
	g++ -std=c++11 -o $(BIN)/test_ingredientes $(OBJ)/test_ingredientes.o $(OBJ)/ingredientes.o $(OBJ)/ingrediente.o $(OBJ)/vector_dinamico.o

$(OBJ)/ingrediente.o: $(SRC)/ingrediente.cpp $(INC)/ingrediente.h
	g++ -std=c++11 -c -o $(OBJ)/ingrediente.o -I$(INC) $(SRC)/ingrediente.cpp


$(OBJ)/ingredientes.o: $(SRC)/ingredientes.cpp $(INC)/ingredientes.h $(INC)/vector_dinamico.hpp
	g++ -c -o $(OBJ)/ingredientes.o -I$(INC) $(SRC)/ingredientes.cpp

$(OBJ)/test_ingredientes.o: $(SRC)/test_ingredientes.cpp $(INC)/ingredientes.h $(INC)/vector_dinamico.hpp
	g++ -std=c++11 -c -o $(OBJ)/test_ingredientes.o -I$(INC) $(SRC)/test_ingredientes.cpp
##########################################################################
clean:
	rm $(OBJ)/*.o $(BIN)/*
##########################################################################
rmproper: clean
	rm $(BIN)/prueba
##########################################################################