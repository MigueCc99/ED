/**
  * EJERCICIO 6
  * Expresión en postfijo: expresión matemática en la que cada operación aparece
  * con sus dos operandos seguidos por el operador.
  * Ejemplo: 23+5* Escribe un programa que evalúe una expr. en postfijo
  *
  * @author Miguel Ángel Campos Cubillas
  */
  #include <iostream>
  #include <string>
  #include <stack>
  #include <queue>

  using namespace std;
  
  string evalua_postfijo (string cadena){
    stack<string> pila;
    unsigned i;
    string dcha, izq;

    for (i=0; i<cadena.size(); ++i){
      if((cadena[i] >= 'a') && (cadena[i] <= 'z'))
        pila.push(string(1,cadena[i]));
      else{
        dcha = pila.top();
        pila.pop();
        izq = pila.top();
        pila.pop();

        switch(cadena[i]){
          case '+':
            pila.push(izq+'+'+dcha);
          break;
          case '-':
            pila.push(izq+'-'+dcha);
          break;
          case '*':
            pila.push(izq+'*'+dcha);
          break;
          case '/':
            pila.push(izq+'/'+dcha);
          break;
          case '^':
            pila.push(izq+'^'+dcha);
          break;
        }
      }
    }
    return pila.top();
  }

  int main (int argc, char *argv[]){
    string expresion;

    cout << "Introduce una expresion postfija => ";
    cin >> expresion;
    cout << endl;

    cout << "El resultado es " << evalua_postfijo(expresion) << endl;

    return 0;
  }
