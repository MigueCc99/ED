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
    int reservados;

public:
    Vector_Dinamico(int n)
    {
        assert(n >= 0);
        if (n > 0)
            datos = new T[n];
        reservados = n;
        nelementos = 0;
    }

    Vector_Dinamico(const Vector_Dinamico &original)
    {
        nelementos = original.nelementos;
        reservados = original.reservados;
        if (reservados > 0)
        {
            datos = new T[reservados];
            for (int i = 0; i < nelementos; i++)
                datos[i] = original.datos[i];
        }
        else
            reservados = 0;
    }

    ~Vector_Dinamico()
    {
        if (reservados > 0)
            delete[] datos;
    }

    int size() const
    {
        return reservados;
    }

    void resize(int n)
    {
        assert(n >= 0);
        if (n != reservados)
        {
            if (n != 0)
            {
                T *nuevos_datos = new T[n];
                if (reservados > 0)
                {
                    int minimo = n < nelementos ? n : nelementos;
                    nelementos = minimo;
                    for (int i = 0; i < minimo; i++)
                        nuevos_datos[i] = datos[i];
                    delete[] datos;
                }
                reservados = n;
                datos = nuevos_datos;
            }
            else
            { //Si n==0
                if (reservados > 0)
                    delete[] datos;
                datos = 0;
                reservados = 0;
                nelementos = 0;
            }
        }
    }

    T& operator[](const int i)
    {
        assert(i >= 0 && i < reservados);
        return datos[i];
    }

    const T& operator[](const int i) const
    {
        assert(i >= 0 && i < reservados);
        return datos[i];
    }

    Vector_Dinamico& operator=(const Vector_Dinamico &original)
    {
        if (this != &original)
            if (reservados > 0)
                delete[] datos;
        reservados = original.reservados;
        nelementos = original.nelementos;
        if (reservados > 0)
        {
            datos = new T[reservados];
            for (int i = 0; i < nelementos; i++)
                datos[i] = original.datos[i];
        }
        return *this;
    }

    void aniadeElemento(const T &elemento)
    {
        if(nelementos < reservados){
            datos[nelementos] = elemento;
            nelementos++;
        }
        else{
            resize(reservados+1);
            datos[nelementos] = elemento;
            nelementos++;
        }
    }
};

int main(int argc, char *argv[])
{
    Vector_Dinamico<int> vector(0);

    vector.aniadeElemento(19);
    vector.aniadeElemento(9);
    vector.aniadeElemento(7);
    vector.aniadeElemento(13);
    vector.aniadeElemento(12);

    for (int i = 0; i < vector.size(); i++)
        cout << "Elemento " << i << " de " << vector.size() << " elementos es: " << vector[i] << endl;

    return 0;
}