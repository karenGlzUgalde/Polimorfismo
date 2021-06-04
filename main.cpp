// Actividad de Polimorfismo Vectores
// Equipo 1
// Juan Daniel Rodríguez Oropeza A01411625
// Karen González Ugalde A01411597
// Hector Jesús Ortiz Lejarza A01411730
// Josué Moises Pérez Galindo A01412511

#include "Fraccion.h"
#include "Arrfrac.h"
#include "Vector.h"

#include <iostream>
using namespace std;

int main(){
    cout << "Evaluando la clase Fraccion:" << endl << "============================" << endl;
    cout << "Definicion y reduccion:" << endl;

    cout << "Fraccion 1 (f1): ";
    Fraccion f1 (30000,75000); // Fraccion 1: 2/5
    f1.imprimir();
    cout << "Fraccion 2 (f2): ";
    Fraccion f2 (6,12); //  Fraccion 2: 1/2
    f2.imprimir();
    cout << "Fraccion 3 (f3): ";
    Fraccion f3 (-3,12); // Fraccion 3: -1/4 (negativo/positivo)
    f3.imprimir();
    cout << "Fraccion 4 (f4): ";
    Fraccion f4 (3,-12); // Fraccion 4: -1/4 (positivo/negativo)
    f4.imprimir();
    cout << "Fraccion 5 (f5): ";
    Fraccion f5 (-3,-12); // Fraccion 5: 1/4 (negativo/negativo)
    f5.imprimir();
    cout << "Fraccion 6 (f6): ";
    Fraccion f6; // Fraccion 6: 0/1 (valor por defecto)
    f6.imprimir();

    cout << "Suma y multiplicacion:" << endl;
    cout << "f6 = f1 + f2:" << endl;
    f6 = f1.suma(f2); // Suma: 2/5 + 1/2 = 9/10
    f6.imprimir();
    cout << "f6 = f1 * f2:" << endl;
    f6 = f1.multiplicacion(f2); // Multiplicacion: 2/5 * 1/2 = 1/5
    f6.imprimir();

    cout << endl << "Evaluando la clase ArrFrac:" << endl << "============================" << endl;
    cout << "Definicion de arreglos:" << endl;
    cout << "Arreglo 1 (af1): ";
    Arrfrac af1;
    af1.imprimir(false);
    cout << "Arreglo 2 (af2): ";
    Arrfrac af2(4);
    af2.imprimir(false);
    Fraccion farray[4] = {f1,f2,f3,f6};
    Fraccion farray2[4] = {f1,f2,f1,f5};
    cout << "Arreglo 3 (af3): ";
    Arrfrac af3(4,farray);
    af3.imprimir(false);
    cout << "Arreglo 4 (af4): ";
    Arrfrac af4(4,farray2);
    af4.imprimir(false);

    cout << "Suma y multiplicacion de arreglos:" << endl;
    cout << "af2 = af3 + af4:" << endl;
    af2 = af3.suma(af4);
    af2.imprimir(false);
    cout << "af2 = af3 * af3:" << endl;
    af2 = af3.multiplicacion(af3);
    af2.imprimir(false);
    cout << "Suma 'InPlace': "<< endl;
    cout << "af2 = af2 + af2:" << endl;
    af2.sumaInPlace(af2);
    af2.imprimir(false);

    cout << "Agregar y eliminar elementos: (modificando af2)" << endl;
    af2.imprimir(true);
    af2.agregarFraccion(f5);
    af2.imprimir(true);
    af2.eliminarFraccion();
    af2.imprimir(true);
    af2.eliminarFraccion();
    af2.imprimir(true);

    cout << endl << "Evaluando la clase Vector:" << endl << "============================" << endl;

    cout << "\n==========    VECTORES DE 4 DIMENSIONES    ==========" << endl;
    
    cout << "\nEstos son los vectores (de 4 dimensiones) de fracciones con los que trabajaremos:" << endl;

    Fraccion * Componentes1 = new Fraccion[4];
    Componentes1[0] = f1;
    Componentes1[1] = f2;
    Componentes1[2] = f3;
    Componentes1[3] = f4;


    Fraccion * Componentes2 = new Fraccion[4];
    Componentes2[0] = f2;
    Componentes2[1] = f3;
    Componentes2[2] = f4;
    Componentes2[3] = f5;

    Vector V1(4, Componentes1);
    Vector VV1(4, Componentes1);
    Vector V2(4, Componentes2);
    Vector VV2(4, Componentes2);
    Vector R1(4);
    Vector R2(4);
    Vector R3(4);
    Vector R4(4);
    Vector R5(4);
    Vector R6(4);

    cout << "\nEste es el vector V1:" << endl;
    V1.print();

    cout << "\nEste es el vector V2:" << endl;
    V2.print();


    cout << "\n==========    SUMA CON VECTORES DE 4 DIMENSIONES    ==========" << endl;

    cout << "\nEste es el vector resultante de la suma de los vectores V1 y V2" << endl;
    R1 = V1.suma(V2);
    R1.print();

    cout << "\nEste es el vector resultante de la suma del vector V1 consigo mismo:" << endl;
    R2 = V1.suma(V1);
    R2.print();

    cout << "\n==========    RESTA CON VECTORES DE 4 DIMENSIONES    ==========" << endl;

    cout << "\nEste es el vector resultante de la resta de los vectores V1 y V2" << endl;
    R3 = V1.resta(V2);
    R3.print();

    cout << "\nEste es el vector resultante de la resta de los vectores V2 y V1" << endl;
    R4 = V2.resta(V1);
    R4.print();

    cout << "\nEste es el vector resultante de la resta del vector V2 consigo mismo." << endl;
    R5 = V2.resta(V2);
    R5.print();

    cout << "\n==========    PRODUCTO PUNTO CON VECTORES DE 4 DIMENSIONES    ==========" << endl;

    cout << "\nEste es el resultado del producto de los vectores V1 y V2" << endl;
    V1.prodPunto(V2).imprimir();

    cout << "\nEste es el resultado del producto del vector V1 consigo mismo:" << endl;
    V1.prodPunto(V1).imprimir();

    cout << "\n==========    MAGNITUD DE VECTORES DE 4 DIMENSIONES    ==========" << endl;

    cout << "\nEste es el resultado de la magnitud del vector V1:" << endl;
    cout << V1.magnitud() << endl;

    cout << "\nEste es el resultado de la magnitud del vector V2:" << endl;
    cout << V2.magnitud() << endl;

    cout << "\n==========    ANGULO ENTRE VECTORES DE 4 DIMENSIONES    ==========" << endl;

    cout << "\nEste es el resultado del angulo entre los vectores V1 y V2" << endl;
    cout << VV1.angulo(VV2) << endl;

    cout << "\nEste es el resultado del angulo entre el vector V1 consigo mismo" << endl;
    cout << VV1.angulo(VV1) << endl;

    cout << "\n==========    VECTORES DE 3 DIMENSIONES    ==========" << endl;

    cout << "\nEstos son los vectores (de 3 dimensiones) de fracciones con los que trabajaremos:" << endl;
    Fraccion * Componentes3 = new Fraccion[3];
    Componentes3[0] = f1;
    Componentes3[1] = f2;
    Componentes3[2] = f3;

    Fraccion * Componentes4 = new Fraccion[3];
    Componentes4[0] = f4;
    Componentes4[1] = f5;
    Componentes4[2] = f6;

    Vector V3(3, Componentes3);
    Vector VV3(3, Componentes3);
    Vector V4(3, Componentes4);
    Vector VV4(3, Componentes4);

    Vector RR1(3);
    Vector RR2(3);
    Vector RR3(3);
    Vector RR4(3);
    Vector RR5(3);
    Vector RR6(3);

    cout << "\n==========    SUMA CON VECTORES DE 3 DIMENSIONES    ==========" << endl;

    cout << "\nEste es el vector resultante de la suma de los vectores V3 y V4" << endl;
    RR1 = V3.suma(V4);
    RR1.print();

    cout << "\nEste es el vector resultante de la suma del vector V3 consigo mismo:" << endl;
    RR2 = V3.suma(V3);
    RR2.print();

    cout << "\n==========    RESTA CON VECTORES DE 3 DIMENSIONES    ==========" << endl;

    cout << "\nEste es el vector resultante de la resta de los vectores V3 y V4" << endl;
    RR3 = V3.resta(V4);
    RR3.print();

    cout << "\nEste es el vector resultante de la resta de los vectores V4 y V3" << endl;
    RR4 = V4.resta(V3);
    RR4.print();

    cout << "\nEste es el vector resultante de la resta del vector V4 consigo mismo." << endl;
    RR5 = V4.resta(V4);
    RR5.print();

    cout << "\n==========    PRODUCTO PUNTO CON VECTORES DE 3 DIMENSIONES    ==========" << endl;

    cout << "\nEste es el resultado del producto de los vectores V3 y V4" << endl;
    V3.prodPunto(V4).imprimir();

    cout << "\nEste es el resultado del producto del vector V3 consigo mismo:" << endl;
    V3.prodPunto(V3).imprimir();

    cout << "\n==========    PRODUCTO CRUZ CON VECTORES DE 3 DIMENSIONES    ==========" << endl;

    cout << "\nEste es el resultado del producto de los vectores V3 y V4" << endl;
    V3.prodCruz(V4).imprimir();

    cout << "\nEste es el resultado del producto del vector V3 consigo mismo:" << endl;
    V3.prodCruz(V3).imprimir();

    cout << "\n==========    MAGNITUD DE VECTORES DE 3 DIMENSIONES    ==========" << endl;

    cout << "\nEste es el resultado de la magnitud del vector V1:" << endl;
    cout << V1.magnitud() << endl;

    cout << "\nEste es el resultado de la magnitud del vector V2:" << endl;
    cout << V2.magnitud() << endl;

    cout << "\n==========    ANGULO ENTRE VECTORES DE 3 DIMENSIONES    ==========" << endl;

    cout << "\nEste es el resultado del angulo entre los vectores V3 y V4" << endl;
    cout << VV3.angulo(VV4) << endl;

    cout << "\nEste es el resultado del angulo entre el vector V3 consigo mismo" << endl;
    cout << VV3.angulo(VV3) << endl;

    cout << "\n\nPrograma creado por el Equipo 1:" << endl;
    cout << "Juan Daniel Rodriguez Oropeza A01411625" << endl;
    cout << "Karen Gonzalez Ugalde A01411597" << endl;
    cout << "Josue Moises Pérez Galindo A01412511" << endl;
    cout << "Hector Jesus Ortiz Lejarza A01411730" << endl;

    return 0;
}