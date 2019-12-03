/**
  * EJERCICIO 11
  * Implementa una cola con prioridad que contenga strings y de la que salgan primero las cadenas
  * de caracteres más largas y en caso de igualdad salgan por orden alfabético.
  *
  * @author Miguel Ángel Campos Cubillas
  */
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct prioridad{
  bool operator() (string a, string b){
    if (a.length() == b.length())
      return (a > b);
    return (a.length() > b.length());
  }
};

int main(){
  priority_queue<string, vector<string>, prioridad > pq;

  pq.push("Eden Hazard");
  pq.push("Pirlo");
	pq.push("Cristiano Ronaldo");
	pq.push("Sergio Ramos");
	pq.push("Iniesta");
  pq.push("Mirlo");

  cout << "PRIORITY_QUEUE" << endl;

  while (!pq.empty()) {
    cout << pq.top() << endl;
    pq.pop();
  }
  cout << endl;

  return (0);
}
