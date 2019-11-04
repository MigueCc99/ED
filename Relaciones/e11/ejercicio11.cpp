/**
  * EJERCICIO 11
  * Implementa una cola con prioridad de tipo struct con (apellidos, nombre, prioridad)
  * de forma que los datos salgan de acuerdo a ese tercer campo de prioridad.
  *
  * @author Miguel Ángel Campos Cubillas
  */
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef struct{
  string apellidos;
  string nombre;
  int prioridad;
}ELEMENTO;

struct prioridad{
  bool operator() (ELEMENTO a, ELEMENTO b){
    return (a.prioridad > b.prioridad);
  }
};

int main(){
  priority_queue<ELEMENTO, vector<ELEMENTO>, prioridad > pq;
  ELEMENTO e1 = {"Expósito Martínez","Martín",1};
  ELEMENTO e2 = {"Aveiro Campos","Julia",5};
  ELEMENTO e3 = {"García Gonzalez","Natalia",2};
  ELEMENTO e4 = {"Nadal Martínez","Carlos",3};
  ELEMENTO e5 = {"López López","Teresa",4};
  pq.push(e1);
	pq.push(e2);
	pq.push(e3);
	pq.push(e4);
	pq.push(e5);

  cout << "PRIORITY_QUEUE" << endl;

  while (!pq.empty()) {
    cout << pq.top().apellidos << " " << pq.top().nombre << endl;
    pq.pop();
  }
  cout << endl;
}
