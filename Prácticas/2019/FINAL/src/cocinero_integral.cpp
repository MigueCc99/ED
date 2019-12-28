#include "acciones.h"
#include "ingredientes.h"
#include "recetas.h"
#include <fstream>
using namespace std;
int main(int argc,char *argv[]){

  if (argc!=4){
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

  f_acciones >> acc;
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

  //rall.obtener_valor_nutricional();

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

  /***********************************************************************/
  //Fase 5: MOSTRAR LA RECETA ESCOGIDA
  
  receta = rall[code];
  cout << "Receta escogida: " << receta << endl;

  /***********************************************************************/
  //Fase 6: MOSTRAR LA RECETA ESCOGIDA
}
