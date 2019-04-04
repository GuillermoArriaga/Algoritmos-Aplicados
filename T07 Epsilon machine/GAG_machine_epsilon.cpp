// Machine Epsilon. Tarea 8 Guilermo Arriaga Garcia

#include <iostream.h>
#include <stdlib.h>

using namespace std;
 
 int main()
 {
    float machEps = 1.0f;

    system("cls");
    cout<<"\n\n\tPROGRAMA QUE CALCULA EL EPSILON DE ESTA MÁQUINA\n\n"; 
    cout<<"Actual Epsilon, 1 + Actual Epsilon\n";
    do {
       cout<<machEps<<"\t"<<(1.0f + machEps)<<endl;
       machEps /= 2.0f;
       /* Si el siguiente epsilon produce un 1, 
       entonces salir del bucle pues es el épsilon de la máquina */
       
       }while ((float)(1.0 + (machEps/2.0)) != 1.0);
 
    cout<<"\n\nEpsilon de la maquina calculado: "<<machEps<<"\n\n";

    system("pause");
    return 0;
 }
