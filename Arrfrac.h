#ifndef ARRFRAC_H
#define ARRFRAC_H

#include "Fraccion.h"

class Arrfrac{
private: 
    Fraccion * arr;
    int size;
    int sizeMem;
    //void setSize() //cuando modifiquemos el ejercicio usando la clase vector
public:
    Arrfrac();
    Arrfrac(int);
    Arrfrac(int, Fraccion *);
    int getSize();
    Arrfrac suma(Arrfrac inaArrfrac);
    void sumaInPlace(Arrfrac inaArrfrac);
    Arrfrac multiplicacion(Arrfrac inaArrfrac);
    Fraccion getFraccion(int);
    void setFraccion(int, Fraccion);
    void agregarFraccion(Fraccion); 
    void eliminarFraccion(); // ultimo elemento 
    void imprimir(bool);
};

#endif // ARRFRAC_H