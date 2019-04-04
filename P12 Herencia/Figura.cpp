/*  =========================================================================
    =                                                                       =
    =             Guillermo Arriaga García  FIGURAS Tr,Cua,Pen,Cir          =
    =                                                                       =
    =========================================================================*/


#include "Figura.h"
#include <cmath>

/*  =========================================================================
    ==                                                                     == 
    ==                            FIGURA                                   == 
    ==                                                                     == 
    ========================================================================= */


Figura::Figura()               // Estos métodos están para ejemplificar
              {}               // el nombre duplicado en herencias
Figura::~Figura()
              {}             
double Figura::area()
              {}
double Figura::perimetro()
              {}

/*  =========================================================================
    ==                                                                     == 
    ==                           TRIANGULO                                 == 
    ==                                                                     == 
    ========================================================================= */



Triangulo::Triangulo()
                  { this->num_lad=3;
                  }

Triangulo::~Triangulo()
                  {}

             
Triangulo::Triangulo(float a,float b,float c)
                  { this->a=a;
                    this->b=b;
                    this->c=c;
                    this->num_lad=3;
                  }
             
void Triangulo::lados(float a,float b,float c)
                  { this->a=a;
                    this->b=b;
                    this->c=c;
                  }
             
double Triangulo::area()
                  { float s=(a+b+c)/2;
                    return sqrt((s*(s-a)*(s-b)*(s-c)));
                  }
                  
double Triangulo::perimetro()
                  { return a+b+c;
                  }     


/*  =========================================================================
    ==                                                                     == 
    ==                            CUADRADO                                 == 
    ==                                                                     == 
    ========================================================================= */


Cuadrado::Cuadrado()
                  { this->num_lad=4;
                  }

Cuadrado::~Cuadrado()                  
                  {}
                    
Cuadrado::Cuadrado(float a)
                  { this->a=a;
                    this->num_lad=4;
                  }
             
void Cuadrado::lado(float a)
                  { this->a=a;
                  }
             
double Cuadrado::area()
                  { return a*a;
                  }

double Cuadrado::perimetro()
                  { return 4*a;
                  }


/*  =========================================================================
    ==                                                                     == 
    ==                            PENTAGONO                                == 
    ==                                                                     == 
    ========================================================================= */


Pentagono::Pentagono()
                  { this->num_lad=5;
                  }

Pentagono::~Pentagono()
                  {}
                  
Pentagono::Pentagono(float a)
                  { this->a=a;
                    this->num_lad=5;
                  }
             
void Pentagono::lado(float a)
                  { this->a=a;
                  }
             
double Pentagono::area()
                  { float apot=a*(0.769420884294); // (sen(72°)+sen(36°))/2
                    return 2.5*a*apot;
                  }
                  
double Pentagono::perimetro()
                  { return 5*a;
                  }



/*  =========================================================================
    ==                                                                     == 
    ==                             CÍRCULO                                 == 
    ==                                                                     == 
    ========================================================================= */


Circulo::Circulo()
                  { this->num_lad=-1;
                  }

Circulo::~Circulo()
                  {}
             
Circulo::Circulo(float r)
                  { this->r=r;
                    this->num_lad=-1;
                  }
             
void Circulo::radio(float r)
                  { this->r=r;
                  }
             
double Circulo::area()
                  { return PI*r*r;
                  }

double Circulo::perimetro()
                  { return 2*PI*r;
                  }




/*  =========================================================================
    ==                                                                     == 
    ==                    INDICACIONES DE LA PRÁCTICA                      == 
    ==                                                                     == 
    ========================================================================= */


/*

Practica 12


HERENCIA: Existe una clase "padre" y unas clases "hijas"
de donde las "hijas" HEREDAN las propiedades de la clase
"padre", es decir, sus variables, funciones, etc.

class Padre
{
    public:
        string apeido;
        int dinero;
        
        void trabaja()
        {
            dinero*=2;
        }
};

class HijoMalo : public Padre
{
    public:
        HijoMalo()
        {
            apeido="Palomares";
        }
        void trabaja()
        {
            dinero=0;
        }
        void gasta_dinero()
        {
            dinero--;
        }
};

class HijoBueno : public Padre
{
    public:
        HijoBueno()
        {
            apeido="Juarez";
        }
        void da_dinero()
        {
            dinero++;
        }
}

int main()
{
    Padre* p=new HijoBueno();
    Padre* pp=new HijoMalo();
    p->dinero=100;
    pp->dinero=200;
        
    ((HijoBueno*)(p))->da_dinero();
    ((HijoMalo*)(pp))->gasta_dinero();
    
    lista<Padre*> L;        // su clase lista con templates
    
    L.push(p);
    L.push(pp);
    
    Padre* roberto;
    
    roberto=L.dame_un_elemento_random();
    
    if(roberto->apeido=="Palomares")
    {
        ((HijoMalo*)(roberto))->gasta_dinero();
    }else
    {
        ((HijoBueno*)(roberto))->da_dinero();
    }
    
}


int main2()
{
    HijoMalo *roberto=new HijoMalo();
    roberto->dinero=10;
    
    ((Padre*)(roberto))->trabaja();
    
    cout<<roberto->dinero;   
}

Practica 12:
    
    clase Figura
        int numero_de_lados
        double area();
        double perimetro();
    
    class Triangulo : public Figura  //cualquier triangulo
    class Cuadrado : public Figura
    class Pentagono : public Figura //regular
    class Circulo : public Figura
        Hacer lo que quieran pero que funcione y que haga
        las funciones de Figura. Constructores de cada
        figura, por ejemplo para el triangulo le pasas
        3 longitudes que son los lados. Para el circulo
        seria le pasarias el radio, etc.
    
    En el main hacer una lista de Figuras* y ahi meterle
    triangulos, cuadrados, etc. e imprimir las funciones
    de Figura para cada elemento de la lista.
    
    En un triángulo de lados a, b, c, y semiperímetro s=(a+b+c)/2, su área es igual a la raíz cuadrada de s(s-a)(s-b)(s-c)
*/




/*



*/
