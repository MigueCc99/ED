/*
 * Ejercicio 12
 * Implementa una función bool contenida(const list<T> &l1, const list<T> &l2)
 * a la que se le pases dos listas y compruebe si la lista l1 está contenida en
 * l2 (si los elementos aparecen en la otra y en el mismo orden).
*/

#include <iostream>
#include <list>

using namespace std;

template <class T>
bool contenida(list<T> &list1, list<T> &list2){
  bool sub_lista = false;

  list<T>::iterator it1 = list1.begin();

  for(list<T>::iterator it2 = list2.begin(); it2 != list2.end(); ++it2){
    it1 = list1.begin();
    if(*it2 == *it1){
      sub_lista = true;
      while(sub_lista && it1 != list1.end()){
        if(*it2 != *it1)
          sub_lista = false;
        else ++it1, ++it2;
      }
    }
  }
  return(sub_lista);
}

int main(){
  list<int>lista1,lista2;

  lista1.push_back(1);
  lista1.push_back(2);
  lista1.push_back(3);
  lista1.push_back(4);
  lista1.push_back(5);

  lista2.push_back(1);
  lista2.push_back(1);
  lista2.push_back(2);
  lista2.push_back(3);
  lista2.push_back(4);
  lista2.push_back(5);
  lista2.push_back(9);

  cout << "Lista 1: ";
  for(list<int>::iterator it = lista1.begin(); it != lista1.end(); ++it)
    cout << (*it) << " ";
  cout << endl;

  funcion(lista,5);

  cout << "Lista 2: ";
  for(list<int>::iterator it = lista2.begin(); it != lista2.end(); ++it)
    cout << (*it) << " ";
  cout << endl;

  if (contenida(lista1,lista2))
		cout << "Lista 1 esta contenida en lista 2 " << endl;
	else
		cout << "Lista 1 NO esta contenida en lista 2" << endl;

  return 0;

}
