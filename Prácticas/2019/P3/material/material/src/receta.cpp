#include "receta.h"

void Receta::copiar(const Receta &receta){
    this->code = receta.code;
    this->plato = receta.plato;
    this->nombre = receta.nombre;
    this->ings = receta.ings;
    this->calorias = receta.calorias;
    this->hc = receta.hc;
    this->grasas = receta.grasas;
    this->proteinas = receta.proteinas;
    this->fibra = receta.fibra;
}

Receta::Receta(){
    code = "NULO";
    plato = 0;
    nombre = "NULO";
    string nulo("NULO");
    calorias,hc,grasas,proteinas,fibra = 0;
}

Receta::Receta(string code, int plato, string nombre, list<pair<string,unsigned int> > ings){
    this->code = code;
    this->plato = plato;
    this->nombre = nombre;
    this->ings = ings;
}

Receta::Receta(const Receta &receta){
    copiar(receta);
}

Receta & Receta::operator=(const Receta &receta){
    if(this != &receta){
        copiar(receta);
    }
    return *this;
}

ostream &operator<<(ostream &os, const Receta &receta){
    os << receta.code << ";";
    os << receta.plato <<  ";";
    os << receta.nombre << ";";

    for(Receta::const_iterator it=receta.begin(); it!=receta.end();++it)
        os << (*it).first << " " << (*it).second;

    os << receta.calorias << " ";
    os << receta.hc << " ";
    os << receta.grasas << " ";
    os << receta.proteinas << " ";
    os << receta.fibra << " ";

    return os;
}

istream &operator>>(istream &is, Receta &receta){
    string code, nombre;
    string plato;
    list<pair<string,unsigned int> > ings;
    pair<string,unsigned int> par;
    string first, second;
    unsigned int unsig = 10;
    bool f = true;
    bool esp = true;
    char salto_linea = '\n';
    char delim = ';';
    char espacio = ' ';
    char aux;

    getline(is, code, delim);
    getline(is, plato, delim);
    getline(is, nombre, delim);

    while(aux != salto_linea){
        is.get(aux);
        //cout << "aux: " << aux << endl;
        if(aux == delim){
            f = true;
            esp = false;
            //unsig = stoul(second,nullptr,10);
            par = make_pair(first,unsig);
            ings.push_back(par);
            first = second = "";
        }
        else if(aux == espacio){
            f = false;
        }
        else if(f){
            first += aux;
        }
        else if(!f){
            second += aux;
        }
        cout << "Primer elemento: " << first << " Segundo elemento: " << second << endl;
    }
    
    Receta auxiliar(code,stoi(plato), nombre, ings);
    
    receta = auxiliar;

    return is;
}
