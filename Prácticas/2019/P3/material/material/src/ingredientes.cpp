#include "ingredientes.h"

Ingredientes::Ingredientes() : datos(0), indice_tipo(0) {}

void Ingredientes::insertarIngrediente(const Ingrediente &ingrediente){
    datos.push_back(ingrediente);
    ordenaPorNombre();
    indice_tipo.push_back(getNumIngredientes()-1);
    ordenaPorTipo();
}

void Ingredientes::borrarIngrediente(const int nroIngrediente){
    datos.erase(datos.begin()+nroIngrediente);
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
    datos.insert(datos.begin()+i, ingrediente);
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
    return this->datos.size();
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

vector<string> Ingredientes::getTipos(){
    vector<string> tipos;
    bool encontrado = false;
    for (int i = 0; i < getNumIngredientes(); i++){
        for (int j = 0; j < tipos.size() && !encontrado; j++){
            if (tipos[j] == datos[i].getTipo())
                encontrado = true;
        }
        if (!encontrado){
            if (!datos[i].getTipo().empty())
                tipos.push_back(datos[i].getTipo());
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
    for(int i=1; i < getNumIngredientes()-1; i++){
        for(int j=0; j < getNumIngredientes()-1; j++){
            if(datos[j].getNombre() > datos[j+1].getNombre()){
                aux = datos[j];
                datos[j] = datos[j+1];
                datos[j+1] = aux;
            }
        }
    }
}

void Ingredientes::ordenaPorTipo(){
    int aux;
    for(int i=1; i < getNumIngredientes()-1; i++){
        for(int j=0; j < getNumIngredientes()-1; j++){
            if((getIngrediente(indice_tipo[j]).getTipo() > getIngrediente(indice_tipo[j+1]).getTipo()) && (getIngrediente(indice_tipo[j]).getNombre() > getIngrediente(indice_tipo[j+1]).getNombre())){
                aux = indice_tipo[j];
                indice_tipo[j] = indice_tipo[j+1];
                indice_tipo[j+1] = aux;
            }
        }
    }
}

void Ingredientes::imprimirPorTipo(ostream &os){
    for(int i=0; i<getNumIngredientes(); i++)
        cout << datos[indice_tipo[i]] << endl;
}

void Ingredientes::getEstadistica(const string tipo){
Ingredientes ingredientes_tipo = getIngredientesTipo(tipo);
float prom_cal, prom_hid, prom_pro, prom_gras, prom_fib = 0;
float max_cal, max_hid, max_pro, max_gras, max_fib = 0;
float min_cal, min_hid, min_pro, min_gras, min_fib = 10000000;
string el_max_cal, el_max_hid, el_max_pro, el_max_gras, el_max_fib;
string el_min_cal, el_min_hid, el_min_pro, el_min_gras, el_min_fib;
Ingrediente ingrediente_actual;

for(int i=0; i<ingredientes_tipo.getNumIngredientes(); i++){
    ingrediente_actual = ingredientes_tipo.getIngrediente(i);
    prom_cal += ingrediente_actual.getCalorias();
    prom_hid += ingrediente_actual.getHidratos();
    prom_pro += ingrediente_actual.getProteinas();
    prom_gras += ingrediente_actual.getGrasas();
    prom_fib += ingrediente_actual.getFibras();

    if(ingrediente_actual.getCalorias() >= max_cal){
        max_cal = ingrediente_actual.getCalorias();
        el_max_cal = ingrediente_actual.getNombre();
    }
    
    if(ingrediente_actual.getCalorias() <= min_cal){
        min_cal = ingrediente_actual.getCalorias();
        el_min_cal = ingrediente_actual.getNombre();
    }

    if(ingrediente_actual.getHidratos() >= max_hid){
        max_hid = ingrediente_actual.getHidratos();
        el_max_hid = ingrediente_actual.getNombre();
    }
    
    if(ingrediente_actual.getHidratos() <= min_hid){
        min_hid = ingrediente_actual.getHidratos();
        el_min_hid = ingrediente_actual.getNombre();
    }

    if(ingrediente_actual.getProteinas() >= max_pro){
        max_pro = ingrediente_actual.getProteinas();
        el_max_pro = ingrediente_actual.getNombre();
    }
    
    if (ingrediente_actual.getProteinas() <= min_pro){
        min_pro = ingrediente_actual.getProteinas();
        el_min_pro = ingrediente_actual.getNombre();
    }

    if(ingrediente_actual.getGrasas() >= max_gras){
        max_gras = ingrediente_actual.getGrasas();
        el_max_gras = ingrediente_actual.getNombre();
    }
    
    if(ingrediente_actual.getGrasas() <= min_gras){
        min_gras = ingrediente_actual.getGrasas();
        el_min_gras = ingrediente_actual.getNombre();
    }

    if(ingrediente_actual.getFibras() >= max_fib){
        max_fib = ingrediente_actual.getFibras();
        el_max_fib = ingrediente_actual.getNombre();
    }
    
    if(ingrediente_actual.getFibras() <= min_fib){
        min_fib = ingrediente_actual.getFibras();
        el_min_fib = ingrediente_actual.getNombre();
    }
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
cout << "Máximos valores" << endl;
cout << "Calorías (Alimento)" << "\tHidratos de Carb. (Alimento)" << "\tProteínas (Alimento)" << "\tGrasas (Alimento)" << "\tFibra (Alimento)" << endl;
cout << max_cal << " " << el_max_cal << "\t\t" << max_hid << " " << el_max_hid << "\t\t" << max_pro << " " << el_max_pro << "\t\t" << max_gras << " " << el_max_gras << "\t\t" << max_fib << " " << el_max_fib << endl;
cout << "Mínimos valores" << endl;
cout << "Calorías (Alimento)" << "\tHidratos de Carb. (Alimento)" << "\tProteínas (Alimento)" << "\tGrasas (Alimento)" << "\tFibra (Alimento)" << endl;
cout << min_cal << " " << el_min_cal << "\t\t" << min_hid << " " << el_min_hid << "\t\t" << min_pro << " " << el_min_pro << "\t\t" << min_gras << " " << el_min_gras << "\t\t" << min_fib << " " << el_min_fib << endl;

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
    return is;
}
