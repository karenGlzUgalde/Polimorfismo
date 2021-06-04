#ifndef VECTOR_H
#define VECTOR_H

# include "Fraccion.h"

class Vector{

  public:
    Fraccion * componentes; // [1/4, 1/2] + [1/4, 1/4] = [1/2, 3/4]
    //Suma * componente;
    int tam;

  public:
    // Constructores
    Vector();
    Vector(int t, Fraccion * Componentes/*,*suma*/);
    Vector(int);
    // Sobrecarga de Operadores
    Fraccion operator * (Vector); // Producto punto
    Vector producto (Vector); // Producto Cruz
    Vector producto (int); // Escalamiento
    Vector operator + (const Vector);
    Vector operator - (const Vector);
    // Métodos Propios
    void print();
    Vector suma(Vector);
    Vector resta(Vector);
    Fraccion prodPunto(Vector);
    Fraccion prodCruz(Vector);
    float angulo(Vector);
    float magnitud();


};

#endif // VECTOR_H
