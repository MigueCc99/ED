#include "acciones.h"
#include "recetas.h"
#include <fstream>
using namespace std;
int main(int argc,char *argv[]){

  if (argc!=3){
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
  cout << acc<< endl;
  cout << "Pulse una tecla para continuar"<< endl;
  cin.get(); 
  

  /***********************************************************************/
  //Fase 2: CARGAR EN MEMORIA LOS INGREDIENTES
  /***********************************************************************/
  //Fase 3: CARGAR EN MEMORIA LAS RECETAS Y MOSTRARLAS POR PANTALLA
  
  ifstream f_recetas(argv[2]);
  if (!f_recetas){
	  cout<<"No existe el fichero "<<argv[2]<<endl;
  }

  Recetas rall;
  f_recetas >> rall;
  cout << rall<< endl;
  cout << "Numero de recetas "<< rall.size()<< endl;
  cout << "Pulse una tecla para continuar"<< endl;
  cin.get(); 

  /***********************************************************************/
  //Fase 4: PEDIR AL USUARIO UN CÓDIGO DE RECETA


}
