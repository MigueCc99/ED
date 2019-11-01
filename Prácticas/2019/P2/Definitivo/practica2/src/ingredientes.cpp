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
        for (int j = i; j < ordenadosXTipo.getNumIngredientes() - 1; j++)
            if (ordenadosXTipo.getIngrediente(i).getTipo() > ordenadosXTipo.getIngrediente(j + 1).getTipo()){
                aux = ordenadosXTipo.getIngrediente(i);
                ordenadosXTipo.modificaIngrediente(i, getIngrediente(j + 1));
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

void Ingredientes::getEstadistica(const string tipo){
Ingredientes ingredientes_tipo = getIngredientesTipo(tipo);
float prom_cal, prom_hid, prom_pro, prom_gras, prom_fib = 0;

for(int i=0; i<ingredientes_tipo.getNumIngredientes(); i++){
    prom_cal += ingredientes_tipo.getIngrediente(i).getCalorias();
    prom_hid += ingredientes_tipo.getIngrediente(i).getHidratos();
    prom_pro += ingredientes_tipo.getIngrediente(i).getProteinas();
    prom_gras += ingredientes_tipo.getIngrediente(i).getGrasas();
    prom_fib += ingredientes_tipo.getIngrediente(i).getFibras();
}

prom_cal = prom_cal/ingredientes_tipo.getNumIngredientes();
prom_hid = prom_hid/ingredientes_tipo.getNumIngredientes();
prom_pro = prom_pro/ingredientes_tipo.getNumIngredientes();
prom_gras = prom_gras/ingredientes_tipo.getNumIngredientes();
prom_fib = prom_fib/ingredientes_tipo.getNumIngredientes();

cout << "Estadística____________________________" << endl;
cout << "Tipo de alimento " << tipo << endl;
cout << "Promedio +-Desviación" << endl;
cout << "Calorías" << "\tHidratos de Carb." << "\tProteínas" << "\tGrasas" << "\tFibra" << endl;
cout << prom_cal << "\t\t" << prom_hid << "\t\t" << prom_pro << "\t\t" << prom_gras << "\t\t" << prom_fib << endl;


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



