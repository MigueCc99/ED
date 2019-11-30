##########################################################################
# makefile
##########################################################################
OBJ=obj
BIN=bin
SRC=src
INC=include
##########################################################################
$(BIN)/test_ingredientes: $(OBJ)/test_ingredientes.o $(OBJ)/tipos_ingredientes.o $(OBJ)/ingredientes.o $(OBJ)/ingrediente.o
	g++ -std=c++11 -o $(BIN)/test_ingredientes $(OBJ)/test_ingredientes.o $(OBJ)/ingredientes.o $(OBJ)/ingrediente.o 
	g++ -std=c++11 -o $(BIN)/tipos_ingredientes $(OBJ)/tipos_ingredientes.o $(OBJ)/ingredientes.o $(OBJ)/ingrediente.o 

$(OBJ)/test_ingredientes.o: $(SRC)/test_ingredientes.cpp $(INC)/ingredientes.h 
	g++ -std=c++11 -c -o $(OBJ)/test_ingredientes.o -I$(INC) $(SRC)/test_ingredientes.cpp

$(OBJ)/tipos_ingredientes.o: $(SRC)/tipos_ingredientes.cpp $(INC)/ingredientes.h  $(INC)/vector_dinamico.hpp
	g++ -std=c++11 -c -o $(OBJ)/tipos_ingredientes.o -I$(INC) $(SRC)/tipos_ingredientes.cpp

$(OBJ)/ingredientes.o: $(SRC)/ingredientes.cpp $(INC)/ingredientes.h $(INC)/vector_dinamico.hpp
	g++ -std=c++11 -c -o $(OBJ)/ingredientes.o -I$(INC) $(SRC)/ingredientes.cpp

$(OBJ)/ingrediente.o: $(SRC)/ingrediente.cpp $(INC)/ingrediente.h
	g++ -std=c++11 -c -o $(OBJ)/ingrediente.o -I$(INC) $(SRC)/ingrediente.cpp

##########################################################################
clean:
	rm $(OBJ)/*.o $(BIN)/*
##########################################################################
rmproper: clean
	rm $(BIN)/test_ingredientes
##########################################################################