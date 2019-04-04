/*  =========================================================================
    ==                                                                     == 
    ==        GUILLERMO ARRIAGA GARCÍA          13/05/11                   == 
    ==                                                                     == 
    ==        PRACTICA 13             US0 DE STL (LIBRERIA TEPLATES C++)   == 
    ==                                                                     == 
    ========================================================================= */


#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>

#include <vector>
#include <list>
#include <queue>
#include <stack>



#define AMARILLO system("COLOR 0E");
#define AZUL     system("COLOR 09");
#define BLANCO   system("COLOR 07");
#define CIELO    system("COLOR 0B");
#define ROJO     system("COLOR 0C");
#define VERDE    system("COLOR 0A");
#define PAUSA    cout<<"\n\n\t";system("PAUSE");cout<<"\n\n";
#define LIMPIAR  system("CLS");
#define FINAL    LIMPIAR AMARILLO cout<<"\n\n\n\t\tFIN DEL PROGRAMA"; PAUSA

using namespace std;




/*  =========================================================================
    ==                                                                     == 
    ==                               MAIN                                  == 
    ==                                                                     == 
    ========================================================================= */


int main()
{
   int seleccion=1;
   VERDE

   
   
   /* *******************************************************************
   
   Leer de un archivo:
        Un entero N (que indica cuantos strings va a capturar.
        N strings y guardarlas en vecto<string> v, ordenar v e imprimirlo.
        
   Leer de un archivo:
        Un entero N
        N ints, guardarlos en list<int>, borrar los N/2 ints más grandes.
        Imprimir el list<int>
        
   
   */


        /* =========================================================
           =                                                       =
           =                   CAPTURA DESDE ARCHIVOS              =
           =                                                       =
           =========================================================*/
   
   
   FILE *in=fopen("strings.txt","r");
   int n;
   fscanf(in,"%d",&n);
   
   vector<string> s(n);
   char c[100];
   
   
   for(int i=0;i<n;i++)
   {  fscanf(in,"%s",&c);
      s[i]=c;
      cout<<s[i]<<" ";
   }
   
   fclose(in);
   
   PAUSA
   

   FILE *in2=fopen("ints.txt","r");
   int m;
   fscanf(in,"%d",&m);
   
   list<int> l;
   int ii;
   
   
   for(int i=0;i<m;i++)
   {  fscanf(in,"%d",&ii);
      l.push_front(ii);
      cout<<l.front()<<" ";
   }

   fclose(in);
   
   PAUSA


        /* =========================================================
           =                                                       =
           =                       ORDENACIÓN                      =
           =                                                       =
           =========================================================*/


   string str2;

   for(vector<string>::iterator it1=s.begin(); it1!=s.end(); it1++)
     for(vector<string>::iterator it2=it1; it2!=s.end(); it2++)
           if((*it1)>(*it2))
               { str2=(*it1);       // swap
                 (*it1)=(*it2);
                 (*it2)=str2;
               }
   
   for(list<int>::iterator it3=l.begin(); it3!=l.end(); it3++)
     for(list<int>::iterator it4=it3; it4!=l.end(); it4++)
           if((*it3)>(*it4))
               { ii=(*it3);         // swap
                 (*it3)=(*it4);
                 (*it4)=ii;
               }

   for(int j=0;j<m/2;j++)    // anula los N/2 elementos mayores de la lista
      l.pop_back();


        /* =========================================================
           =                                                       =
           =                       IMPRESIÓN                       =
           =                                                       =
           =========================================================*/



   for(int i=0;i<n;i++)
      cout<<" "<<s[i];
   

   for(list<int>::iterator it3=l.begin(); it3!=l.end(); it3++)
      cout<<" "<<(*it3);
   

   PAUSA


    FINAL
    return EXIT_SUCCESS;
}


        /* =========================================================
           =                                                       =
           =                     EXPLICACIÓN                       =
           =                                                       =
           =========================================================*/


/*
   // USO DE VECTORES

   vector<int> v1;       // vacio
   vector<int> v2(5);
   vector<int> v3(6,1);  // 6 elementos iguales a 1
   
   // v1[2]=1; marca error no tiene memoria
   
   v1.push_back(5);   // mete el 5 a v1
   v1.pop_back();     // elimina el último elemento sin verlo
   int tam=v1.size(); // regresa el tamaño del vector
   
   for(int i=0;i<v1.size();i++)
   { // algo
   }

   // el iterador es similar a un apuntador
   for(vector<int>::iterator it=v1.begin();it!=v1.end();it++)
   { (*it)=1;
   }
   
   int k;
   v1.erase(v1.begin()+k); //Borra el elemento en la posicion k
   v1.clear();
   
   
   // USO DE LISTA
   
   list<double> L;
   
   L.back();
   L.front();
   
   L.pop_back();
   L.pop_front();
   
   L.size();
   
   // L[]; no existe
   
   for(list<double>::iterator it=L.begin();it!=L.end();it++)
   {}
   
   L.clear();  // Limpia y deja size 0
   
   queue<float> que;
   
   que.push(3);  // mete al final
   que.front();  // regresa el elemento inicial
   que.pop();    // saca el primer elemento
   que.empty();  // regresa TRUE si está vacia
   que.size();
   
   // no tiene que[]
   // no tiene iteradores
   
*/
