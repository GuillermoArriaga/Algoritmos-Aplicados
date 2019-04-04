/*  =========================================================================
    ==                                                                     == 
    ==        GUILLERMO ARRIAGA GARCÍA          03/06/11                   == 
    ==                                                                     == 
    ==        EXAMEN FINAL PROB 2     DIRECTORIO TELEFÓNICO                == 
    ==                                                                     == 
    ========================================================================= */


#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include "GuiaTelefonica.h"

#define AMARILLO system("COLOR 0E");
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
    int seleccion=1,i,j,k;
    VERDE

    GUIA_TELEFONICA guia;
    
    guia.capturar();
    guia.mostrar();
    
    guia.insertar("Edgar","456-2345-111");
    guia.mostrar();
    guia.modificar("Edgar","456-1111-222");
    guia.mostrar();
    guia.eliminar("Edgar");
    guia.mostrar();
        
    
    FINAL
    return EXIT_SUCCESS;
}


/*  =========================================================================
    ==                                                                     == 
    ==                              FUNCIONES                              == 
    ==                                                                     == 
    ========================================================================= */



/*  =========================================================================
    ==                                                                     == 
    ==                                 |                                   == 
    ==                                                                     == 
    ========================================================================= */


        /* =========================================================
           =                                                       =
           =                           |                           =
           =                                                       =
           =========================================================*/
