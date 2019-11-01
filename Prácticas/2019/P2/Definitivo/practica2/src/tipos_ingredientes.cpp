#include <iostream>
#include <fstream>
#include <string>
#include "vector_dinamico.h"
#include "ingrediente.h"
#include "ingredientes.h"

using namespace std;

int main (int argc, char *argv[]){
    
    if (argc != 3){
        cout << "./bin/tipos_ingredientes datos/ingredientes.txt tipo_ingrediente(ej: 'Molusco')" << endl;
        return 0;
    }

    string nombre_fichero = argv[1];
    ifstream f(nombre_fichero);

    if (!f){
        cout << "No puedo abrir " << nombre_fichero << endl;
        return 0;
    }

    string tipo_ingrediente ("Molusco");
    f.seekg(0);
    Ingredientes all_ingredientes;
    cout << "Lectura de todos los ingredientes" << endl;
    f >> all_ingredientes;

    Vector_Dinamico<string> tipos=all_ingredientes.getTipos();
    

    return 0;
}
