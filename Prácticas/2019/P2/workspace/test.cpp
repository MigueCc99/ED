#include <iostream>
#include "assert.h"

using namespace std;

template <class T>
class Vector_Dinamico{
private:

    T *datos;       /**< datos */
    int nelementos; /**< nelementos */
    int reservados;

public:
    
    Vector_Dinamico(int n = 0)
    {
        assert(n >= 0);
        if (n > 0)
            datos = new T[n];
        reservados = n;
    }

    ~Vector_Dinamico()
    {
        if (this->reservados > 0)
            delete[] this->datos;
    }

    Vector_Dinamico(const Vector_Dinamico &original)
    {
        this->reservados = original.reservados;
        this->numelementos = original.numelementos;
        if (reservados > 0)
        {
            datos = new T[this->reservados];
            for (int i = 0; i < this->numelementos; i++)
                this->datos[i] = original.datos[i];
        }
        else
            datos = 0;
    }

    int size() const
    {
        return this->reservados;
    }

    int get_nelementos() const
    {
        return this->nelementos;
    }

    T& operator[](int i)
    {
        assert(0 <= i && i < nelementos);
        return datos[i];
    }

    const T& operator[](int i) const
    {
        assert(0 <= i && i < nelementos);
        return datos[i];
    }

    void aniadeElemento(const T elemento){
        if (get_nelementos()==size())
            resize(size()+10);
        this[get_nelementos()-1] = elemento;
        this->nelementos++;
    }

    Vector_Dinamico& operator=(const Vector_Dinamico &original)
    {
        if (this != &original)
        {
            if (reservados > 0)
                delete[] this->datos;
            this->reservados = original.reservados;
            this->nelementos = original.nelementos;
            this->datos = new T[this->reservados];
            for (int i; i < this->nelementos; i++)
                this->datos[i] = original.datos[i];
        }
        return *this;
    }

    void resize(int n)
    {
        assert(n >= 0);
        if (n != this->reservados)
        {
            if (n != 0)
            {
                T *nuevos_datos;
                nuevos_datos = new T[n];
                if (this->nelementos > 0)
                {
                    int minimo;
                    minimo = this->nelementos < n ? nelementos : n;
                    for (int i = 0; i < minimo; ++i)
                        nuevos_datos[i] = datos[i];
                    delete[] this->datos;
                }
                this->nelementos = n;
                this->datos = nuevos_datos;
            }
            else
            {
                if (this->nelementos > 0)
                    delete[] this->datos;
                this->datos = 0;
                this->nelementos = 0;
            }
        }
    }
};

int main (int argc, char *argv[]){
    Vector_Dinamico<int> vector(10);

    vector.aniadeElemento(1);
    vector.aniadeElemento(2);

    for (int i = 0; i < vector.get_nelementos(); i++)
        cout << "Elemento " << i << " de " << vector.get_nelementos() << " elementos es: " << vector[i] << endl;

    return 0;
}

