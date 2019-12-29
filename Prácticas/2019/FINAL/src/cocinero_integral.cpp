#include "acciones.h"
#include "instrucciones.h"
#include "ingrediente.h"
#include "ingredientes.h"
#include "recetas.h"
#include "receta.h"
#include <fstream>
using namespace std;

void calcular_valor_nutricional(Recetas &recetas, Ingredientes &ingredientes){
  Receta receta;
  Ingrediente ingrediente;
  bool encontrado = false;
  float gramos,calorias,cal_100,hc,prot,grasas,fibra,aux = 0;
  for(Recetas::iterator it = recetas.begin(); it != recetas.end(); ++it){
    receta =(*it);
    for(Receta::iterator ir = receta.begin(); ir != receta.end(); ++ir){
      for(Ingredientes::iterator ii = ingredientes.begin(); ii != ingredientes.end() && !encontrado; ++ii){
        ingrediente = (*ii);
        if((*ir).first == ingrediente.getNombre()){
          cal_100 = ingrediente.getCalorias();
          gramos = (*ir).second;
          calorias += (cal_100/100)*gramos;
          aux = ingrediente.getHidratos();
          hc += gramos*(aux/100);
          aux = ingrediente.getProteinas();
          prot += gramos*(aux/100);
          aux = ingrediente.getGrasas();
          gramos += gramos*(aux/100);
          aux = ingrediente.getFibras();
          fibra += gramos*(aux/100);
          encontrado = true;
        }
      }
      encontrado = false;
    }
  }
      receta.setCalorias(calorias);
      receta.setHc(hc);
      receta.setProteinas(prot);
      receta.setGrasas(grasas);
      receta.setFibra(fibra);
}

void mostrar_ingredientes(Receta &receta){
  cout << "Ingredientes:" << endl << endl;
  for(Receta::iterator it = receta.begin(); it != receta.end(); ++it){
    cout << (*it).first << " " << (*it).second << endl;
  }
}

void info_nutricional(Receta &receta){
  cout << "Información Nutricional:" << endl << endl;
  cout << "Calorias:" << receta.getCalorias() << endl;
  cout << "Hidratos de Carbono:" << receta.getHc() << endl;
  cout << "Grasas:" << receta.getGrasas() << endl;
  cout << "Proteina:" << receta.getProteinas() << endl;
  cout << "Fibra:" << receta.getFibras() << endl;
}

Acciones Instrucciones::acc;

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
  Instrucciones instr;
  f_acciones >> acc;
  instr.acc = acc;
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
  cout << "ruta" << ruta << endl;
  f_instrucciones >> instr;

  /***********************************************************************/
  //Fase 7: MOSTRAR LA RECETA ESCOGIDA
  
  receta = rall[code];
  cout << "Receta escogida: " << receta << endl;

  mostrar_ingredientes(receta);
  cout << endl;
  info_nutricional(receta);
  

}
