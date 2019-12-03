#include <iostream>
#include <stack>
using namespace std;

/**
  * EJERCICIO 1
  * Construye una función a la que se le pase una pila P de tipo T y dos elementos x,y de tipo T
  * y que modifique la pila de forma que todas las veces que aparezca x se substituya por y (quedando
  * la pila en el mismo estado en el que estaba anteriormente). Para este ejercicio no podrán usarse
  * iteradores.
  * 
  * @author Miguel Ángel Campos Cubillas
  */

template <class T>
void imprime_pila(stack<T> pila){
    stack<T> aux;
    while (!pila.empty()){
        aux.push(pila.top());
        pila.pop();
    }
    
    while (!aux.empty()){
        cout << aux.top() << " ";
        aux.pop();
    } 
}

template <class T>
void substituye_x_y(const T &x, const T &y, stack<T> &pila){
    stack<T> aux;
    while (!pila.empty()){
        if (x != pila.top())
            aux.push(pila.top());
        else
            aux.push(y); 
        pila.pop();
    }

    while (!aux.empty()){
        pila.push(aux.top());
        aux.pop();
    } 
}

int main (int argc, char *argv[]){
    stack<int> pila;
    int num_elementos = 0;
    int elemento = 0;
    int contador = 0;
    int x = 5;
    int y = 1999;

    cout << "¿Cuántos elementos quieres añadir?" << endl << "Numero de elementos a añadir: ";
    cin >> num_elementos;

    cout << "\nIntroduce " << num_elementos << " elementos\n";
    cin >> elemento;
    while (contador < num_elementos){
        pila.push(elemento);
        cin >> elemento;
        contador++;
    }

    cout << "\n\nImprimimos la pila SIN MODIFICAR: ";
    imprime_pila(pila);

    cout << "\n\nSubstituimos x por y donde sea necesario...";
    substituye_x_y(x,y,pila);

    cout << "\n\nImprimimos la pila MODIFICADA: ";
    imprime_pila(pila);

    return 0;
}