#include <iostream>
#include <fstream>
#include <string>
#include "vector_dinamico.hpp"
#include "ingrediente.h"
#include "ingredientes.h"
using namespace std;

void MuestraParametros(){

    cout << "1.- Dime el nombre del fichero con los ingredientes\n" 
         << "2.- Dime el tipo de ingrediente a analizar"
         << endl;
}

int main(int argc, char *argv[]){
    
    if (argc != 3){             // Comprobamos si el número de parámetros es el correcto
        MuestraParametros();
        return 0;
    }
    
    string nf = argv[1];        // Recogemos el nombre del fichero en un string
    ifstream f(nf);             // Usamos el constructor del archivo de entrada con nombre nf

    if (!f){                    // Si no se puede abrir el fichero, abortar
        cout << "No puedo abrir " << nf << endl;
        return 0;
    }

    f.seekg(0);                 // Ponemos el puntero del fichero al principio del mismo
    Ingredientes all_ingre;
    cout << "Lectura de todos los ingredientes" << endl;
    f >> all_ingre;

    //Comprobamos que hemos hecho bien la lectura
    cout << "Los ingredientes ordenados por nombre..." << endl
         << endl;
    cout << all_ingre << endl;
    ;
    cout << "Pulse una tecla para continuar..." << endl
         << endl;
    cin.get();

    cout << "Imprimos por tipo " << endl;
    all_ingre.imprimirPorTipo(cout);

    cout << endl
         << "Pulse una tecla para continuar..." << endl
         << endl;
    cin.get();

   Vector_Dinamico<string> tipos = all_ingre.getTipos();
   cout<<"Los tipos de alimentos son:"<<endl;
   for (int i=0;i<tipos.getNumElementos(); ++i){
      cout<<tipos[i]<<endl;
   }
   cout<<"Pulse una tecla para continuar "<<endl;
   cin.get();
  
   string tipo=argv[2];
   Ingredientes ingre_tipo=all_ingre.getIngredientesTipo(tipo);
   cout<<"Los ingredientes de tipo "<<tipo<<" son: "<<endl<<ingre_tipo<<endl;

   cout << endl
         << "Pulse una tecla para continuar..." << endl
         << endl;
    cin.get();

   all_ingre.getEstadistica(tipo);
   
   return 0;
}