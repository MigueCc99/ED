#include "ingrediente.h"

void Ingrediente::copiar(const Ingrediente &ingrediente){
    this->nombre = ingrediente.nombre;
    this->calorias = ingrediente.calorias;
    this->hidratos = ingrediente.hidratos;
    this->proteinas = ingrediente.proteinas;
    this->grasas = ingrediente.grasas;
    this->fibras = ingrediente.grasas;
    this->tipo = ingrediente.tipo;
}

Ingrediente::Ingrediente(){
    nombre = "nulo";
    calorias = 0;
    hidratos = 0;
    proteinas = 0;
    grasas = 0;
    fibras = 0;
    tipo = "nulo";
}

Ingrediente::Ingrediente(string nombre, int calorias, int hidratos, int proteinas, int grasas, int fibras, string tipo){
    this->nombre = nombre;
    this->calorias = calorias;
    this->hidratos = hidratos;
    this->proteinas = proteinas;
    this->grasas = grasas;
    this->fibras = fibras;
    this->tipo = tipo;
}

Ingrediente::Ingrediente(const Ingrediente &ingrediente){
    copiar(ingrediente);
}

Ingrediente& Ingrediente::operator=(const Ingrediente &ingrediente){
    if (this != &ingrediente){
        copiar(ingrediente);
    }
    return *this;
}

const string Ingrediente::getNombre() const { return nombre; }

const int Ingrediente::getCalorias() const { return calorias; }

const int Ingrediente::getHidratos() const { return hidratos; }

const int Ingrediente::getProteinas() const { return proteinas; }

const int Ingrediente::getGrasas() const { return grasas; }

const int Ingrediente::getFibras() const { return fibras; }

const string Ingrediente::getTipo() const { return tipo; }

void Ingrediente::setNombre(string nombre) { this->nombre = nombre; }

void Ingrediente::setCalorias(int calorias) { this->calorias = calorias; }

void Ingrediente::setHidratos(int hidratos) { this->hidratos = hidratos; }

void Ingrediente::setProteinas(int proteinas) { this->proteinas = proteinas; }

void Ingrediente::setGrasas(int grasas) { this->grasas = grasas; }

void Ingrediente::setFibras(int fibras) { this->fibras = fibras; }

void Ingrediente::setTipo(string tipo) { this->tipo = tipo; }

ostream &operator<<(ostream &os, const Ingrediente &ingrediente){
    os << "Nombre " << ingrediente.getNombre() << endl;
    os << "Calorias " << ingrediente.getCalorias() << endl;
    os << "Hc " << ingrediente.getHidratos() << endl;
    os << "Proteinas " << ingrediente.getProteinas() << endl;
    os << "Grasas " << ingrediente.getGrasas() << endl;
    os << "Fibra " << ingrediente.getFibras() << endl;
    os << "Tipo " << ingrediente.getTipo() << endl;

    return os;
}

istream &operator>>(istream &is, Ingrediente &ingrediente){
    string nom, tip, cal, hc, pro, gra, fib;
    char delim = ';';
    std::getline(is, nom, delim);
    std::getline(is, cal, delim);
    std::getline(is, hc, delim);
    std::getline(is, pro, delim);
    std::getline(is, gra, delim);
    std::getline(is, fib, delim);
    std::getline(is, tip);

    Ingrediente iflujo(nom, stoi(cal), stoi(hc), stoi(pro), stoi(gra), stoi(fib), tip);
    ingrediente = iflujo;

    return is;
}