/* Guillermo Arriaga Garcia
   Tarea 2b Practica 1 1-feb-11 

   ALGORITMOS PARA REALIZAR Y ANALIZAR CONEXIONES DE ELEMENTOS

Implementacion del quick-find, quick-union, quick union ponderado
*/

#include <iostream>
#include <stdio.h>  // Para poder leer la entrada de datos out.txt
#include <ctime>   // Para poder medir el tiempo de realización


using namespace std;
static const unsigned long int N = 10000;

void presentacion();
void quick_find();
void quick_union();
void quick_union_pesado();


int main()
{
    presentacion();
    return(0);
}

//+++++++++-----------------++++++++++++++++++----------------------+++++++++++

void presentacion()
{    
    int seleccion;
    
    system("cls");                               // Presentacion del programa
    cout <<"\n\n\tPROGRAMAS PARA REALIZAR O REVISAR CONEXIONES\n\n";
    cout <<"1.- Quick find\n2.- Quick union\n3.- Quick union pesado\n";
    cout <<"\n0.- Salir del programa\n\nEl subprograma elegido recibira los "
           "datos del archivo lista_aleatoria.txt y enviara los \ndatos de "
           "salida a quick_find.txt, quick_union.txt o quick_union_pesado.txt\n"
           "\nSeleccion: ";
    fflush(stdin);
    cin >> seleccion;
    
    switch(seleccion)
    {      case 0: exit(0);                          // Salida del programa
           case 1: quick_find();break;
           case 2: quick_union();break;
           case 3: quick_union_pesado();break;
           case 4: quick_find();quick_union();quick_union_pesado();break;
           default: break;
    }       
}                      



//+++++++++-----------------++++++++++++++++++----------------------+++++++++++

void quick_find()
{  unsigned long int i, p, q, id[N];  /*  id[] es el vector que contiene a todos 
                                      los elementos que pueden ser conectados.*/
   freopen("lista_aleatoria.txt","r",stdin);  /*  Abre el texto con la información de las 
                                      conexiones, como "r" lectura y asigna a 
                                      esta información a stdin */
   clock_t start,finish;            // Declaracion de las variables temporales
   double total_time;

   freopen("quick_find.txt","w",stdout);  // Imprime en archivo toda la salida



   start=clock();                    // Comienza el contador de tiempo
   for (i=0; i<N; i++) id[i] = i; /* Inicializacion del vector, cada quien 
                                     está sólo en relación consigo mismo.*/
   finish=clock();                                 // Tiempo final
   total_time=((finish-start)/(double)CLOCKS_PER_SEC); // Tiempo de ejecución
                                     
   while ( cin >> p >> q )  /* Se realiza esta estructura mientras se ingresa 
                               información por el teclado, los valores deben 
                               ir separados por un espacio y, al final, poner 
                               un enter.*/
         { unsigned long int t = id[p];

           start=clock();
           if (t == id[q]) 
            {finish=clock();total_time+=((finish-start)/(double)CLOCKS_PER_SEC);
             continue;}  /* QUICK-FIND: Si los valores [p]=[q] 
                                         -> están conectados -> No realizar 
                                         conexión y no imprimir a pantalla */
           for ( i=0; i<N; i++)       /* Recorrido de todo el vector para 
                                         actualizar las uniones con la nueva.*/
                 if (id[i] == t ) id[i]=id[q]; /* UNION: Si los valores [p]!=[q] 
                                         -> realizar conexión.
                                         Los unidos con [p] ahora están unidos 
                                         a [q]; se van agrupando en subconjuntos 
                                         con representante q */
           finish=clock();total_time+=((finish-start)/(double)CLOCKS_PER_SEC);
           
           cout << " " << p << " " << q << endl;
         }
         
         
         
         
         
   fclose(stdin);              // Cierra el acceso de datos por archivo

   cout <<"\n\tTiempo de ejecución de Quick Find con "<< N <<" elementos: "
        << total_time << " segundos." << endl;

   fclose(stdout);             // stdout pasa a ser el monitor
}


//+++++++++-----------------++++++++++++++++++----------------------+++++++++++


void quick_union()
{  
   freopen("lista_aleatoria.txt","r",stdin);  /*  Abre el texto con la información de las 
                                      conexiones, como "r" lectura y asigna a 
                                      esta información a stdin */
   clock_t start,finish;              // Declaracion de las variables temporales
   double total_time;
   
   freopen("quick_union.txt","w",stdout);  // Imprime en archivo toda la salida
   

   unsigned long int i, j, p, q, id[N];
   
   
   start=clock();
   for (i=0; i<N; i++) id[i] = i;    // Inicializacion
   finish=clock(); total_time=((finish-start)/(double)CLOCKS_PER_SEC);


   while ( cin >> p >> q )
         { start=clock();
           for (i=p; i!=id[i]; i=id[i]);     // Encuentra por la izquierda
           for (j=q; j!=id[j]; j=id[j]);     // Encuentra por la derecha
       
           if(i==j) {finish=clock();
              total_time+=((finish-start)/(double)CLOCKS_PER_SEC); continue;}

           id[i]=j;                          // quick union
           
           finish=clock();total_time+=((finish-start)/(double)CLOCKS_PER_SEC);

           cout << " " << p << " " << q << endl;
         }



   fclose(stdin);

   cout <<"\n\tTiempo de ejecución de Quick Union con "<< N <<" elementos: "
        << total_time << " segundos." << endl;

   fclose(stdout);             // stdout pasa a ser el monitor
}



//+++++++++-----------------++++++++++++++++++----------------------+++++++++++


void quick_union_pesado()
{  
   freopen("lista_aleatoria.txt","r",stdin);  
   /*  Abre el texto con la información de las conexiones, como "r" lectura 
       y asigna a esta información a stdin */
   clock_t start,finish;              // Declaracion de las variables temporales
   double total_time;
   
   freopen("quick_union_pesado.txt","w",stdout);  // Imprime en archivo



   unsigned long int i, j, p, q, id[N], sz[N];  
                                        // sz[] es el tamaño del arbol de datos


   start=clock();
   for (i=0; i<N; i++) {id[i]=i; sz[i]=1;}  // Inicializaciones
   finish=clock(); total_time=((finish-start)/(double)CLOCKS_PER_SEC);

   while ( cin >> p >> q )            // Mientras se recibe informacion de stdin
         { start=clock();
           for (i=p; i!=id[i]; i=id[i]);  // Busqueda por un lado
           for (j=q; j!=id[j]; j=id[j]);  // Busqueda por el otro lado

           if(i==j) {finish=clock(); 
              total_time+=((finish-start)/(double)CLOCKS_PER_SEC);continue;}
           if(sz[i] < sz[j])
             {id[i]=j; sz[j]+=sz[i];}  // quick union + peso
           else{id[j]=i;sz[i]+=sz[j];} // quick union + peso
  
           finish=clock(); total_time+=((finish-start)/(double)CLOCKS_PER_SEC);
  
           cout << " " << p << " " << q << endl;
         }


   fclose(stdin);

   cout <<"\n\tTiempo de ejecución de Quick Union Ponderado con "<< N 
        <<" elementos: "<< total_time << " segundos." << endl;

   fclose(stdout);             // stdout pasa a ser el monitor
}



//+++++++++++------------------++++++++++++++++++++++--------------------+++++++

