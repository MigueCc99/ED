/**
  * EJERCICIO 5
  * Implementa un TDA pila utilizando como representación dos colas
  * 
  * @author Miguel Ángel Campos Cubillas
  */

#include <iostream> 
#include <queue>

using namespace std;

template <class T>
class Pila{
private:
	queue<T> cola;
	queue<T> cola_aux;
public:	

	bool empty() const{
		return cola.empty();
	}
	
	int size() const{
		return cola.size();
	}
	
	T& top(){
		return cola.back();
	}
	
	const T& top() const{
		return cola.back();
	}
	
	void push(const T &elemento){
		cola.push(elemento);
	}
	
	void pop(){
		while(cola.size() != 1){
			cola_aux.push(cola.front());
			cola.pop();
		}
		cola.pop();
		while(!cola_aux.empty()){
			cola.push(cola_aux.front());
			cola_aux.pop();
		}
	}
};

int main(int argc, char *argv[]){
	Pila<int> pila;
	int elemento, num_elementos, contador = 0;

    cout << "¿Cuántos elementos quieres añadir?" << endl << "Numero de elementos a añadir: ";
    cin >> num_elementos;

    cout << "\nIntroduce " << num_elementos << " elementos\n";
    cin >> elemento;
    while (contador < num_elementos){
        pila.push(elemento);
        cin >> elemento;
        contador++;
    }
    
    while (!pila.empty()){
		cout << "top() " << pila.top() << endl;
		cout << "size() " << pila.size() << endl;

		pila.pop();
	}
	
	return 0;
}
