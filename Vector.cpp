#include "Fraccion.h"
#include "Vector.h"

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

Vector::Vector()
{
  this->componentes = new Fraccion[1];
  //componente=new int Suma[1];
}

Vector::Vector(int t, Fraccion * Componentes/*,*suma*/)
{
  this->tam = t;
  this->componentes = Componentes; // No es necesario escrbir new ni [].No es necesa  //componente=new int Suma[1];
}

Vector::Vector(int t)
{
    this->tam = t;
    this->componentes = new Fraccion[t];
}

Vector Vector::suma(Vector v1)
{
    Vector vr(tam);
    if (tam == v1.tam) // Verificar si los vectores tienen el mismo tamaño.
    {
        for (int i=0; i<tam; i++)
        {
            //vr.set(vr.componentes[i] + v1.componentes[i], i);
            vr.componentes[i] = componentes[i].suma(v1.componentes[i]);
        }
    }
    return vr;
}

Vector Vector::operator+ (const Vector v1)
{
    Vector vr(tam);
    if (tam == v1.tam) // Verificar si los vectores tienen el mismo tamaño.
    {
        vr = suma(v1); // Se guarda la operación de suma con el vector de entrada.
    }
    //return this->suma(v1);
    return vr;
}

Vector Vector::resta(Vector v1)
{
    Vector vr(tam);
    if (tam == v1.tam) // Verificar si los vectores tienen el mismo tamaño.
    {
        for (int i=0; i<tam; i++)
        {
            //vr.set(vr.componentes[i] + v1.componentes[i], i);
            vr.componentes[i] = componentes[i].resta(v1.componentes[i]);
        }
    }
    return vr;
}

Vector Vector::operator- (const Vector v1)
{
    Vector vr(tam);
    if (tam == v1.tam) // Verificar si los vectores tienen el mismo tamaño.
    {
        vr = resta(v1); // Se guarda la operación de resta con el vector de entrada.
    }
    //return this->suma(v1);
    return vr;
}

Fraccion Vector::prodPunto(Vector v1)
{
    Vector vr(tam);
    Fraccion sumatoria;
    if (tam == v1.tam) // Verificar si los vectores tienen el mismo tamaño.
    {
        for (int i=0; i<tam; i++)
        {
            //vr.set(vr.componentes[i] + v1.componentes[i], i);
            vr.componentes[i] = componentes[i].multiplicacion(v1.componentes[i]);
            if (i >= 1)
            {
              vr.componentes[i] = vr.componentes[i].suma(vr.componentes[i-1]);
            }
              
            sumatoria = vr.componentes[i];
        }
    }
    return sumatoria;
}
Fraccion Vector::prodCruz(Vector v1)
{
    Vector vr(tam);
    Fraccion sumatoria;
    if (tam == v1.tam) // Verificar si los vectores tienen el mismo tamaño.
    {
        for (int i=0; i<tam; i++)
        {
            //vr.set(vr.componentes[i] + v1.componentes[i], i);
            vr.componentes[i] = componentes[i].multiplicacion(v1.componentes[i+1]);
            
            if (i >= 1)
            {
              vr.componentes[i] = vr.componentes[i].resta(vr.componentes[i-1]);
            }
              
            sumatoria = vr.componentes[i];
        }
    }
    return sumatoria;
}

Fraccion Vector::operator* (const Vector v1)
{
    Vector vr(tam);
    Fraccion sumatoria;
    if (tam == v1.tam) // Verificar si los vectores tienen el mismo tamaño.
    {
        sumatoria = prodPunto(v1); // Se guarda la operación de suma con el vector de entrada.
    }
    //return this->suma(v1);
    return sumatoria;
}

float Vector::angulo(Vector V1)
{
   float num = this->prodPunto(V1).decimales(); 
   float den = this->magnitud() * V1.magnitud();

   //cout << num << endl;
   //cout << den << endl;
// podria cambiarse a cout << num <<"/"<< den << endl;
   float div = num / den;

   //cout << div << endl;

   return acosf(div) * 57.29;


}

float Vector::magnitud()
{
  float mag;

  for (int i=0; i<tam; i++)
  {
    componentes[i] = componentes[i].multiplicacion(componentes[i]);

    if (i >= 1)
    {
      componentes[i] = componentes[i].suma(componentes[i-1]);
    }

    mag = componentes[i].decimales();
  }

  return pow(mag,0.5);
}

void Vector::print()
{
    for (int i=0; i<tam; i++)
    {
        componentes[i].imprimir();
    }
}
