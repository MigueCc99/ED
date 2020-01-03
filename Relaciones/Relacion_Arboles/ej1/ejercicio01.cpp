/*
 * Ejercicio 1
 * Escribe una función que determine cual es la hoja más profunda de un árbol binario
*/

#include <iostream>
#include "bintree.h"

using namespace std;

template <class T>
typename bintree<T>::node hoja_profunda(const bintree<T> &btree){
    bintree<T>::node hoja_p;
    bintree<T>::node izda;
    bintree<T>::node dcha;
    bintree<T>::node aux;
    int contador_prof = 0;
    int profundidad_max = 0;
    for (bintree<int>::const_level_iterator it= btree.begin_level(); it!=btree.end_level(); ++it){
        izda = (*it).left();
        dcha = (*it).right();
        if(izda.null() && dcha.null()){     // *it es hoja 
            aux = *it;
            while(aux != btree.root()){
                contador_prof++;
                aux = aux.parent();
            }
        }
        if(contador_prof > profundidad_max){
            hoja_p = *it;
            profundidad_max = contador_prof;
            contador_prof = 0;
        }
    }
    return hoja_p;
} 

int main(){
  // Creamos el ?bol: 
  //        7
  //     /    \
  //   1        9
  //  /  \      /
  // 6    8    5
  //       \
  //       4
  bintree<int> btree(7);
  
  btree.insert_left(btree.root(), 1);
  btree.insert_right(btree.root(), 9);
  btree.insert_left(btree.root().left(), 6);
  btree.insert_right(btree.root().left(), 8);
  btree.insert_right(btree.root().left().right(), 4);
  btree.insert_left(btree.root().right(), 5);

  cout << "Preorden:";
  for (bintree<int>::preorder_iterator i= btree.begin_preorder(); i!=btree.end_preorder(); ++i)
    cout << *i << " ";
  cout << endl;

  bintree<int>::node hoja_p = hoja_profunda(btree);

  cout << "La hoja más profunda de el arbol es: " << *hoja_p << endl;

  return 0;
}