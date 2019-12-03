/*
 * Ejercicio 9
 * Resuelve el problema anterior pero sobre la lista pasada por referencia.
*/

#include <iostream>
#include <list>

using namespace std;

template <class T>
lista<T> invertir_lista(list<T> &list){

  list<T>::iterator izda = list.begin();
  list<T>::iterator dcha = --list.end();

  int tam = list.size();
  int aux;

  for(int i = 0; i < tam/2; i++){
    aux = (*izda);
    (*izda) = (*dcha);
    (*dcha) = aux;
    --dcha;
    ++izda;
  }
}

int main(void){

  list<int> lista_original;
  list<int> lista_invertida;

  lista_original.push_back(1);
  lista_original.push_back(2);
  lista_original.push_back(3);
  lista_original.push_back(4);
  lista_original.push_back(5);
  lista_original.push_back(6);

  lista_invertida = invertir_lista(lista_original);

  cout << "Lista inicial: ";
  for(list<int>::iterator it = lista_original.begin(); it != lista_original.end(); ++it)
    cout << (*it) << " ";
  cout << endl;

  cout << "Lista Invertida: ";
  for(list<int>::iterator it = lista_invertida.begin(); it != lista_invertida.end(); ++it)
    cout << (*it) << " ";
  cout << endl;

}
