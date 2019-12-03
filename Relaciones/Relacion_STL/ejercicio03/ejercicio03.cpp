/**
  * EJERCICIO 3
  * Construye una función a la que se le pase el nombre de un fichero y le devuelva un map
  * que contenga las palabras que aparecen y el número de veces que aparece cada una
  *
  * @author Miguel Ángel Campos Cubillas
  */

#include<iostream>
#include<fstream>
#include <string>
#include <map>

using namespace std;

typedef map<string,int> diccionario_StringInt;

diccionario_StringInt fichero(const string &nombre){
  diccionario_StringInt aux;
  ifstream f(nombre);
  string palabra;

  while(f >> palabra)
    aux[palabra]++;

  f.close();

  return aux;
}

int main(){

  auto diccionario = fichero("ejercicio03.cpp");
  for(diccionario_StringInt::const_iterator it = diccionario.cbegin(); it != diccionario.cend(); ++it)
    cout << "Palabra: " << it->first << " aparece " << it->second << " veces!!!" << endl;
  return 0;
}
