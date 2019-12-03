/**
  * EJERCICIO 10
  * Usando una pila y una cola, implementa una función que compruebe si un string
  * es un palíndromo
  *
  * @author Miguel Ángel Campos Cubillas
  */

#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

bool es_palindromo (string cadena){
  stack<char> pila;
  queue<char> cola;

  for (int i=0; i < cadena.size(); i++){
    pila.push(cadena[i]);
    cola.push(cadena[i]);
  }

  for (int i=0; i < cadena.size(); i++){
    if (pila.top() == cola.front()){
      pila.pop();
      cola.pop();
    }
    else return false;
  }
  return true;
}

int main (int argc, char *argv[]){
  string cadena;

  cout << "Introduce una cadena de caracteres para comprobar si es palíndromo: ";
  cin >> cadena;
  cout <<  endl;

  cout << "¿Es palíndromo? => ";
  if (es_palindromo(cadena))
    cout << "Sí" << endl;
  else
    cout << "No" << endl;

  return 0;
}
