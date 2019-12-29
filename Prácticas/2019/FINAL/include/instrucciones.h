/**
  * @file instrucciones.h
  * @brief Fichero cabecera del TDA Instrucciones
  * 
  */

#ifndef _INSTRUCCIONES_H_
#define _INSTRUCCIONES_H_

#include <iostream>
#include <string>
#include <stack>
#include "arbolbinario.h"
#include "acciones.h"
using namespace std;

class Instrucciones{
private:
  ArbolBinario<string> datos;
public:
  static Acciones acc;

  Instrucciones();

  Instrucciones(ArbolBinario<string> &arbol, Acciones acc);

  friend ostream &operator<<(ostream &os, const Instrucciones &instrucciones);  // recorrer el arbol binario en postorden
  friend istream &operator>>(istream &is, Instrucciones &instrucciones);  // recorrer el arbol binario en postorden

};

#endif /* _INSTRUCCIONES_H_ */