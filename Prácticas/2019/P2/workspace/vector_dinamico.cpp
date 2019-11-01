//  vector_dinamico.cpp

#include <cassert>
#include "vector_dinamico.h"

template <class T>
Vector_Dinamico::Vector_Dinamico(int n)
{
    assert(n >= 0);
    if (n > 0)
        datos = new T[n];
    nelementos = n;
}

template <class T>
Vector_Dinamico::Vector_Dinamico(const Vector_Dinamico &original)
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

template <class T>
Vector_Dinamico::~Vector_Dinamico()
{
    if (nelementos > 0)
        delete[] datos;
}

template <class T>
int Vector_Dinamico::size() const
{
    return nelementos;
}

template <class T>
void Vector_Dinamico::resize(int n)
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

template <class T>
T &Vector_Dinamico::operator[](const int i)
{
    assert(i >= 0 && i < nelementos);
    return datos[i];
}

template <class T>
const T &Vector_Dinamico::operator[](const int i) const
{
    assert(i >= 0 && i < nelementos);
    return datos[i];
}

template <class T>
Vector_Dinamico &Vector_Dinamico::operator=(const Vector_Dinamico &original)
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

template <class T>
void aniadeElemento(const T &elemento){
    int pos = nelementos;
    resize(nelementos+1);
    *this[pos];
}
