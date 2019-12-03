/*
 * Ejercicio 10
 * Implementa una función lis<l> mezclar(const list<l> &l1, const list<l> &l2)
 * que dadas dos listas ordenadas l1 y l2 devuelva una lista ordenada mezclando
 * las dos listas.
*/

#include <iostream>
#include <list>

using namespace std;

template <class T>
list<T> merge_list(list<T> list1, list<T> list2){
  list<T> list_result;
  list<T>::iterator it1 = list1.begin();
  list<T>::iterator it2 = list2.begin();

  while(it1 != list1.end() && it2 != list2.end()){
    if(*it1 <= *it2){
      lista_resultante.push_back(*it1);
      ++it1;
    }
    else{
      lista_resultante.push_back(*it2);
      ++it2;
    }
  }

  while(it1 != lista1.end()){
    lista_resultante.push_back(*it1);
    ++it1;
  }

  while(it2 != lista2.end()){
    lista_resultante.push_back(*it2);
    ++it2;
  }

	return lista_resultante;
}

int main(){

	list<int>lista1,lista2, lista_resultante;

	lista1.push_back(1);
	lista1.push_back(2);
	lista1.push_back(3);
	lista1.push_back(4);
	lista1.push_back(5);
	lista1.push_back(6);
	lista1.push_back(7);

	lista2.push_back(2);
	lista2.push_back(5);
	lista2.push_back(6);
	lista2.push_back(6);
	lista2.push_back(9);
	lista2.push_back(1);
	lista2.push_back(2);

  lista_resultante = merge_list(lista1, lista2);

  cout << "Lista 1: ";
  for(list<int>::iterator it = lista1.begin(); it != lista1.end(); ++it)
    cout << (*it) << " ";
  cout << endl;

  cout << "Lista 2: ";
  for(list<int>::iterator it = lista2.begin(); it != lista2.end(); ++it)
    cout << (*it) << " ";
  cout << endl;

  cout << "Lista mezclada y ordenada: ";
  for(list<int>::iterator it = lista_resultante.begin(); it != lista_resultante.end(); ++it)
    cout << (*it) << " ";
  cout << endl;
}
