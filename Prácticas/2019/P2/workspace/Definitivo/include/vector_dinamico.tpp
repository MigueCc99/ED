#include <cassert>

template <class T>
Vector_Dinamico<T>::Vector_Dinamico(){
    Vector_Dinamico(0);
}

template <class T>
Vector_Dinamico<T>::Vector_Dinamico(int n){
    assert(n >= 0);
    if (n > 0)
        datos = new T[n];
        reservados = n;
        nelementos = 0;
}
template <class T>
Vector_Dinamico<T>::Vector_Dinamico(const Vector_Dinamico<T> &original){
    nelementos = original.nelementos;
    reservados = original.reservados;
    if (reservados > 0){
        datos = new T[reservados];
        for (int i = 0; i < nelementos; i++)
            datos[i] = original.datos[i];
    }
    else
        reservados = 0;
}

template <class T>
Vector_Dinamico<T>::~Vector_Dinamico(){
    if (reservados > 0)
        delete[] datos;
}

template <class T>
int Vector_Dinamico<T>::size() const{
    return reservados;
}

template <class T>
int Vector_Dinamico<T>::getNumElementos() const{
    return nelementos;
}

template <class T>
void Vector_Dinamico<T>::resize(int n){
    assert(n >= 0);
    if (n != reservados){
        if (n != 0){
            T *nuevos_datos = new T[n];
            if (reservados > 0){
                int minimo = n < nelementos ? n : nelementos;
                nelementos = minimo;
                for (int i = 0; i < minimo; i++)
                    nuevos_datos[i] = datos[i];
                delete[] datos;
            }
            reservados = n;
            datos = nuevos_datos;
        }
        else{ //Si n==0
            if (reservados > 0)
                delete[] datos;
            datos = 0;
            reservados = 0;
            nelementos = 0;
        }
    }
}

template <class T>
T& Vector_Dinamico<T> ::operator[](const int i){
    assert(i >= 0 && i < reservados);
    return datos[i];
}

template <class T>
const T &Vector_Dinamico<T>::operator[](const int i) const{
    assert(i >= 0 && i < reservados);
    return datos[i];
}

template <class T>
Vector_Dinamico<T>& Vector_Dinamico<T>::operator = (const Vector_Dinamico<T> &original){
    if (this != &original)
        if (reservados > 0)
            delete[] datos;
    reservados = original.reservados;
    nelementos = original.nelementos;
    if (reservados > 0){
        datos = new T[reservados];
        for (int i = 0; i < nelementos; i++)
            datos[i] = original.datos[i];
    }
    return *this;
}

template <class T>
void Vector_Dinamico<T>::aniadeElemento(const T &elemento){
    if (nelementos < reservados){
        datos[nelementos] = elemento;
        nelementos++;
    }
    else{
        resize(reservados + 1);
        datos[nelementos] = elemento;
        nelementos++;
    }
}

template <class T>
void Vector_Dinamico<T>::borrarElemento(const int posicion){
    if (posicion > 0 && posicion < reservados){
        for (int i = posicion; i < nelementos; i++)
            modificaElemento(i, datos[i + 1]);
        resize(nelementos - 1);
    }
}

template <class T>
void Vector_Dinamico<T>::modificaElemento(const int posicion, const T &elemento){
    datos[posicion] = elemento;
}
