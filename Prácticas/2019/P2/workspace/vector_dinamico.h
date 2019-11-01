#ifndef VectorDinamico_h
#define VectorDinamico_h

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
    Vector_Dinamico<T>(int n = 0);
    Vector_Dinamico<T>(const Vector_Dinamico &original);
    ~Vector_Dinamico<T>();
    int size() const;
    void aniadeElemento(const T &elemento);
    void resize(int n);
    T &operator[](const int i);
    const T &operator[](const int i) const;
    Vector_Dinamico<T> &operator=(const Vector_Dinamico<T> &original);
};

#endif // VectorDinamico_h