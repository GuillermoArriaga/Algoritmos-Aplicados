
// GAG programs Problema de Josephus


#include <iostream>
#include <cstdlib>

using namespace std;

void josephus(int n, int k);

int main()
{
    int seleccion=1,n,k;

  while(seleccion!=0){  
    system("cls");
    cout<<"\n\nPrograma que soluciona el problema de Josephus\n\n"
      "1.- Dar un n (participantes) y k (razon) especificos.\n"
      "2.- Imprimir las proporciones de diferentes k para un n.\n"
      "3.- Imprimir las proporciones de diferentes n para un k.\n"
      "4.- Imprimir n<=16 y k<=n\n"
      "0.- Salir\n\nSeleccion: ";
    cin>>seleccion;
    
    switch(seleccion){
      default: break;
      case 0: break;
      case 1: cout<<"\n\nIngresa n y k: "; cin>>n>>k; josephus(n,k);
              cout<<"\n\n"; system("pause"); break;
      case 2: cout<<"\n\nIngresa n: "; 
              cin>>n;
              for(k=1;k<=n;k++) josephus(n,k);
              cout<<"\n\n"; system("pause"); break;
      case 3: cout<<"\n\nIngresa k: "; cin>>k;for(n=1;n<16;n++)josephus(n,k);
              cout<<"\n\n"; system("pause"); break;
      case 4: for(n=1;n<16;n++){
                  for(k=1;k<=n;k++)josephus(n,k); 
                  cout<<endl; system("pause");
              }
              cout<<"\n\n"; system("pause"); break;
    }// cierre del switch
  }// cierre del while
return 0;
}

void josephus(int n, int k)
{ cout<<"\nN = "<<n<<"  K = "<<k<<"\tMUEREN: ";
  int **a,contador,vivos,i,m;
  a=new int*[n+1]; for(i=0;i<=n;i++) a[i]=new int[2];
  vivos=0;
  a[0][0]=0; a[0][1]=0; 
  for(i=1;i<=n;i++) 
     { a[i][1]=i+1; a[i][0]=i-1;
        if(i==n) a[i][1]=1;
        if(i==1) a[i][0]=n;
       vivos++;
     } // Inicializacion    a[][x]   x=1 ->  siguiente    x=2  ->  anterior

  m=1;
  while(vivos>1)             
   { for(i=1;i<k;i++) m=a[m][1];   // avanza k-1 lugares   
     vivos--;                      // muere a[m][]
     a[(a[m][0])][1]=a[m][1];      // el anterior vivo de m apunta al siguiente vivo
     a[(a[m][1])][0]=a[m][0];      // el siguiente vivo de m apunta al anterior vivo
     cout<<" "<<m;
     m=a[m][1];                    // avanza al siguiente vivo
   }
  cout<<"\tVIVE: "<<m;
  for(i=0;i<=n;i++) delete a[i];
  delete [] a;
}
