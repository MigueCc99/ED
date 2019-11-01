#include <iostream>
using namespace std;

template <class T>
class Vector_Dinamico
{
private:
    /**
 *  @page repVector_Dinamico Rep del TDA Vector_Dinamico
 *  @section invVector_Dinamico Invariante de la representación
 *  El invariante es \e rep.nelementos >= 0
 *                   \e rep.datos apunta a una zona de memoria con capacidad para albergar nelementos de tipo T
 * *  @section faVector_Dinamico Función de abstracción
 *  Un objeto válido @e rep del TDA Vector_Dinamico representa al valor
 *  {rep.datos[0], rep.datos[1], ... , rep.datos[nelementos-1}
 **/
    T *datos;
    int nelementos;

public:
    Vector_Dinamico(int n)
    {
        assert(n >= 0);
        if (n > 0)
            datos = new T[n];
        nelementos = n;
    }

    Vector_Dinamico(const Vector_Dinamico &original)
    {
        nelementos = original.nelementos;
        if (nelementos > 0)
        {
            datos = new T[nelementos];
            for (int i = 0; i < nelementos; i++)
                datos[i] = original.datos[i];
        }
        else
            nelementos = 0;
    }

    ~Vector_Dinamico()
    {
        if (nelementos > 0)
            delete[] datos;
    }

    int size() const
    {
        return nelementos;
    }

    void resize(int n)
    {
        assert(n >= 0);
        if (n != nelementos)
        {
            if (n != 0)
            {
                T *nuevos_datos = new T[n];
                if (nelementos > 0)
                {
                    int minimo = n < nelementos ? n : nelementos;
                    for (int i = 0; i < minimo; i++)
                        nuevos_datos[i] = datos[i];
                    delete[] datos;
                }
                nelementos = n;
                datos = nuevos_datos;
            }
            else
            { //Si n==0
                if (nelementos > 0)
                    delete[] datos;
                datos = 0;
                nelementos = 0;
            }
        }
    }

    T& operator[](const int i)
    {
        assert(i >= 0 && i < nelementos);
        return datos[i];
    }

    const T& operator[](const int i) const
    {
        assert(i >= 0 && i < nelementos);
        return datos[i];
    }

    Vector_Dinamico& operator=(const Vector_Dinamico &original)
    {
        if (this != &original)
            if (nelementos > 0)
                delete[] datos;
        nelementos = original.nelementos;
        if (nelementos > 0)
        {
            datos = new T[nelementos];
            for (int i = 0; i < nelementos; i++)
                datos[i] = original.datos[i];
        }
        return *this;
    }

    void aniadeElemento(const T &elemento)
    {
        int pos = nelementos;
        resize(nelementos + 1);
        *this[pos];
    }
};

int main(int argc, char *argv[])
{
    Vector_Dinamico<int> vector(2);

    vector[0] = 1;
    vector[1] = 2;

    for (int i = 0; i < vector.size(); i++)
        cout << "Elemento " << i << " de " << vector.size() << " elementos es: " << vector[i] << endl;

    return 0;
}