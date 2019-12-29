#include "instrucciones.h"

Instrucciones::Instrucciones(){}

Instrucciones::Instrucciones(ArbolBinario<string> &arbol, Acciones acc){
    this->datos = arbol;
    this->acc = acc;
}

ostream &operator<<(ostream &os, const Instrucciones &instrucciones){
    instrucciones.datos.RecorridoPostOrden(os);
    return os;
}

istream &operator>>(istream &is, Instrucciones &instrucciones){
    string linea = "";
    string ingrediente = "";
    string accion = "";
    int ariedad;
    bool hay_esp = false;
    const char espacio = ' ';
    const char salto_linea = '\n';

    stack<ArbolBinario<string> > pila;

    while(is.peek() != EOF){
        getline(is,linea,salto_linea);
        for(string::iterator it = linea.begin(); it != linea.end(); ++it){
            if(*it == espacio)
                hay_esp = true;
            if(!hay_esp)
                accion += *it;
            else
                ingrediente += *it;          
        }

        ArbolBinario<string> arbol(accion);

        if(!ingrediente.empty()){
            if(instrucciones.acc.getAriedad(accion) == 1){
                arbol.Insertar_Hi(arbol.getRaiz(),ingrediente);
            }
            else if(instrucciones.acc.getAriedad(accion) == 2){
                arbol.Insertar_Hi(arbol.getRaiz(),ingrediente);
                arbol.Insertar_Hd(arbol.getRaiz(),pila.top());
                pila.pop();
            }
        }
        else{
            if(instrucciones.acc.getAriedad(accion) == 1){
                arbol.Insertar_Hi(arbol.getRaiz(),pila.top());
                pila.pop();
            }
            else if(instrucciones.acc.getAriedad(accion) == 2){
                arbol.Insertar_Hd(arbol.getRaiz(),pila.top());
                pila.pop();
                arbol.Insertar_Hi(arbol.getRaiz(),pila.top());
                pila.pop();
            }
        }
        arbol.RecorridoPostOrden(cout);
        //instrucciones.datos = arbol;
        //cout << "Accion:" << accion << endl;
        //cout << "Ingrediente:" << ingrediente << endl;
        linea = "";
        accion = "";
        ingrediente = "";
        hay_esp = false;
    }
    return is;
}