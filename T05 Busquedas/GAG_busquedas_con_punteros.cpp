
/* GAG programs feb 2011
   Tarea 5:  BUSQUEDA SECUENCIAL Y BINARIA
   Guillermo Arriaga Garc�a
*/



#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;



unsigned int aleatorio(unsigned int inicio, unsigned int fin);
unsigned int busqueda_secuencial(unsigned int a[], unsigned int valor, unsigned int b, unsigned int c);
unsigned int busqueda_binaria(unsigned int a[], unsigned int valor, unsigned int b, unsigned int c);
unsigned int pot_diez(int potencia);

int main()
{
   int seleccion=1;
   unsigned int inicio=1, fin=100, *lista, *lista_ord, a, numero, cantidad=1000,b,c,i,j,cantidad_2;
   clock_t start,finish;            // Declaracion de las variables temporales
   double total_time;
   lista=new unsigned int [cantidad];
   lista_ord=new unsigned int [cantidad];


   for(i=0;i<cantidad;i++)                           // Inicializaci�n
      { lista[i]=aleatorio(inicio,fin);
        lista_ord[i]=lista[i];
      }     
   
   for(i=0;i<cantidad;i++)                           // Ordenacion de la lista
      {  for(j=i+1;j<cantidad;j++)
            { if(lista_ord[i]>lista_ord[j]) 
                { a=lista_ord[i];
                  lista_ord[i]=lista_ord[j];
                  lista_ord[j]=a;
      }     }   }
      

   while(seleccion!=0)                               // Men� principal
     {
        system("cls");
        cout<<"\n\n\tGAG programs feb-2011: BUSQUEDAS: SECUENCIAL Y BINARIA\n\n"
              "La lista de inicio tiene 1001 datos aleatorios entre 1 y 100 \n\n"
              "1.- Fijar la cantidad de datos a tratar (llenado aleatorio).\n"
              "2.- Busqueda secuencial en la lista original.\n"
              "3.- Busqueda secuencial con la lista ordenada.\n"
              "4.- Busqueda binaria en la lista ordenada.\n"
              "5.- Imprimir las listas\n"
              "6.- Fijar una cantidad grande con una inicializacion no aleatoria.\n"
              "7.- Hacer n-busquedas de un numero.\n\n"
              "0.- Salir del programa\n\n"
              "Seleccion: ";
        fflush(stdin); // Limpieza de bufer de entrada
        cin>>seleccion;
        
        switch(seleccion)
           {
              case 0: break;

              case 1: cout<<"\n\nIngresa la cantidad de datos : ";
                      cin>>cantidad;
                      cout<<"\nIngresa el intervalo en el cual se generaran los aleatorios = ";
                      cin>>inicio>>fin;
                      // Ajuste de datos:  positivos e inicio < fin
                      if(inicio>fin) {a=inicio;inicio=fin;fin=a;}  
                                                                  
                      // Creacion de la nueva lista
                      delete lista,lista_ord;
                      lista=new unsigned int [cantidad];
                      lista_ord=new unsigned int [cantidad];
                      for(i=0;i<cantidad;i++)
                         { lista[i]=aleatorio(inicio,fin);
                           lista_ord[i]=lista[i];
                         }

                      start=clock();                    // Comienza el contador de tiempo   
                      // Ordenacion de la nueva lista   
                      for(i=0;i<cantidad;i++)     
                         {  for(j=i+1;j<cantidad;j++)
                               { if(lista_ord[i]>lista_ord[j]) 
                                   { a=lista_ord[i];
                                     lista_ord[i]=lista_ord[j];
                                     lista_ord[j]=a;
                         }     }   }
                      finish=clock();                                     // Tiempo final
                      total_time=((finish-start)/(double)CLOCKS_PER_SEC); // Tiempo total
                      cout<<"\n\nEl ordenamiento de la lista se efectuo en "<<total_time<<" segundos.\n\n";
                      cout<<"\n\n";
                      system("pause");    
                      break;

              case 2: cout<<"\n\nIngresa el numero a buscar (["<<inicio<<","<<fin<<"]) : ";
                      cin>>numero;
                      cout<<"\n\nEl intervalo en el cual buscar ( dentro de [0,"<<cantidad-1<<"] ) : ";
                      cin>>b>>c;
                      // Ajuste de datos:  positivos y b < c
                      if(b>c) {a=b;b=c;c=a;}  
                      
                      a=busqueda_secuencial(lista,numero,b,c);
                                            
                      if(lista[a]==numero)
                         cout<<"\n\nEl numero "<<numero<<" se encuentra en la posicion "<<a<<" de la lista.\n\n";
                      else cout<<"\n\nEl numero "<<numero<<" no se encuentra en el intervalo ["<<b<<","<<c<<"] de la lista.\n\n";
                      system("pause");                      
                      break;

              case 3: cout<<"\n\nIngresa el numero a buscar (["<<inicio<<","<<fin<<"]) : ";
                      cin>>numero;
                      cout<<"\n\nEl intervalo en el cual buscar( dentro de [0,"<<cantidad-1<<"] ): ";
                      cin>>b>>c;
                      // Ajuste de datos:  positivos y b < c
                      if(b>c) {a=b;b=c;c=a;}  
                      
                      a=busqueda_secuencial(lista_ord,numero,b,c);
                                            
                      if(lista_ord[a]==numero)
                         cout<<"\n\nEl numero "<<numero<<" se encuentra en la posicion "<<a<<" de la lista.\n\n";
                      else cout<<"\n\nEl numero "<<numero<<" no se encuentra en el intervalo ["<<b<<","<<c<<"] de la lista.\n\n";
                      system("pause");
                      break;

              case 4: cout<<"\n\nIngresa el numero a buscar (["<<inicio<<","<<fin<<"]): ";
                      cin>>numero;
                      cout<<"\n\nEl intervalo en el cual buscar( dentro de [0,"<<cantidad-1<<"] ) : ";
                      cin>>b>>c;
                      // Ajuste de datos:  positivos y b < c
                      if(b>c) {a=b;b=c;c=a;}  
                      
                      a=busqueda_binaria(lista_ord,numero,b,c);
                                            
                      if(lista_ord[a]==numero)
                         cout<<"\n\nEl numero "<<numero<<" se encuentra en la posicion "<<a<<" de la lista ordenada.\n\n";
                      else cout<<"\n\nEl numero "<<numero<<" no se encuentra en el intervalo ["<<b<<","<<c<<"] de la lista ordenada.\n\n";
                      system("pause");
                      break;
              
              case 5: cout<<"\n\nPOSICION:\tLISTA ORIGINAL\t  LISTA ORDENADA\n\n";

                      start=clock();                    // Comienza el contador de tiempo   

                      for(i=0;i<cantidad;i++)
                          { cout<<"["<<i<<"]\t\t"<<lista[i]<<"\t\t  "<<lista_ord[i]<<endl;
                            if(i%100==0&&i!=0) system("pause");
                          }   

                      finish=clock();                                     // Tiempo final
                      total_time=((finish-start)/(double)CLOCKS_PER_SEC); // Tiempo total
                      cout<<"\n\nLa impresion se realizo en "<<total_time<<" segundos.\n\n";
                      cout<<"\n\n";
                      system("pause");
                      break;
                      
              case 6: cout<<"\n\nIngresa la cantidad de datos: ";
                      cin>>cantidad;
                      inicio=0;
                      fin=50;

                      // Creacion de la nueva lista
                      delete lista,lista_ord;
                      lista=new unsigned int [cantidad];
                      lista_ord=new unsigned int [cantidad];

                      for(i=0;i<cantidad;i++)
                         { lista[i]=(i+50)%51;  // Asignacion simple y dispersa
                           lista_ord[i]=lista[i];
                         }

                      start=clock();                    // Comienza el contador de tiempo   
                      // Ordenacion de la nueva lista   
                      for(i=0;i<cantidad;i++)     
                         {  for(j=i+1;j<cantidad;j++)
                               { if(lista_ord[i]>lista_ord[j]) 
                                   { a=lista_ord[i];
                                     lista_ord[i]=lista_ord[j];
                                     lista_ord[j]=a;
                         }     }   }
                      finish=clock();                                     // Tiempo final
                      total_time=((finish-start)/(double)CLOCKS_PER_SEC); // Tiempo total
                      cout<<"\n\nEl ordenamiento de la lista se efectuo en "<<total_time<<" segundos.\n\n";
                      cout<<"\n\n";
                      system("pause");    
                      break;

              case 7: cout<<"\n\nIngresa el numero a buscar (["<<inicio<<","<<fin<<"]) : ";
                      cin>>numero;
                      cout<<"\n\nEl intervalo en el cual buscar( dentro de [0,"<<cantidad-1<<"] ): ";
                      cin>>b>>c;
                      // Ajuste de datos:  positivos y b < c
                      if(b>c) {a=b;b=c;c=a;}  
                      cout<<"\nIngresa la cantidad de busquedas: ";
                      cin>>cantidad_2;
                      
                      // Busqueda secuencial en lista sin ordenar
                      start=clock();
                      for(i=0;i<cantidad_2;i++)
                         {a=busqueda_secuencial(lista,numero,b,c);}
                      finish=clock();
                      total_time=((finish-start)/(double)CLOCKS_PER_SEC);
                      
                      cout<<"\nBusqueda secuencial en lista sin ordenar con "
                          <<cantidad_2<<" iteraciones \n\tha tardado "
                          <<total_time<<" segundos.";
                      if(lista[a]==numero)
                         cout<<"\n\tEl numero "<<numero<<" se encuentra en la posicion "<<a<<" de la lista.\n\n";
                      else cout<<"\n\tEl numero "<<numero<<" no se encuentra en el intervalo ["<<b<<","<<c<<"] de la lista.\n\n";

                      // Busqueda secuencial en lista ordenada
                      start=clock();
                      for(i=0;i<cantidad_2;i++)
                         {a=busqueda_secuencial(lista_ord,numero,b,c);}
                      finish=clock();
                      total_time=((finish-start)/(double)CLOCKS_PER_SEC);
                      
                      cout<<"\nBusqueda secuencial en lista ordenada con "
                          <<cantidad_2<<" iteraciones \n\tha tardado "
                          <<total_time<<" segundos.";
                      if(lista_ord[a]==numero)
                         cout<<"\n\tEl numero "<<numero<<" se encuentra en la posicion "<<a<<" de la lista.\n\n";
                      else cout<<"\n\tEl numero "<<numero<<" no se encuentra en el intervalo ["<<b<<","<<c<<"] de la lista.\n\n";


                      // Busqueda binaria en lista ordenada
                      start=clock();
                      for(i=0;i<cantidad_2;i++)
                         {a=busqueda_binaria(lista_ord,numero,b,c);}
                      finish=clock();
                      total_time=((finish-start)/(double)CLOCKS_PER_SEC);
                      
                      cout<<"\nBusqueda binaria en lista ordenada con "
                          <<cantidad_2<<" iteraciones\n\tha tardado "
                          <<total_time<<" segundos.";
                      if(lista_ord[a]==numero)
                         cout<<"\n\tEl numero "<<numero<<" se encuentra en la posicion "<<a<<" de la lista.\n\n";
                      else cout<<"\n\tEl numero "<<numero<<" no se encuentra en el intervalo ["<<b<<","<<c<<"] de la lista.\n\n";

                      system("pause");
                      break;
                   
              default: break;        
           }  //Cierre del switch
     } //Cierre del while
delete lista,lista_ord;
return 0;
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


unsigned int aleatorio(unsigned int inicio, unsigned int fin)
{  /* Si creo un aleatorio del 0 al 10^n, n=d�gitos y luego saco el modulo de
      otro numero con esa cantidad de digitos, entonces habr� un gran peso en
      ciertos n�meros por lo que propongo lo siguiente:  */

      
   unsigned int num,aleatorio;
   int i,j,numero[9],digitos;                           // M�ximo 999,999,999
   
   num=fin-inicio;

   digitos=0;
   for(i=0;num!=0;i++)                                  // Detecta cada cifra
       for(j=0;j<10;j++)
          {  if(((num-j*pot_diez(i))%pot_diez(i+1))==0)
                {  numero[i]=j;
                   num-=j*pot_diez(i);
                   digitos++;
                   j=10;
                }
          }


   
   aleatorio=0;      
   for(j=0;j<digitos;j++)       // Generaci�n del aleatorio seg�n cada cifra
       { if (numero[j]==0) aleatorio+=pot_diez(j)*(rand()%10);
         if (numero[j]==1) aleatorio+=0;
         if (numero[j]!=0&&numero[j]!=1)
             aleatorio+=pot_diez(j)*(rand()%(numero[j]+1));
       }  
       
   aleatorio+=inicio;
   
   return aleatorio;
}

unsigned int pot_diez(int potencia)    // Funcion para potencias de diez
{ unsigned int resultado;
  resultado=1;
  for(int i=0;i<potencia;i++) {resultado*=10;}
  return resultado;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

unsigned int busqueda_secuencial(unsigned int a[], unsigned int valor, unsigned int b, unsigned int c)
{
   unsigned int i;
//   clock_t start,finish;            // Declaracion de las variables temporales
//   double total_time;

//   start=clock();                    // Comienza el contador de tiempo   
   for(i=b;i<=c;i++)
       if(valor==a[i])
         { //finish=clock();                                     // Tiempo final
//           total_time=((finish-start)/(double)CLOCKS_PER_SEC); // Tiempo total
//           cout<<"\n\nLa busqueda se realizo en "<<total_time*1000000<<" microsegundos.\n\n";
           return i;
         }

//   finish=clock();                                     // Tiempo final
//   total_time=((finish-start)/(double)CLOCKS_PER_SEC); // Tiempo total
//   cout<<"\n\nLa busqueda se realizo en "<<total_time*1000000<<" microsegundos.\n\n";

   return 0;  // Pues es un entero sin signo, de todos modos no hay confusion en si i=0 pues "arriba" se evaluar� la distinci�n.
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

unsigned int busqueda_binaria(unsigned int a[], unsigned int valor, unsigned int b, unsigned int c)
{
   unsigned int i,d;
//   clock_t start,finish;            // Declaracion de las variables temporales
//   double total_time;

//   start=clock();                    // Comienza el contador de tiempo   
   while(c>=b)
        {  if(valor==a[b]) return b;   // Evaluacion de extremos
           if(valor==a[c]) return c;
           d=(b+c)/2;
           if(valor==a[d])
             { //finish=clock();                                     // Tiempo final
//               total_time=((finish-start)/(double)CLOCKS_PER_SEC); // Tiempo total
//               cout<<"\n\nLa busqueda se realizo en "<<total_time*1000000<<" microsegundos.\n\n";
               return d;
             }
           if(valor<a[d]) c=d-1;
           else b=d+1;
        }
//   finish=clock();                                     // Tiempo final
//   total_time=((finish-start)/(double)CLOCKS_PER_SEC); // Tiempo total
//   cout<<"\n\nLa busqueda se realizo en "<<total_time*1000000<<" microsegundos.\n\n";
   return 0;  // Pues es un entero sin signo, de todos modos no hay confusion en si i=0 pues "arriba" se evaluar� la distinci�n.
}
