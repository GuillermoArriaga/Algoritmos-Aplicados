// GAG: Uso de Strings preacrica 8, 18 feb 2011
// La clase incrementa o decrementa el char*

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>  // para printf

using namespace std;

void explicaciones();
void practica8();
int int_a_string(int num1,string &str2);
int string_a_int(string str1,int &num2);
int pot(int num, int potencia);


int main(int argc, char *argv[])
{
//    explicaciones();
    practica8();
    
    cout<<"\n\nFIN DEL PROGRAMA\n\n"; system("PAUSE");
    return EXIT_SUCCESS;
}

// +++++++++++++++++++++++ PRACTICA 8 +++++++++++++++++++++++++++++++++++++++++
void practica8()
{    
     int seleccion=1,num1=5607,num2=0,exito;
     string str1="7823",str2="";
     
     while(seleccion!=0)
     {  system("cls");
        cout<<"\n\n\t\tGuillermo Arriaga Garcia"
              "\n\n\t\tPRACTICA 8: CONVERSION DE STRING <-> INT"
              "\n\n\t0.- Salir del programa."
              "\n\t1.- Ingresar un string de numeros enteros."
              "\n\t2.- Ingresar un entero positivo."
              "\n\t3.- Ver conversiones."
              "\n\n\tSELECCION: "; cin>>seleccion;
       switch(seleccion)
       { default: break;
         case 0: break;
         case 1: cout<<"\n\nIngresa la cadena: "; cin>>str1; break;
         case 2: cout<<"\n\nIngresa el numero: "; cin>>num1; int_a_string(num1,str2); break;
         case 3: exito=string_a_int(str1,num2);
                 if(exito==0)
                   { cout<<"\n\n\tEl numero de la cadena "<<str1<<" es "<<num2;}
                 else {cout<<"\n\n\tNo hay numero para la cadena "<<str1;}  
                 exito=int_a_string(num1,str2);
                 if(exito==0)
                   { cout<<"\n\n\tEl string de "<<num1<<" es "<<str2;}
                 cout<<"\n\n"; system("pause");
       }// cierre de switch       
        
     }// cierre del while
}// cierre de practica8


// +++++++++  FUNCIONES regresan 0 si es posible y -1 si no.   +++++++++++++++
// El cambio lo realizan en el segundo dato que reciben por referencia
int int_a_string(int num1,string &str2)
{   
    int num3=0,i=0,digitos=0,j,cifra,num4;
    str2="";
    if(num1==0) str2="0";
    
    // Checa si es negativo
    if(num1<0)
      { num3=num1;
        num1=(-1)*(num1);
        str2+='-';
      }
      
   // Cuenta los digitos
   while(num1/(pot(10,i))>0) {digitos++; i++;}
   
   // Buscador de la cifra de cada dígito
   num4=num1;
   for(i=(digitos-1);i>=0;i--) // asigna el caracter
    { 
      // Detectar la cifra de cada digito i
      cifra=0;
      while((num4-cifra*pot(10,i))>(pot(10,i)-1)) { cifra++; }
      num4-=cifra*pot(10,i);  // quita los digitos encontrados 
      
//      str2+=(char)(cifra+48); // asigna la cifra como caracter con un cast
      // Si no fuera permitido usar cast entonces:
//      /* 
         switch(cifra)
           { default: break;
             case 0: str2+='0'; break;
             case 1: str2+='1'; break;
             case 2: str2+='2'; break;
             case 3: str2+='3'; break;
             case 4: str2+='4'; break;
             case 5: str2+='5'; break;
             case 6: str2+='6'; break;
             case 7: str2+='7'; break;
             case 8: str2+='8'; break;
             case 9: str2+='9'; break;
           }
//      */      
    } // cierre del for
    
    if(num3<0) { num1=num3; } // si num1 negativo fue negativo, lo vuelve a ser
    return 0;  // no es posible que no convierta un int a cadena, si se tecleo
               // mal el entero desde su captura habría error. 
               // Por lo que return -1 no se ocuparía
} // cierre de funcion

int pot(int num, int potencia)  // calculador de potencias
{   int num2=1;
    for(int i=0;i<potencia;i++) { num2*=num; }
    return num2;
}



