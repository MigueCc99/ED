/**
  * EJERCICIO 12
  * Implementa una cola con prioridad que contenga strings y de la que salgan primero las cadenas
  * de caracteres que tengan más vocales y en caso de igualdad salgan por orden alfabético.
  *
  * @author Miguel Ángel Campos Cubillas
  */
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int numVocales (const string c){
  int vocales = 0;
  for (int i=0; i<c.length(); i++)
    if (c[i] == 'a'|| c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u')
      vocales++;
  return vocales;
}

struct prioridad{
  bool operator() (string a, string b){
    if (numVocales(a) == numVocales(b))
      return (a > b);
    return (numVocales(a) < numVocales(b));
  }
};

int main(){
  priority_queue<string, vector<string>, prioridad > pq;

  pq.push("Aaaaaaa");
  pq.push("Iiiiiii");
	pq.push("Cadena");
	pq.push("Bolso");
	pq.push("Trapecio");
  pq.push("Mirlo");

  cout << "PRIORITY_QUEUE" << endl;

  while (!pq.empty()) {
    cout << pq.top() << endl;
    pq.pop();
  }
  cout << endl;

  return (0);
}
