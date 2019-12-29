#include "acciones.h"
#include "instrucciones.h"
#include "ingrediente.h"
#include "ingredientes.h"
#include "recetas.h"
#include "receta.h"
#include <fstream>
using namespace std;

void mostrar_ingredientes(Receta &receta){
  cout << "Ingredientes:" << endl << endl;
  for(Receta::iterator it = receta.begin(); it != receta.end(); ++it){
    cout << (*it).first << " " << (*it).second << endl;
  }
}

void calcular_valor_nutricional(Recetas &rall,Ingredientes &allingre){
  for(Recetas::iterator it = rall.begin(); it != rall.end(); ++it){
    (*it).obtieneNutricional(allingre);
  }
}

int main(int argc,char *argv[]){

  if (argc!=5){
    cout<<"FORMATO => ./bin/cocinero_integral datos/Acciones.txt datos/recetas.txt datos/ingredientes.txt datos/instrucciones/"<<endl;
    return 0;
  }

  /***********************************************************************/
  //Fase 1: CARGAR EN MEMORIA LAS ACCIONES 

  ifstream f_acciones(argv[1]);
  if (!f_acciones){
	  cout<<"No existe el fichero "<<argv[1]<<endl;
  }

  Acciones acc;
  //ArbolBinario<string> arbol;
  Instrucciones instr;
  f_acciones >> acc;
  instr.acc = acc;
  //Instrucciones instr (arbol, acc);
  cout << "Todas las Acciones:" << endl;
  cout << acc<< endl;
  cout << "Pulse una tecla para continuar"<< endl;
  cin.get(); 
  

  /***********************************************************************/
  //Fase 2: CARGAR EN MEMORIA LOS INGREDIENTES
  
  ifstream f_ingredientes(argv[3]);
  if (!f_ingredientes){
	  cout<<"No existe el fichero "<<argv[3]<<endl;
  }
  
  Ingredientes allingre;

  f_ingredientes >> allingre;
  cout << "Todos los ingredientes:" << endl;
  cout << allingre<< endl;
  cout << "Pulse una tecla para continuar"<< endl;
  cin.get(); 


  /***********************************************************************/
  //Fase 3: CARGAR EN MEMORIA LAS RECETAS Y MOSTRARLAS POR PANTALLA
  
  ifstream f_recetas(argv[2]);
  if (!f_recetas){
	  cout<<"No existe el fichero "<<argv[2]<<endl;
  }

  Recetas rall;
  f_recetas >> rall;

  /***********************************************************************/
  //Fase 4: OBTENER EL VALOR NUTRICIONAL DE TODAS LAS RECETAS USANDO LOS INGREDIENTES

  calcular_valor_nutricional(rall,allingre);

  /***********************************************************************/
  //Fase 5: MOSTRAR LAS RECETAS

  cout << "Todas las Recetas:" << endl;
  cout << rall<< endl;
  cout << "Numero de recetas "<< rall.size()<< endl;
  cout << "Pulse una tecla para continuar"<< endl;
  cin.get();

  /***********************************************************************/
  //Fase 6: PEDIR AL USUARIO UN CÓDIGO DE RECETA

  string code;
  Receta receta;

  cout << "Introduce un código de receta:";
  cin >> code;
  cout << endl;

  string ruta = argv[4] + code + "m.txt";
  ifstream f_instrucciones(ruta);
  if (!f_instrucciones){
	  cout<<"No existe el fichero "<<ruta<<endl;
  }
  cout << "ruta" << ruta << endl << endl;
  f_instrucciones >> instr;

  /***********************************************************************/
  //Fase 7: MOSTRAR LA RECETA ESCOGIDA
  
  receta = rall[code];
  cout << "Receta escogida: " << receta << endl;

  mostrar_ingredientes(receta);
  cout << endl;
  receta.muestraNutricional();
  
  cout << "\nPasos a seguir: " << instr << endl;
  cout << "Hay un error al mostrar los pasos a seguir. Me da error al ultilizar el operator= para asignar los datos del arbol a los datos de las instrucciones para posteriormente mostrarlos por pantalla con el ostream " << endl;
  cout << instr << endl;

}
