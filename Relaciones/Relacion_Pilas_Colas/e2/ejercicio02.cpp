#include <iostream>
#include <string>
#include <stack>

using namespace std;

/**
  * EJERCICIO 2
  * Implementa una función para determinar si una expresión contenida en un string tiene una configuración 
  * de paréntesis correcta. Debe tener un orden lineal.
  * 
  * @author Miguel Ángel Campos Cubillas
  */

bool configuracion_parentesis_correcta(string expresion){
  stack<char> pila;
	bool good_conf = false;
	char parenthesis1 = '(';
	char parenthesis2 = ')';

	for (unsigned i=0; i<expresion.size(); ++i){
			if (expresion[i] == parenthesis1){
				pila.push(parenthesis1);
			}
			else if (expresion[i] == parenthesis2){
				if (pila.empty())
					return false;
				else{
					pila.pop();
				}
			}
	}
	return (pila.empty());
}

 int main(int argc, char *argv[]){
     string expresion;

     cout << "Introduce una expresión con paréntesis: ";
     cin >> expresion;
     cout << endl;

     bool good_conf = configuracion_parentesis_correcta(expresion);

     if(good_conf)
      cout << "Buena configuración de paréntesis para la expresión " << expresion <<  endl;
     else
      cout << "Mala configuración de paréntesis para la expresión " << expresion <<  endl;

      return 0;
 }