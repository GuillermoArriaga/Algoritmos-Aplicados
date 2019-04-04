// Problema 2 el panadero recursivo

#include <iostream>
#include <cstdlib>

using namespace std;

int recursion(int n, int tam, int &cant_bolsas, int &llenado);

int main()
{ int i,n,tam,par; // n=numero de panes, Tam=tamano de las bosas
  int cant_bolsas, llenado; 

  system("cls");
  cout<<"\n\n\tIngresa la cantidad de panes: "; cin>>n;
  cout<<"\n\n\tIngresa la capacidad de las bolsas: "; cin>>tam;
  
  if(n%2==0) par=1;
  if(n%2==1) { par=0; n--; }  // Soluciono para pares y luego agrego el pan que quité
  
  cant_bolsas=1;
  
  recursion(n,tam,cant_bolsas,llenado);

  if((tam-cant_bolsas*llenado)<1&&par==0) {cant_bolsas++;}
  
  if(par==0) n++;
  
  cout<<"\n\tSe requieren "<<cant_bolsas<<" bolsas.\n";
  cout<<"\n\t\t"<<n-cant_bolsas*llenado<<" se llenaran con "<<llenado+1
      <<"\n\t\ty "<<cant_bolsas*(1+llenado)-n<<" con "<<llenado<<" panes.";
      
      
    
  cout<<"\n\n";system("pause");  
  return 0;
}

int recursion(int n, int tam, int &cant_bolsas, int &llenado)
{    
     if(n<=tam) { llenado=n; return 1; }
     if(n>tam) 
        { cant_bolsas*=2;
          n=n/2;
          recursion(n,tam,cant_bolsas,llenado);
        }  
}
