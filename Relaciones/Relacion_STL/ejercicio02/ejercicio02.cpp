/**
  * EJERCICIO 2
  * Implementa una función desencripta que haga la función inversa al ejercicio anterior
  *
  * @author Miguel Ángel Campos Cubillas
  */

#include<iostream>
#include <string>
#include <map>

using namespace std;

typedef map<char, char> diccionario;

string desencripta(string cad, const diccionario &code){
  diccionario desencriptador;
  for(diccionario::const_iterator it = code.cbegin(); it != code.cend(); ++it)
    desencriptador.insert({it->second, it->first});

  for(int i = 0; i < cad.size(); i++){
    auto we = desencriptador.find(cad[i]);
    if(we != desencriptador.end())
      cad[i] = we->second;
  }
  return cad;
}

int main(){
  diccionario encriptador;

  for (char c ='a'; c < 'z'; c++)
		encriptador.insert({c, c+1});
	  encriptador.insert({'z','a'});

	for (char c = 'A'; c < 'Z'; c++)
		encriptador.insert({c,c+1});
	  encriptador.insert({'Z','A'});

  string cadena = "Granada";

  string cadena_desencriptada = desencripta(cadena,encriptador);

  cout << cadena_desencriptada << endl << endl;
  return 0;
}
