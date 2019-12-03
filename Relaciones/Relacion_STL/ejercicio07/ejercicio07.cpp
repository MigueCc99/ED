/*
 * Ejercicio 7
 * Implementa una función elimina_duplicados(list<T> &l) que elimine los
 * elementos duplicados (sin ordenar previamente la lista).
*/

#include <iostream>
#include <list>

using namespace std;

template <class T>
void elimina_duplicados(list<T> &list){

  list<T>::iterator it_fin;

  for(list<T>::iterator it_ini = list.begin(); it_ini != list.end(); ++it_ini){
    it_fin = it_ini;
    ++it_fin;

    while(it_fin != list.end()){
      if((*it_ini) == (*it_fin))
        it_fin = list.erase(it_fin);
      else
        ++it_fin;
    }
  }
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

  elimina_duplicadosç(lista);

  cout << "Lista Final ";
  for(list<int>::iterator it = lista_int.begin(); it != lista.end(); ++it)
    cout << (*it) << " ";
  cout << endl;

  return 0;
}
