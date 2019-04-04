// Practica 5: Listas Guillermo Arriaga Garcia 25 de febrero de 2011
// Programa corregido y aumentado

#include <cstdlib>
#include <iostream>
#include "Lista.h"
#include "NODO_H.h"

using namespace std;

int main(int argc, char *argv[])
{
    int i, valor, cantidad, posicion_1=0, posicion_2=0;
    LISTA lista_1(1);
    NODO* raiz;


// LISTA 1: Uso de insertaInicio    
    system ("cls");
    cout<<"Se ha creado la LISTA 1 con 10 elementos aleatorios entre 0 - 9:\n\n";
    raiz=lista_1.inicio();
    raiz->item=rand()%10;
    for(i=0;i<9;i++)
        { lista_1.insertaInicio(rand()%10);
        }  
    // Para imprimir
    raiz=lista_1.inicio();
    for(i=0;i<10;i++)
        { 
          cout<<"\tElemento["<<i<<"]: "<<(raiz->item)<<" que apunta a "<<(raiz->next)<<".\n";
          raiz=raiz->next;
        }  
    cout<<endl;
    system("pause");
    
    
// LISTA 2: Uso de inicializacion en cero
    cout<<"\n\nAhora ingresa una cantidad de elementos para que \n\tla lista 2 los inicialice en cero: ";
    cin>>cantidad;
    cout<<"\n\n";
    
    LISTA lista_2(cantidad);
    // Para imprimir
    raiz=lista_2.inicio();
    for(i=0;i<cantidad;i++)
        { cout<<"\tElemento["<<i<<"]: "<<raiz->item<<" que apunta a "<<raiz->next<<endl;
          raiz=raiz->next;
        }  
    cout<<endl;
    system("pause");

// LISTA 3    
    cout<<"\n\nAhora ingresa una cantidad de elementos para la lista 3: ";
    cin>>cantidad;
    cout<<"\n\n";
    cout<<"\nIngresa el valor con que se inicializaran: ";
    cin>>valor; 
    cout<<"\n\n";
    
    LISTA lista_3(cantidad,valor);
    // Para imprimir
    raiz=lista_3.inicio();
    for(i=0;i<cantidad;i++)
        { 
          cout<<"\tElemento["<<i<<"]: "<<raiz->item<<" que apunta a "<<raiz->next<<endl;
          raiz=raiz->next;
        }  
    cout<<"\n";
    system("pause");


    
    cout<<"\n\nAhora ingresa un valor a buscar en las listas 1 y 3: ";
    cin>>valor;
    cout<<"\n\n";
    posicion_1=lista_1.encuentra(valor);
    posicion_2=lista_3.encuentra(valor);
    
    if(posicion_1==-1)cout<<"\nEl valor "<<valor<<" no se encuentra en la lista 1 (aleatoria).";
    else {cout<<"\nEl valor "<<valor<<" se encuentra en la posicion "<<posicion_1<<" de la lista 1.";}  

    if(posicion_2==-1)cout<<"\nEl valor "<<valor<<" no se encuentra en la lista 3.";
    else {cout<<"\nEl valor "<<valor<<" se encuentra en la posicion "<<posicion_2<<" de la lista 3.";}  
    
    cout<<"\n\nFin del programa.\n\n";
    system("pause");
    return 0;
}
