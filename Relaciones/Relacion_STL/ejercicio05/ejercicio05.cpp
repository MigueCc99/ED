/**
  * EJERCICIO 5
  * Construye una función a la que se le pasen los parámetros con los que se ha
	* ejecutado un programa y determine qué opciones se han seleccionado y, en su
	* caso, el valor que se la ha asignado. Por ejemplo: tar -z -x -f fichero
	* debería indicar que se han activado z,x y también f que tiene un parámetro
	* fichero.
  *
  * @author Miguel Ángel Campos Cubillas
  */

#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

typedef map<string,string> diccionario_ss;

void param(diccionario_ss &diccionario, string cad){
  istringstream line(cad);
  string palabra;
  string fichero;

  bool first = true;
  bool opt = false;

  while(line >> palabra){
    if(first)
      first = false;
    else{
      if(palabra[0] == '-'){
        if(opt)
          diccionario.insert({fichero,""});
        else
          opt = true;
        fichero = palabra;
      }
      else{
        opt = false;
        diccionario.insert({fichero,palabra});
      }
    }
  }

  if(palabra[0] == '-')
    diccionario.insert({palabra,""});
}

int main(){
  string orden = "tar -z -x -f fichero -c directorio";
  string espacio = " ";
  diccionario_ss diccionario;

  param(diccionario,orden);
  for(diccionario_ss::iterator it = diccionario.begin(); it != diccionario.end(); ++it)
    cout << it->first << espacio << it->second << endl;

  return 0;
}
