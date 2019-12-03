/**
  * EJERCICIO 1
  * Un método de encriptación basado en un código consiste en trasnformar cada letra del alfabeto por otra.
  * Implementa una función <encripta> a la que se le pase una cadena de caracteres y un map<char,char> con
  * el código y que devuelva la cadena encriptada
  *
  * @author Miguel Ángel Campos Cubillas
  */

#include <iostream>
#include <string>
#include <map>

using namespace std;

typedef map<char, char> diccionario;

string encripta(string cad, const diccionario &code){
    for(int i=0; i < cad.size(); i++){
        auto we = code.find(cad[i]);
        if(we != code.end())
            cad[i] = we->second;
    }
    return cad;
}

int main(){
    diccionario encriptador;

    for(char c = 'a'; c < 'z'; c++){
        encriptador.insert({c,c+1});
        encriptador.insert({'z','a'});
    }

    for(char c = 'A'; c < 'Z'; c++){
        encriptador.insert({c,c+1});
        encriptador.insert({'Z','A'});
    }

    string cadena = "Unx z Zoqnazq";

    string cadena_encriptada = encripta(cadena,encriptador);

    cout << cadena_encriptada << endl << endl;

    return 0;
}