// +++++++++++++++  Conversor de cadena de caracteres a int  +++++++++++++++++
int string_a_int(string str1,int &num2)
{   int i=0,negativo=0,digitos;
    
    digitos=(str1.size()-1);
    
    if(str1[0]=='-') { negativo=1; digitos--; i=1;}
    
    num2=0;
    while(str1[i]!='\0')  // el while recorre el string
    { if(str1[i]>='0'&&str1[i]<='9')
        {  
/*           switch(str1[i])
            { default:  break;
              case '0': digitos--; break;
              case '1': num2+=1*pot(10,(digitos)); digitos--; break;
              case '2': num2+=2*pot(10,(digitos)); digitos--; break;
              case '3': num2+=3*pot(10,(digitos)); digitos--; break;
              case '4': num2+=4*pot(10,(digitos)); digitos--; break;
              case '5': num2+=5*pot(10,(digitos)); digitos--; break;
              case '6': num2+=6*pot(10,(digitos)); digitos--; break;
              case '7': num2+=7*pot(10,(digitos)); digitos--; break;
              case '8': num2+=8*pot(10,(digitos)); digitos--; break;
              case '9': num2+=9*pot(10,(digitos)); digitos--; break;
            }
*/         // Si habilitas el switch deshabilita la siguiente operacion: 
           num2+=(str1[i]-'0')*pot(10,(digitos)); digitos--; 
        }
      
      else {return -1;} // hay algún caracter no numérico
      i++;
    }
    
    
    if(negativo==1) num2*=-1;   // Lo vuelve negativo si es el caso
    return 0; // Indica proceso exitoso
    
} // cierre de funcion













// +++++++++++++++++++++++  EXPLICACIONES DE USO  +++++++++++++++++++++++++++++
void explicaciones()
{     string s;  // crea un char* vacio : constructor default
    string ss("Hola"); // tiene un constructor especial y pone '\0'==indica que termina la cadena al final
    char c[]={"Guillaume"};
    string sss(c);
    int i;
    
    // Hay un método .size que regresa el tamaño de la cadena sin contar '\0'
    system("cls");

    // CAMBIO DE CARACTERES DE UN STRING
    cout<<"\n\n ss inicial = "<<ss;
    for(i=0;i<ss.size();i++)
       { ss[i]='a';
       }
    cout<<"\n ss final = "<<ss;
   

   // CONCATENACION DE STRINGS           '1char'  "varios char"
   ss+='b';
   string suma=ss+" "+sss;
   cout<<"\n ss + 'b' = "<<ss;
   cout<<"\n\n ss + _ + sss = "<<suma;
   
   // IMPRESION CON PRINTF
   printf("\n Con printf ss = %s",ss.c_str());  // usando el método .c_str();
   
   // PARA COMPARAR STRINGS   <,>,==,!=
   if(ss==sss) // si ss es exactamente igual a sss
     {cout<<"\n\nss = sss ";}
   
   if(ss<sss) // compara el ASCII de cada uno de los caracteres ss[i]<sss[i] 
     {cout<<"\n\nss < sss ";}  // si ss=aa y sss=aaa -> ss<sss
     // si ss=aba y sss=aab -> ss > sss  si cuando checa encientra que es menor el que esta checando devuelve que el string es menor
     // si son iguales, pasa a checa el siguiente


   // PARA LIMPIAR UN STRING
   ss="";
   ss="Hola";
   cout<<"\n ss nuevo = "<<ss;
   ss="Hola Guillaume";        // no se necesita limpiar
   cout<<"\n ss nuevo = "<<ss;
   
   
   // para saber el ascii de un caracter
   printf("\n\nEl ASCII de a es %d",'a');
   cout<<"\nEl ASCII de A es "<<(int)('A'); // haciendo cast a int
   cout<<"\nEl ASCII de 0 es "<<(int)('0'); 
   cout<<"\nEl ASCII de 1 es "<<(int)('1');  
   cout<<"\nEl ASCII de 9 es "<<(int)('9'); 
   
   // CONVERSION DE INT <-> STRING por ahora haciendo funciones
   
    cout<<"\n\n"; system("PAUSE");
}
