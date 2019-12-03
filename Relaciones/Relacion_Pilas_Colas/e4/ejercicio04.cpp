#include <iostream>
#include <stack>
using namespace std;

/**
  * EJERCICIO 4
  * Implementa un TDA cola utilizando como representación dos pilas
  * 
  * @author Miguel Ángel Campos Cubillas
  */

template <class T>
class Cola{
private:
    stack<T> pila_back;
    stack<T> pila_front;
public:
    Cola(){}

    Cola(const Cola &cola){
        this->pila_back = cola.pila_back;
        this->pila_front = cola.pila_front;
    }

    Cola& operator=(const Cola &cola){
        if(this != &cola){
            this->pila_back = cola.pila_back;
            this->pila_front = cola.pila_front;   
        }
        return *this;
    }

    void push(T elemento){
        pila_back.push(elemento);
    }

    void pop(){
        while (!pila_back.empty()){
            pila_front.push(pila_back.top());
            pila_back.pop();
        }

        pila_front.pop();

        while (!pila_front.empty()){
            pila_back.push(pila_front.top());
            pila_front.pop();
        }
    }

    T& front(){
        while (!pila_back.empty()){
            pila_front.push(pila_back.top());
            pila_back.pop();
        }

        T *frente = pila_front.pop();

        while (!pila_front.empty()){
            pila_back.push(pila_front.top());
            pila_front.pop();
        }
        return frente;
    }

    T& back(){
        return &pila_front.top();
    }

    bool empty(){
        return pila_back().empty();
    }

    const int size(){
        return pila_back().size();
    }

    bool operator<(const Cola &otra){
        return pila_back < otra.pila_back;
    }

    bool operator==(const Cola &otra){
        return pila_back == otra.pila_back;
    }

    void imprimeCola(){
        while (!pila_back.empty()){
            cout << pila_back.top() << " ";
            pila_front.push(pila_back.top());
            pila_back.pop();
        }
    
        while (!pila_front.empty()){
            pila_back.push(pila_front.top());
            pila_front.pop();
        } 
    }

};

int main(){
    Cola<int> cola;
    Cola<int> cmp_cola;
    int num_elementos = 0;
    int elemento = 0;
    int contador = 0;

    cout << "¿Cuántos elementos quieres añadir?" << endl << "Numero de elementos a añadir: ";
    cin >> num_elementos;

    cout << "\nIntroduce " << num_elementos << " elementos\n";
    cin >> elemento;
    while (contador < num_elementos){
        cola.push(elemento);
        cin >> elemento;
        contador++;
    }

    cout << "Cola original"<< endl;
    cola.imprimeCola();

    cola.pop();

    cout << "\nCola tras el pop" << endl;
    cola.imprimeCola() ;

    Cola<int> cpy_cola(cola);

    cout << "\nCopia cola" << endl;
    cpy_cola.imprimeCola();

    if (cola == cpy_cola)
        cout << "\nSon iguales la copia de la cola y la cola original";
    else
        cout << "\nNo son iguales la copia de la cola y la cola original";

    cout << "\nCreamos una nueva cola" << endl;
    cout << "¿Cuántos elementos quieres añadir?" << endl << "Numero de elementos a añadir: ";
    cin >> num_elementos;

    contador = 0;

    cout << "\nIntroduce " << num_elementos << " elementos\n";
    cin >> elemento;
    while (contador < num_elementos){
        cmp_cola.push(elemento);
        cin >> elemento;
        contador++;
    }

    cout << "\nCola para comparar" << endl;
    cmp_cola.imprimeCola() ; 

    if (cola == cmp_cola)
        cout << "\nSon iguales la nueva cola y la cola original";
    else
        cout << "\nNo son iguales la nueva cola y la cola original";

    if (cola < cmp_cola)
        cout << "\nEs mayor la nueva cola";
    else
        cout << "\nEs mayor la original";

    return 0;
}