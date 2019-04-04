/* ==========================================================================
   =                                                                        =
   =         GUILLERMO ARRIAGA GARCÍA : PROBLEMA 1 EXAMEN 1                 = 
   =                                                                        =
   =                     DETECTOR DE LISTAS CORRUPTAS                       =
   =                                                                        =
   =          Basado en la tarea 9 del 3 de marzo de 2011                   =
   =                                                                        =
   ========================================================================== */


#include <cstdlib>
#include <iostream>
#include "Lista.h"
#include "NODO_H.h"

using namespace std;


void imprimir_lista(LISTA& lis, int& cant);
int checa_corrupcion(LISTA& lis, int &posic);

int main()
{
    int i, seleccion=1,n=2,m=2,checador;
    int posicion=0;
    LISTA lista_1(2), lista_2(2);
    NODO* comienzo;

    while(seleccion!=0)
    {               
      system("cls");
      cout<<"\n\tGuillermo Arriaga Garcia\n\tListas\n\n\n"
          "\t1.- Crear la lista 1 de n elementos aleatorios entre el 0-9"
             "\n\tcon apuntador final a algun elemento aleatorio de la lista.\n"
          "\t2.- Crear la lista 2 de m elementos aleatorios entre el 0-9.\n"
          "\t3.- Imprimir las listas.\n"          
          "\t4.- Detectar si hay corrupcion.\n"
          "\n\n\t0.- Salir del programa.\n\n\tSELECCION: ";
      fflush(stdin);
      cin>>seleccion;
      
      switch(seleccion)
        { case 0: break;
                       
          case 1: cout<<"\n\nInserta la cantidad de elementos: "; cin>>n;
                  if(n<1) n=1; // Ajuste de datos
                  lista_1.limpiar();
                  comienzo=lista_1.inicio();
                  (comienzo->contenido)=rand()%10;   
                  for(i=1;i<n;i++) lista_1.insertaFinal(rand()%10);
                  lista_1.mover_final(1+(rand()%n)); // El final apunta a algun elemento
                  cout<<"\nLista 1:\n";
                  imprimir_lista(lista_1,n);
                  break;

          case 2: cout<<"\n\nInserta la cantidad de elementos: "; cin>>m;
                  if(m<1) m=1; // Ajuste de datos
                  lista_2.limpiar();
                  comienzo=lista_2.inicio();
                  (comienzo->contenido)=rand()%10;   
                  for(i=1;i<m;i++) lista_2.insertaFinal(rand()%10);
                  cout<<"\nLista 2:\n";
                  imprimir_lista(lista_2,m);
                  break;


          case 3: cout<<"\nLista 1:\n"; imprimir_lista(lista_1,n);
                  cout<<"\nLista 2:\n"; imprimir_lista(lista_2,m);
                  break;
          
          case 4: checador=checa_corrupcion(lista_1,posicion); //Checar lista 1
                  if(checador==0) 
                     cout<<"\n\n\tLa lista 1 esta corrupta, su final apunta al "
                         <<posicion<<"vo. elemento.";
                  else cout<<"\n\n\tLa lista 1 esta incorrupta.";
                  
                  checador=checa_corrupcion(lista_2,posicion); // Checar lista 2
                  if(checador==0) 
                     cout<<"\n\n\tLa lista 2 esta corrupta, su final apunta al "
                         <<posicion<<"vo. elemento.";
                  else cout<<"\n\n\tLa lista 2 esta incorrupta.";
                  
                  cout<<"\n\n\t"; system("pause");
                  break;        

                  
          default: break;
        }  // Cierre del switch
   } // Cierre del while  
cout<<"\n\n\tFIN DEL PROGRAMA\n\n\t"; system("pause");   
return 0;
} // Cierre del main


/* ==========================================================================
   =                                                                        =
   =                     FUNCIÓN PARA IMPRIMIR LISTAS                       =  
   =                                                                        =
   =          Esta función no es necesaria, por eso usa la cantidad         =
   =                      de elementos de cada lista                        =
   =                                                                        =
   ========================================================================== */


// Funcion para imprimir listas 
// Esta función no es necesaria, por eso usa la cantidad de elementos de cada lista
void imprimir_lista(LISTA& lis, int& cant)
{     NODO* ubicador=lis.inicio();
      int i;

      cout<<endl;
      for(i=0;i<cant;i++)
        { cout<<"\tElemento["<<ubicador->posicion<<"]: "<<(ubicador->contenido)
              <<" que apunta a "<<(ubicador->siguiente)<<".\n";
          ubicador=ubicador->siguiente;
        }  
      cout<<endl; system("pause");
}



/* ==========================================================================
   =                                                                        =
   =                 FUNCIÓN PARA REVISAR SI HAY CORRUPCIÓN                 =  
   =                                                                        =
   =              INFORMACIÓN: Apuntador a la raiz de la lista              =
   =                                                                        =
   ========================================================================== */

int checa_corrupcion(LISTA& lis,int &posic)
{ 
    
  // val_apun da en entero el valor del apuntador de algun elemento.
  int val_apun=(int)lis.inicio();     // cast a int
  int contador,i;
  posic=0;  
  
  NODO *ubicador,*ubic2;              // Ubicador para recorrer la lista a verificar

  LISTA lista_de_chequeo(1,val_apun); // Creacion de la lista de chequeo
  ubicador=lis.inicio();
  
  if((ubicador->siguiente)==NULL) return 1;  // Si es de un elemento y no hay corrupción

  ubicador=lis.inicio()->siguiente;
  contador=1;  // Contador: anuncia la cantidad de elementos de lista_de_chequeo
  
  while(1==1)
  { val_apun=(int)ubicador;
    lista_de_chequeo.insertaFinal(val_apun);
    contador++;
    ubic2=lista_de_chequeo.inicio();   // Para recorrer la lista de chequeo
    
    for(i=0;i<(contador-1);i++)  // Revisa que el nuevo elemento no esté repetido
       { if(val_apun==(ubic2->contenido)) 
           {posic=i+1; return 0;} // Encontró corrupción
         ubic2=ubic2->siguiente;  // Sigue buscando
         if((ubicador==NULL)) return 1; // Revisa si es posible la corrupción
       }// Cierre del for 
    ubicador=ubicador->siguiente;   // Siguiente elemento de la lista a revisar
  }// Cierre del while
}
