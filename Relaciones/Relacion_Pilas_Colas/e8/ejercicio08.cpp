/**
  * EJERCICIO 8
  * Implementa una función insertar(Q, pos, x) que inserte un elemento en la cola Q
  * en la posicion pos. La cola debe quedar como estaba (salvo por el nuevo elemento)
  *
  * @author Miguel Ángel Campos Cubillas
  */

  #include <iostream>
  #include <queue>
  #include <stack>

  using namespace std;

  template <class T>
  void insertar(queue<T> &cola, const int pos, const T elemento){
    queue<T> aux;

    for(int i=cola.size(); i>0; --i){
      aux.push(cola.front());
      cola.pop();
      if(i == pos)
        aux.push(elemento);
    }

    while (!aux.empty()){
      cola.push(aux.front());
      aux.pop();
    }
  }

  template <class T>
  void imprime_cola(queue<T> cola){
    stack<T> aux;
    while(!cola.empty()){
      aux.push(cola.front());
      cola.pop();
    }

    while(!aux.empty()){
      cout << aux.top() << " ";
      aux.pop();
    }
  }

  int main(int argc, char *argv[]){
    queue<int> cola;
    int elemento;
    int posicion;

    cout << "Introduce los elementos, utiliza '-1' para finalizar: " << endl;
    cin >> elemento;

    while(elemento != -1){
      cola.push(elemento);
      cin >> elemento;
    }

    cin.get();
    cout << "Pulsa una tecla para continuar...";
    cin.get();

    cout << "Cola Original => ";
    imprime_cola(cola);
    cout << endl;

    cout << "Pulsa una tecla para continuar...";
    cin.get();

    cout << "Indica un elemento a añadir => ";
    cin >> elemento;
    cout << endl;

    cout << "Indica la posición de la cola en la que introducir el elemento (tomando como referencia el tope de cola) => ";
    cin >> posicion;

    insertar(cola,posicion,elemento);

    cout << "Cola Modificada => ";
    imprime_cola(cola);
    cout << endl;

    return (0);
  }
