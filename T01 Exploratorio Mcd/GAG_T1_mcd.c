
// GAG enero 2011: Algoritmo de Euclides para encontrar el MCD

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int residuo(int x, int y);

int main()
{ int a,b,c,d,e,f=1;

  system("cls");
  printf("\n\n\tPrograma que calcula el Maximo Comun Divisor"
         " de dos numeros enteros\n\n"
         "Ingresa los dos enteros con un 'enter':\n\n");scanf("%i%i",&b,&c);
  
  b=abs(b);c=abs(c);          // Toma solo valores no negativos
  a=(b+c+abs(c-b))/2; d=a;         // Seleccion del mayor
  b=(b+c-abs(c-b))/2; e=b;        // Seleccion del menor

// Calculo con el operador % modulo
  c=a%b;
  do{ if (c==0) {printf("\n\nEl MCD es %i utilizando el operador modulo.",b); 
                 getch(); f=0;}
      else { a=b; b=c; c=a%b;}
    }while (f==1); // Ciclo sin fin

// Calculo sin el operador % modulo
  f=1; c=residuo(d,e);
  do{ if (c==0) {printf("\n\nEl MCD es %i haciendo restas.",e); getch(); f=0;} 
      else { d=e; e=c; c=residuo(d,e);}
    }while (f==1); 
    
  return(0);    
}

int residuo(int x, int y)
{  while(x-y>=0)x-=y;
   return(x);
}
  
