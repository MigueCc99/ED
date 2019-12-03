/*
 * Ejercicio 6
 * Implementa una función que, dada una lista l de tipo T y un elemento x de
 * tipo T, elimine el elemento x de todas las posiciones en las que aparezca en
 * l. Por ejemplo: si x = 1 y l = (2,1,1,1,1,5,3) el resultado debería ser
 * (2,5,3)
*/

#include <iostream>
#include <list>

using namespace std;

template <class T>
void elimina_x(list<T> &list, int x){
  for(list<T>::iterator it = list.begin(); it != list.end(); ++it)
    if((*it) == x)
      it = list.erase(it);
}

int main(){
  list<int> lista_int;

  // tomamos el ejemplo
  lista_int.push_back(2);
  lista_int.push_back(1);
  lista_int.push_back(1);
  lista_int.push_back(1);
  lista_int.push_back(1);
  lista_int.push_back(5);
  lista_int.push_back(3);

  cout << "Lista Original: ";
  for(list<int>::iterator it = lista_int.begin(); it != lista_int.end(); ++it)
    cout << (*it) << " ";
  cout << endl;

  elimina_elemento(lista,1);

  cout << "Lista Final ";
  for(list<int>::iterator it = lista_int.begin(); it != lista.end(); ++it)
    cout << (*it) << " ";
  cout << endl;

  return 0;
}
