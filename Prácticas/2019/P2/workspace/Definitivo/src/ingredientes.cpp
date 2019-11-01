#include "ingredientes.h"

Ingredientes::Ingredientes() : datos(0) {}

void Ingredientes::insertarIngrediente(const Ingrediente &ingrediente){
    datos.aniadeElemento(ingrediente);
    ordenaPorNombre();
}

void Ingredientes::borrarIngrediente(const int nroIngrediente){
    datos.borrarElemento(nroIngrediente);
}

void Ingredientes::borrarIngredienteXNombre(const string &nombre){
    bool encontrado = false;
    for (int i = 0; i < getNumIngredientes() && !encontrado; i++){
        if (getIngrediente(i).getNombre() == nombre){
            borrarIngrediente(i);
            encontrado = true;
        }
    }
}

void Ingredientes::modificaIngrediente(const int i, const Ingrediente &ingrediente){
    datos.modificaElemento(i, ingrediente);
}

Ingrediente Ingredientes::getIngrediente(const int i){
    return datos[i];
}

Ingrediente Ingredientes::get(const string &nombre){
    Ingrediente aux;
    for (int i = 0; i < getNumIngredientes(); i++)
        if (getIngrediente(i).getNombre() == nombre)
                aux = getIngrediente(i);
    return aux;
}

const int Ingredientes::getNumIngredientes() const{
    return this->datos.getNumElementos();
}

string Ingredientes::getInformacion(const string nombre){
    Ingrediente aux = get(nombre);
    string info;
    info += aux.getNombre() + '\n';
    info += aux.getCalorias() + '\n';
    info += aux.getHidratos() + '\n';
    info += aux.getProteinas() + '\n';
    info += aux.getGrasas() + '\n';
    info += aux.getFibras() + '\n';
    info += aux.getTipo() + '\n';
    return info;
}

Vector_Dinamico<string> Ingredientes::getTipos(){
    Vector_Dinamico<string> tipos;
    bool encontrado = false;
    for (int i = 0; i < getNumIngredientes(); i++){
        for (int j = 0; j < tipos.getNumElementos() && !encontrado; j++){
            if (tipos[j] == datos[i].getTipo())
                encontrado = true;
        }
        if (!encontrado){
            if (!datos[i].getTipo().empty())
                tipos.aniadeElemento(datos[i].getTipo());
        }else{encontrado = false;}
    }
    return tipos;
}

Ingredientes Ingredientes::getIngredientesTipo(const string tipo){
    Ingredientes ingredientesTipo;
    for (int i = 0; i < getNumIngredientes(); i++)
        if (getIngrediente(i).getTipo().compare(tipo) == 1)
            ingredientesTipo.insertarIngrediente(getIngrediente(i));
    return ingredientesTipo;
}

Ingrediente& Ingredientes::operator[](const int i){
    return datos[i];
}

const Ingrediente& Ingredientes::operator[](const int i) const{
    return datos[i];
}

void Ingredientes::ordenaPorNombre(){
    Ingrediente aux;
    for (int i = 1; i < getNumIngredientes(); i++)
        for (int j = 0; j < getNumIngredientes() - 1; j++)
            if (getIngrediente(j).getNombre() > getIngrediente(j + 1).getNombre()){
                aux = getIngrediente(j);
                modificaIngrediente(j, getIngrediente(j + 1));
                modificaIngrediente(j + 1, aux);
            }
}

Ingredientes Ingredientes::ordenaPorTipo(){
    Ingredientes ordenadosXTipo = *this;
    Ingrediente aux;
    for (int i = 1; i < ordenadosXTipo.getNumIngredientes(); i++)
        for (int j = 0; j < ordenadosXTipo.getNumIngredientes() - 1; j++)
            if (ordenadosXTipo.getIngrediente(j).getTipo() > ordenadosXTipo.getIngrediente(j + 1).getTipo()){
                aux = ordenadosXTipo.getIngrediente(j);
                ordenadosXTipo.modificaIngrediente(j, getIngrediente(j + 1));
                ordenadosXTipo.modificaIngrediente(j + 1, aux);
            }
    return ordenadosXTipo;
}

void Ingredientes::imprimirPorTipo(ostream &os){
    Ingredientes aux = ordenaPorTipo();
    os << aux;
    //ordenaPorTipo();
    //os << *this;
}

ostream &operator<<(ostream &os, const Ingredientes &ingredientes){
    for (int i = 0; i < ingredientes.getNumIngredientes(); i++)
    {
        os << ingredientes[i];
        os << endl;
    }
    return os;
}

istream &operator>>(istream &is, Ingredientes &ingredientes){
    Ingrediente aux;
    string linea;
    getline(is, linea);
    while (is.peek() != EOF){
        is >> aux;
        ingredientes.insertarIngrediente(aux);
    }
    //ingredientes.ordenaPorNombre();
    return is;
}
