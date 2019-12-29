#include "instrucciones.h"

Acciones Instrucciones::acc;

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
    cout <<"TEST PARA COMPROBAR LA CREACIÓN DEL ÁRBOL DE INSTRUCCIONES - AQUÍ SE MUESTRA SU CORRECTO FUNCIONAMIENTO" << endl;
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
            if(instrucciones.acc.getAriedad(accion) == '1'){
                arbol.Insertar_Hi(arbol.getRaiz(),ingrediente);
                pila.push(arbol);
            }
            else if(instrucciones.acc.getAriedad(accion) == '2'){
                arbol.Insertar_Hd(arbol.getRaiz(),ingrediente);
                arbol.Insertar_Hi(arbol.getRaiz(),pila.top());
                pila.pop();
                pila.push(arbol);
            }
        }
        else{
            if(instrucciones.acc.getAriedad(accion) == '1'){
                arbol.Insertar_Hi(arbol.getRaiz(),pila.top());
                pila.pop();
                pila.push(arbol);
            }
            else if(instrucciones.acc.getAriedad(accion) == '2'){
                arbol.Insertar_Hd(arbol.getRaiz(),pila.top());
                pila.pop();
                arbol.Insertar_Hi(arbol.getRaiz(),pila.top());
                pila.pop();
                pila.push(arbol);
            }
        }

        cout <<"\nARIEDAD --->>" << instrucciones.acc.getAriedad(accion) << endl;
        arbol.RecorridoPreOrden(cout);
        cout << endl << endl;
        //cout << "Accion:" << accion << endl;
        //cout << "Ingrediente:" << ingrediente << endl;
        linea = "";
        accion = "";
        ingrediente = "";
        hay_esp = false;
    }
    ArbolBinario<string> aux (pila.top());
    //instrucciones.datos = aux;
    pila.pop();
    return is;
}