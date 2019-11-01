#include <iostream>
#include "vector_dinamico.h"
using namespace std;

int main (int argc, char *argv[]){
    Vector_Dinamico <int> vector(10);

    vector[0] = 1;
    vector[1] = 2;

    for (int i = 0; i < vector.size(); i++)
        cout << "Elemento " << i << " de " << vector.size() << " elementos es: " << vector[i] << endl;

    return 0;

}