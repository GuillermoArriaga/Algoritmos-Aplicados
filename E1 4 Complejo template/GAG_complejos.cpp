// GAG Complejos 4-2-2011

#include <cstdlib>
#include <iostream>
#include "complejo.h"

using namespace std;

template <class T>
void impresion_complejo(complejo<T> &comp);

int main(int argc, char *argv[])
{
    complejo<int> ci1(1,2),ci2(3,4),ci3;
    complejo<float> cf1(1.1,2.2),cf2(3.3,4.4),cf3;
    complejo<double> cd1(1.25,2.25),cd2(2.25,3.25),cd3;
    
    system("cls"); cout<<"\n\n";
    // Complejos enteros
    impresion_complejo(ci1);  cout<<" + "; impresion_complejo(ci2); cout<<" = ";
    ci3=ci1+ci2;
    impresion_complejo(ci3); cout<<"\n\n";

    // Complejos flotantes
    impresion_complejo(cf1);  cout<<" + "; impresion_complejo(cf2); cout<<" = ";
    cf3=cf1+cf2;
    impresion_complejo(cf3); cout<<"\n\n";

    // Complejos dobles
    impresion_complejo(cd1);  cout<<" + "; impresion_complejo(cd2); cout<<" = ";
    cd3=cd1+cd2;
    impresion_complejo(cd3); cout<<"\n\n";


    cout<<"\n\n"; system("pause"); 
    return (0);
}


template <class T>
void impresion_complejo(complejo<T> &comp)
{cout<<comp.r()<<" + ( "<<comp.i()<<" ) i";
}

