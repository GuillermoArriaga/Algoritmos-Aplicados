// Guillermo Arriaga Garcia Tarea 10: Triangulo de Sierpinski

#include "Shell.cpp"
#include <stdlib.h>


Window W("GAG PROGRAMS: Triangulo de Sierpinski",500,500);

void triangulo(int x1, int y1, int x2, int y2, int x3, int y3);
void sierpinski(int nivel,int x1, int y1, int x2, int y2, int x3, int y3);

int main()
{
  int nivel,i,x1=50,y1=400,x2=450,y2=400,x3=250,y3=100,max=11;

  for(nivel=1;nivel<=max;nivel++)        // Para ver los distintos niveles
  {
    // Impresion del triangulo
    if(nivel==1) 
       W.printf(25,25,"Guillermo Arriaga Garcia: Triangulo de Sierpinski: "
                      "Niveles 1 a %i",max);
    
    W.printf(25,50,"Nivel %d",nivel);
    
    if(nivel==1)   triangulo(x1,y1,x2,y2,x3,y3);          // Triangulo inicial
    if(nivel>1)    sierpinski(nivel-1,x1,y1,x2,y2,x3,y3); // Triangulos internos
    if(nivel!=max) MessageYesNo("Presiona un boton para continuar.");
  }     
  
    MessageYesNo("Presiona un boton para salir.");
    W.Cls();
    return 0;
}


// Funcion que imprime un triangulo
void triangulo(int x1, int y1, int x2, int y2, int x3, int y3)
{   W.line(x1,y1,x2,y2);
    W.line(x2,y2,x3,y3);
    W.line(x3,y3,x1,y1);
}

// Manda a impresion el triangulo interior al triangulo dado
void sierpinski(int nivel,int x1, int y1, int x2, int y2, int x3, int y3)
{  int xx1,yy1,xx2,yy2,xx3,yy3;
   xx1=(x1+x2)/2;  // Calcula los puntos medios redondeados a enteros
   yy1=(y1+y2)/2;
   xx2=(x2+x3)/2;
   yy2=(y2+y3)/2;
   xx3=(x3+x1)/2;
   yy3=(y3+y1)/2;

   triangulo(xx1,yy1,xx2,yy2,xx3,yy3);  // Imprime triangulo

//   system("pause");
   
   if(nivel>1)  // recursividad
    { sierpinski(nivel-1,x1,y1,xx1,yy1,xx3,yy3);  // Triangulo inferior izq.
      sierpinski(nivel-1,xx1,yy1,x2,y2,xx2,yy2);  // Triangulo superior
      sierpinski(nivel-1,xx3,yy3,xx2,yy2,x3,y3);  // Triangulo inferior der.
    }
}
