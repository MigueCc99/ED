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
    nombre = "Undefined";
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

const string Receta::getNombre() const{
      return this->nombre;
}

const string Receta::getCode() const{
    return this->code;
}

const int Receta::ningredientes(){
    return ings.size();
}

ostream &operator<<(ostream &os, const Receta &receta){
    os << receta.code << ";";
    os << receta.plato <<  ";";
    os << receta.nombre << ";";

    for(Receta::const_iterator it=receta.begin(); it!=receta.end();++it)
        os << (*it).first << " " << (*it).second << ";";
/*
    os << receta.calorias << " ";
    os << receta.hc << " ";
    os << receta.grasas << " ";
    os << receta.proteinas << " ";
    os << receta.fibra << " ";
*/
    return os;
}

istream &operator>>(istream &is, Receta &receta){
    string code, nombre, plato;
    string aux;
    string sub_aux;
    list<pair<string,unsigned int> > ings;
    pair<string,unsigned int> par;
    string first, second;
    char salto_linea = '\n';
    char espacio = ' ';
    char delim = ';';

    getline(is, code, delim);
    getline(is, plato, delim);
    getline(is, nombre, delim);

    string::iterator it;
    string::iterator sub;
    string::iterator test;
    string::iterator auxiliar;

    getline(is,aux,salto_linea);
    aux += ';';
        for(it = aux.begin(); it < aux.end(); ++it){
            if((*it) != delim)
                sub_aux += (*it);
            else{
                sub = sub_aux.end();
                test = sub-1;
                if((*test) == '0' or (*test) == '1' or (*test) == '2' or (*test) == '3' or (*test) == '4' or (*test) == '5'
                    or (*test) == '6' or (*test) == '7' or (*test) == '8' or (*test) == '9')
                    while((*sub) != espacio)
                        --sub;
                auxiliar = sub;
                for(sub = sub_aux.begin(); sub < sub_aux.end(); ++sub){
                    if(sub < auxiliar)
                        first += (*sub);
                    else if(sub > auxiliar)
                        second += (*sub);
                }
                par = make_pair(first,stoul(second));
                ings.push_back(par); 
                first = second = "";               
                sub_aux = "";
            }    

        }
    
/*
    while(getline(is,aux,delim) && !fin){
        it = aux.end();
        test = it-1;
        if((*test) == '0' or (*test) == '1' or (*test) == '2' or (*test) == '3' or (*test) == '4' or (*test) == '5'
            or (*test) == '6' or (*test) == '7' or (*test) == '8' or (*test) == '9')
            while((*it) != espacio)
                --it;
        auxiliar = it;
        for(it = aux.begin(); it < aux.end(); ++it){
            if(it < auxiliar)
                first += (*it);
            else if(it > auxiliar)
                second += (*it);
        }
        par = make_pair(first,u);
        ings.push_back(par);
        cout << "Primer elemento: " << first << " Segundo elemento: " << second << endl;
        first = second = "";
        
    }
*/
/*
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
*/    
    Receta r(code,stoi(plato), nombre, ings);
    
    receta = r;

    return is;
}
