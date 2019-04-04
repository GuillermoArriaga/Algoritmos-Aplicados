#include "Diccionario.h"
#include <cstdlib>

DICCIONARIO::DICCIONARIO()
{}

DICCIONARIO::~DICCIONARIO()  // No se ha pedido memoria
{}
            
void DICCIONARIO::insertar(char* palabra)
{ dic[num(palabra)].insertaFinal(palabra);
  return;
}

void DICCIONARIO::listarpor(char letra)
{ dic[num(letra)].imprimir();
  cout<<"\n\n";
  system("PAUSE");
  return;
}

void DICCIONARIO::listar()
{ for(int i=0;i<26;i++)
     { cout<<"\n\n"<<(char)('a'+i)<<" : ";
       dic[i].imprimir();
     }
  cout<<"\n\n";
  system("PAUSE");
  return;
}

int  DICCIONARIO::num(char* palabra)
{ return (palabra[0]-'a');
}

int  DICCIONARIO::num(char letra)
{ return (letra-'a');
}
