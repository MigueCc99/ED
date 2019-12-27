/**
  * @file instrucciones.h
  * @brief Fichero cabecera del TDA Instrucciones
  * 
  */

#ifndef _INSTRUCCIONES_H_
#define _INSTRUCCIONES_H_

#include <iostream>
#include <string>
#include "arbolbinario.h"
#include "acciones.h"
using namespace std;

class instrucciones{
private:
  ArbolBinario<string> datos;
  static acciones &acc;
public:
  friend ostream &operator<<(ostream &os, const instrucciones &instrucciones);  // recorrer el arbol binario en postorden

};

#endif /* _INSTRUCCIONES_H_ */