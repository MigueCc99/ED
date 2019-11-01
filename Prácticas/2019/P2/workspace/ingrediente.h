#ifndef _INGREDIENTE_H
#define _INGREDIENTE_H

#include <String>

enum Tipo{VERDURA, CARNE, PESCADO};

class Ingrediente{
private:
/**
 *  @page repIngrediente Rep del TDA Ingrediente
 *  @section invIngrediente Invariante de la representación
 *  El invariante es \e 0 <= rep.hidratos <= 100
 *                      0 <= rep.proteinas <= 100
 *                      0 <= rep.grasas <= 100
 *                      0 <= rep.fibras <= 100
 *                      Tipo = {Verdura, Carne, Pescado}
 * *  @section faIngrediente Función de abstracción
 *  Un objeto válido @e rep del TDA Ingrediente representa al valor
 *  {Nombre, Calorias, Hidratos, Proteinas, Grasas, Fibras, Tipo}
 **/

String nombre;      /**< nombre */
float calorias;     /**< calorias */
float hidratos;     /**< hidratos */
float proteinas;    /**< proteinas */
float grasas;       /**< grasas */
float fibras;       /**< fibras */
Tipo tipo;          /**< tipo */

};

#endif "_INGREDIENTE_H"