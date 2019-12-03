/**
  * EJERCICIO 4
  * Construye una función que dado el map del ejercicio anterior devuelva un
	* multimap que nos permita consultar las palabras que aparecen un número
	* determinado de veces.
  *
  * @author Miguel Ángel Campos Cubillas
  */

  #include <iostream>
  #include <fstream>
  #include <string>
  #include <map>

  using namespace std;

  typedef map<string,int> diccionario_StringInt;
  typedef multimap<int, string> diccionario_IntString;

  diccionario_StringInt fichero(const string &nombre){
    diccionario_StringInt aux;
    ifstream f(nombre);
    string palabra;

    while(f >> palabra)
      aux[palabra]++;

    f.close();

    return aux;
  }

  diccionario_IntString fichero_times(diccionario_StringInt &d){
    diccionario_IntString times;

    for(diccionario_StringInt::iterator it = d.cbegin(); it != d.cend(); ++it)
      times.insert({it->second, it->first});

    return times;
  }

  int main(){

    auto diccionario = fichero("ejercicio03.cpp");
    auto diccionario_times = fichero_times(diccionario);
    for(diccionario_StringInt::const_iterator it = diccionario_times.cbegin(); it != diccionario_times.cend(); ++it)
      cout << it->first<< it->second << endl;
    return 0;
  }
