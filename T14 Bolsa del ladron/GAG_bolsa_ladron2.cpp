/* ==========================================================================
   ==                                                                      ==
   ==             GAG BOLSA DEL LADRÓN RECURSIVA  TAREA 14                 ==
   ==                                                                      ==
   ==========================================================================*/


#include <cstdlib>
#include <iostream>

using namespace std;

// VARIABLE Item
typedef struct {char name; int size; int val;} Item;

// FUNCIONES
void imprimir_bolsa(int **obj,int cant, int capac);
void max_robo(int **obj,int cant, int capac);
int knap(int cap, Item items[], int maxmonto[],int cant,int cap_ini);



          /*  ===================================================
              =                                                 =
              =                      MAIN                       =
              =                                                 =
              ===================================================   */

int main()
{
    int** objeto;
    int capacidad,cantidad,seleccion=1,i;

          /*  ===================================================
              =                                                 =
              =                 DATOS DE INICIO                 =
              =                                                 =
              ===================================================   */

    capacidad=17;
    cantidad=5;
    objeto=new int*[cantidad];
    for(i=0;i<cantidad;i++) objeto[i]=new int[2];
    objeto[0][0]=3; // tamaño
    objeto[0][1]=4; // valor
    objeto[1][0]=4; objeto[1][1]=5;
    objeto[2][0]=7; objeto[2][1]=10;
    objeto[3][0]=8; objeto[3][1]=11;
    objeto[4][0]=9; objeto[4][1]=13;


          /*  ===================================================
              =                                                 =
              =                     INTERFAZ                    =
              =                                                 =
              ===================================================   */

    system("COLOR 0A");
    while(seleccion!=0)
    {  system("cls");
       cout<<"\n\n\tGuillermo Arriaga Garcia\tBOLSA DEL LADRON\n\n\n"
             "\n\t1.- Cambiar datos de los objetos."
             "\n\t2.- Cambiar la capacidad de la bolsa."
             "\n\t3.- Calcular el maximo monto a robar."
             "\n\n\t0.- Salir del programa.\n\n";
       imprimir_bolsa(objeto,cantidad,capacidad);
       cout<<"\n\n\tSELECCION: ";   cin>>seleccion;
       
       switch(seleccion)
       { case 0: for(i=0;i<cantidad;i++) delete [] objeto[i];
                 delete [] objeto;
                 break;
               
         case 1: for(i=0;i<cantidad;i++) delete [] objeto[i]; delete [] objeto;
                 cout<<"\n\nCantidad de objetos: "; cin>>cantidad;
                 objeto=new int*[cantidad];   // pedir memoria
                 for(i=0;i<cantidad;i++) objeto[i]=new int[2];
                 // Captura de nuevos datos
                 for(i=0;i<cantidad;i++)
                    { cout<<"\nObjeto["<<i+1<<"]\tTamano: "; cin>>objeto[i][0];
                      cout<<"\t\tValor: "; cin>>objeto[i][1];
                    }
                 break;
              
         case 2: cout<<"\n\n\tNueva capacidad de la bolsa: "; cin>>capacidad;
                 break;
                 
         case 3: max_robo(objeto,cantidad,capacidad);
                 break;
                 
         default: break;
       }// cierre del switch
    } // cierre del while
    
    return EXIT_SUCCESS;
} // cierre del main



          /*  ===================================================
              =                                                 =
              =            IMPRESIÓN DE OBJETOS                 =
              =                                                 =
              ===================================================   */

void imprimir_bolsa(int **obj,int cant, int capac)
{ int i,j;
  cout<<"\n\n\tCAPACIDAD DE LA BOLSA: "<<capac<<"\n";
  cout<<"\n\tOBJETO:"; for(i=0;i<cant;i++) cout<<"\t[ "<<((char)('A'+i))<<" ]";
  cout<<"\n\tTAMANO:"; for(i=0;i<cant;i++) cout<<"\t  "<<obj[i][0];
  cout<<"\n\tVALOR:";  for(i=0;i<cant;i++) cout<<"\t  "<<obj[i][1];
  cout<<"\n";
}


          /*  ===================================================
              =                                                 =
              =          CÁLCULO DE LA MEJOR SECUENCIA          =
              =                                                 =
              ===================================================   */

void max_robo(int **obj,int cant, int capac)
{
    int maxmonto[capac+1],i;   //maxmonto[capacidad] = mejor objeto
    for(i=0;i<=capac;i++) maxmonto[i]=-1;  // Inicialización

    // Captura de Items    
    Item items[cant];
    for(i=0;i<cant;i++)
       { items[i].name= (char)('A'+i); 
         items[i].size= obj[i][0];
         items[i].val = obj[i][1];
       }

    // Busqueda del mejor objeto a llevar para todas las capacidades <=
    for(i=1;i<=capac;i++) 
      { knap(i,items,maxmonto,cant,i); }

    // Encuetra la secuencia de objetos a llevar en la mejor combinación
    cout<<"\n\n\tEl mejor robo es :\n\n\tObjetos:  ";

    int cantidad_objeto[cant];
    for(i=0;i<cant;i++) cantidad_objeto[i]=0;

    int valmax=0;
    i=capac;
    while(maxmonto[i]!=-1)
    { //cout<<items[maxmonto[i]].name<<" ";
      cantidad_objeto[maxmonto[i]]+=1;
      valmax+=items[maxmonto[i]].val;
      i-=items[maxmonto[i]].size;
    }
    int caprel=i;
    for(i=0;i<cant;i++) 
      if(cantidad_objeto[i]!=0) 
        { if(cantidad_objeto[i]==1)
            cout<<items[i].name<<" "; 
          else   cout<<cantidad_objeto[i]<<items[i].name<<" "; 
        }  
    
    cout<<"\n\tValor:    "<<valmax<<"\n\tUsando:   "<<(capac-caprel)<<" de "<<capac;
    cout<<"\n\n\t"; system("pause");
}    


          /*  ===================================================
              =                                                 =
              =    CÁLCULO DEL MEJOR OBJETO SEGÚN CAPACIDAD     =
              =                                                 =
              ===================================================   */

int knap(int cap, Item items[], int maxmonto[],int cant,int cap_ini)
{ int i,space,max,t,senalador;
  int maxi=-1;
  
  // Para no volver a hacer cuentas que ya se saben.
  if(maxmonto[cap]!=-1) {maxi=maxmonto[cap]; max=items[maxi].val;}

  // Calcular nueva cuenta
  else
       for(i=0,max=0;i<cant;i++)
         if((space=cap-items[i].size)>=0)
           if((t=knap(space,items,maxmonto,cant,cap_ini)+items[i].val)>max)
           {max = t; maxi = i;}

  // Asigna resultado: El mejor elemento a llevar teniendo capacidad: cap_ini
  if(cap==cap_ini) maxmonto[cap]=maxi;
  return max;
}
