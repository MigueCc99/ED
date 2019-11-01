#ifndef _INGREDIENTES_H
#define _INGREDIENTES_H

#include "vd.h"
#include "ingrediente.h"

class Ingredientes{
private:
    /**
 *  @page repIngrediente Rep del TDA Ingredientes
 *  @section invIngredientes Invariante de la representación
 *  El invariante es \e numIngredientes >0
 * *  @section faIngrediente Función de abstracción
 *  Un objeto válido @e rep del TDA Ingrediente representa al valor
 *  {Nombre, Calorias, Hidratos, Proteinas, Grasas, Fibras, Tipo}
 **/

VD<ingrediente> datos;
};

#endif "_INGREDIENTES_H"