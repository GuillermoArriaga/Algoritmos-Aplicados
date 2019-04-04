/*  =========================================================================
    =                                                                       =
    =              Guillermo Arriaga García  POLINOMIO                      =
    =                                                                       =
    =========================================================================*/


#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include "Polinomio.h"

using namespace std;


/*  =========================================================================
    =                                                                       =
    =                       Destructor y constructores                      =
    =                                                                       =
    =========================================================================*/

    POLINOMIO::~POLINOMIO() { limpiar(); delete raiz; }

    POLINOMIO::POLINOMIO()  { MONOMIO* a=new MONOMIO(1,-123456789,-1,NULL,NULL); raiz=a; fin=a; }

    POLINOMIO::POLINOMIO(string s)
      { MONOMIO* a=new MONOMIO(1,-123456789,-1,NULL,NULL); 
        raiz=a; fin=a;
        
        this->capturar(s);
        
      }



/*  =========================================================================
    =                                                                       =
    =                                Métodos                                =
    =                                                                       =
    =========================================================================*/

    MONOMIO* POLINOMIO::inicio() { return raiz; }
    MONOMIO* POLINOMIO::final()  { return fin; } 

    // Insertar al Inicio
    void POLINOMIO::insertaInicio(double VAL,int exp)
      { if(raiz->contenido==-123456789)
          { raiz->contenido=VAL;
            raiz->exponente=exp;
          }
        else
          { MONOMIO *a=new MONOMIO(1,VAL,exp,NULL,raiz);
            raiz->anterior=a; raiz=a;
            renumerar(); 
          }
        
      }   

    // Inserta al Final
    void POLINOMIO::insertaFinal(double VAL,int exp)
      { if(fin->contenido==-123456789)
          { fin->contenido=VAL;
            fin->exponente=exp;
          }
        else
          { MONOMIO *a=new MONOMIO((fin->posicion+1),VAL,exp,fin,NULL); 
            fin->siguiente=a; fin=a;
          }
      }


    // Longitud de la POLINOMIO
    int POLINOMIO::longitud() {return fin->posicion;}
                                                  
    // Buscar un exponente y regresa la posicion
    int POLINOMIO::encuentra(int exp)
      { MONOMIO* ubicador; int contador=0; ubicador=raiz;
        while(ubicador!=NULL)
          { if (ubicador->exponente==exp) return contador;
            else { contador++; ubicador=ubicador->siguiente; }}
        return -1; }

    // Regresa el apuntador al n-esimo elemento
    MONOMIO* POLINOMIO::regresaNth(int Posicion)
      { MONOMIO* ubicador;
        if(fin->posicion<Posicion) return NULL;
        if((fin->posicion)-(Posicion)<(fin->posicion)/2) // Llega retrocediendo
          { ubicador=fin;
            for(int i=1;i<=(fin->posicion)-(Posicion);i++)
               { ubicador=ubicador->anterior; }
            return ubicador;
          } 
        // Si no hizo lo anterior, ahora llega avanzando.
        ubicador=raiz;
        for(int i=1;i<Posicion;i++)
           { ubicador=ubicador->siguiente; }
        return ubicador;
      }



/*  =========================================================================
    =                                                                       =
    =                          Modificaciones                               =
    =                                                                       =
    =========================================================================*/

    // Cambio de valor en tal posicion
    void POLINOMIO::cambioValor(int Posicion, double VAL,int exp)
      { if(Posicion>0&&Posicion<=(fin->posicion))
          { MONOMIO* ubicador; 
            ubicador=regresaNth(Posicion);
            if(ubicador!=NULL) 
              { ubicador->contenido=VAL;
                ubicador->exponente=exp;
              }
      }   }
                         
    // Cambio de posicion  (CAMBIA LOS VALORES)
    void POLINOMIO::cambioPosicion(int P1, int P2)
      { if(P1>0&&P1<=(fin->posicion)&&P2>0&&P2<=(fin->posicion))
          { double val=(regresaNth(P2)->contenido);
            (regresaNth(P2)->contenido)=(regresaNth(P1)->contenido);
            (regresaNth(P1)->contenido)=val;
            int exp=(regresaNth(P2)->exponente);
            (regresaNth(P2)->exponente)=(regresaNth(P1)->exponente);
            (regresaNth(P1)->exponente)=exp;
      }   }

    // Renumerador
    void POLINOMIO::renumerar()
      { MONOMIO* ubicador; int i; ubicador=raiz;
        for(i=1;ubicador!=fin;i++) 
           { ubicador->posicion=i; ubicador=ubicador->siguiente; }
        fin->posicion=i; }


/*  =========================================================================
    =                                                                       =
    =                          Eliminaciones                                =
    =                                                                       =
    =========================================================================*/


    // Eliminar un MONOMIO
    void POLINOMIO::eliminar(int Posicion)
      { if(Posicion>0&&Posicion<=(fin->posicion))
          { MONOMIO* ubi=regresaNth(Posicion);
            if(ubi->siguiente!=NULL)                     // No es el ultimo
              { if(ubi->anterior!=NULL)          // No es ultimo ni primero
                  {(ubi->anterior)->siguiente=ubi->siguiente;
                   (ubi->siguiente)->anterior=ubi->anterior;
                  } 
                else{ raiz=ubi->siguiente;     // Es el primero y no ultimo
                      raiz->anterior=NULL;
              }     }

            else { if(ubi->anterior!=NULL) // Es el ultimo y no primero
                     { (ubi->anterior)->siguiente=NULL; fin=ubi->anterior; }  
                   else   // Si es el primero y el último, deja con valor cero
                     { raiz=fin=ubi;
                       ubi->contenido=-123456789; // Para identificar lo nuevo
                       ubi->posicion=1;
                       ubi->anterior=NULL;
                       ubi->siguiente=NULL;
                     }
                 }
                           
            if (raiz!=fin) { delete ubi; renumerar(); }
      }   }


    // Quitar el primero
    void POLINOMIO::quitaPrimero() { eliminar(1); renumerar();}
    
    // Quitar el úlimio
    void POLINOMIO::quitaUltimo()  { eliminar(fin->posicion); }
                         
    // Limpiar POLINOMIO
    void POLINOMIO::limpiar()
      { int i; for(i=fin->posicion;i>=raiz->posicion;i--) eliminar(i); }



/*  =========================================================================
    =                                                                       =
    =                            Impresión                                  =
    =                                                                       =
    =========================================================================*/

    void POLINOMIO::imprimir()
      { MONOMIO* ubi=raiz;  
        cout<<" p(x) = ";
        for(int i=1;ubi!=NULL;i++)
          {
           if(ubi->contenido==-123456789) cout<<" \\ VACIO / ";
           else 
            { if(ubi->contenido<0)
                 cout<<" - "<<(-1)*(ubi->contenido)<<" x^"<<ubi->exponente;
              else
                 cout<<" + "<<ubi->contenido<<" x^"<<ubi->exponente;
            }
           ubi=ubi->siguiente; 
          }
      }


/*  =========================================================================
    =                                                                       =
    =                            Evaluación                                 =
    =                                                                       =
    =========================================================================*/


    double POLINOMIO::evaluar(double eval)
      { double num=0,num2=0;
        MONOMIO*ubi=raiz;
        
        for(int i=1;ubi!=NULL;i++)
          {
           if(ubi->contenido==-123456789) cout<<" \\ VACIO / ";
           else 
            { if(ubi->exponente<0)
                { num2=1;
                  for(int j=ubi->exponente;j<0;j++)
                     num2/=eval;
                  num+=ubi->contenido*num2;
                }
              if(ubi->exponente>0)
                { num2=1;
                  for(int j=ubi->exponente;j>0;j--)
                     num2*=eval;
                  num+=ubi->contenido*num2;
                }
              if(ubi->exponente==0) 
                num+=ubi->contenido;
            }
           ubi=ubi->siguiente; 
          }
         return num;
      }



/*  =========================================================================
    =                                                                       =
    =                            Evaluación                                 =
    =                                                                       =
    =========================================================================*/


void POLINOMIO::operator =(const POLINOMIO& P)
{ MONOMIO *ubi;
  ubi=(P.raiz);

  while(ubi!=NULL)
  {
    this->insertaFinal(ubi->contenido,ubi->exponente);
    ubi=ubi->siguiente;
  }

  return;
}


POLINOMIO POLINOMIO::operator +(const POLINOMIO& P1)
{ 
  POLINOMIO P3;
  MONOMIO *ub1,*ub2;
  ub1=P1.raiz;
  ub2=this->raiz;
  
  while(ub1!=NULL||ub2!=NULL)
  {    
    if(ub1==NULL)
      { P3.insertaFinal(ub2->contenido,ub2->exponente);
        ub2=ub2->siguiente;
        continue;
      }

    if(ub2==NULL)
      { P3.insertaFinal(ub1->contenido,ub1->exponente);
        ub1=ub1->siguiente;
        continue;
      }
      
    if(ub1->exponente>ub2->exponente)
      { P3.insertaFinal(ub1->contenido,ub1->exponente);
        ub1=ub1->siguiente;
        continue;
      }
      
    if(ub1->exponente==ub2->exponente)
      { P3.insertaFinal(ub1->contenido+ub2->contenido,ub1->exponente);
        ub1=ub1->siguiente;
        ub2=ub2->siguiente;
        continue;
      }
      
    if(ub1->exponente<ub2->exponente)
      { P3.insertaFinal(ub2->contenido,ub2->exponente);
        ub2=ub2->siguiente;
        continue;
      }
  
  }
  
  // Eliminación de términos nulos
  for(ub1=P3.raiz ; ub1!=P3.fin && P3.fin->posicion>1; ub1=ub1->siguiente)
     { if(ub1->contenido==0)
         { P3.eliminar(ub1->posicion);
         }
     }

  
  
  return P3;  
}
    


POLINOMIO POLINOMIO::operator -(const POLINOMIO& P1)
{ 
  POLINOMIO P3;
  MONOMIO *ub1,*ub2;
  ub1=P1.raiz;
  ub2=this->raiz;
  
  while(ub1!=NULL||ub2!=NULL)
  {    
    if(ub1==NULL)
      { P3.insertaFinal(ub2->contenido,ub2->exponente);
        ub2=ub2->siguiente;
        continue;
      }

    if(ub2==NULL)
      { P3.insertaFinal(ub1->contenido,ub1->exponente);
        ub1=ub1->siguiente;
        continue;
      }
      
    if(ub1->exponente>ub2->exponente)
      { P3.insertaFinal(ub1->contenido,ub1->exponente);
        ub1=ub1->siguiente;
        continue;
      }
      
    if(ub1->exponente==ub2->exponente)
      { P3.insertaFinal(ub1->contenido-ub2->contenido,ub1->exponente);
        ub1=ub1->siguiente;
        ub2=ub2->siguiente;
        continue;
      }
      
    if(ub1->exponente<ub2->exponente)
      { P3.insertaFinal(ub2->contenido,ub2->exponente);
        ub2=ub2->siguiente;
        continue;
      }
  
  }
  
  // Eliminación de términos nulos
  for(ub1=P3.raiz ; ub1!=P3.fin && P3.fin->posicion>1; ub1=ub1->siguiente)
     { if(ub1->contenido==0)
         { P3.eliminar(ub1->posicion);
         }
     }

  
  return P3;  
}
    


POLINOMIO POLINOMIO::operator *(const POLINOMIO& P1)
{ 
  POLINOMIO P3;
  MONOMIO *ub1,*ub2;
  
  for(ub1=P1.raiz ; ub1!=NULL ; ub1=ub1->siguiente)
     for(ub2=raiz ; ub2!=NULL ; ub2=ub2->siguiente)
        P3.insertaFinal((ub1->contenido*ub2->contenido),(ub1->exponente+ub2->exponente));
  
  // Acomodo de P3 con exponentes de mayor a menor
  for(ub1=P3.raiz ; ub1!=P3.fin->anterior ; ub1=ub1->siguiente)
     for(ub2=P3.fin ; ub2!=ub1 ; ub2=ub2->anterior)
        { if(ub2->exponente > ub2->anterior->exponente)
          { P3.cambioPosicion(ub2->posicion,ub2->anterior->posicion);
          }
        }
  
  // Reunión de monomios con exponentes iguales
  for(ub1=P3.raiz ; ub1!=P3.fin ; ub1=ub1->siguiente)
     { if(ub1->exponente==ub1->siguiente->exponente)
         { ub1->contenido+=ub1->siguiente->contenido;
           P3.eliminar(ub1->siguiente->posicion);
         }
     }
  
  // Eliminación de términos nulos
  for(ub1=P3.raiz ; ub1!=P3.fin && P3.fin->posicion>1; ub1=ub1->siguiente)
     { if(ub1->contenido==0)
         { P3.eliminar(ub1->posicion);
         }
     }

  
  return P3;
}
    

   istream& operator>>(istream& entrada, POLINOMIO& p)
       { string s;
         entrada>>s;
         p.capturar(s);
         return entrada;   
       }
        
   ostream& operator<<(ostream& salida, const POLINOMIO& p)
       { MONOMIO* ubi=p.raiz;  
         cout<<" p(x) = ";
         for(int i=1;ubi!=NULL;i++)
          {
            if(ubi->contenido==-123456789) cout<<" \\ VACIO / ";
            else 
            { if(ubi->contenido<0)
                 cout<<" - "<<(-1)*(ubi->contenido)<<" x^"<<ubi->exponente;
              else
                 cout<<" + "<<ubi->contenido<<" x^"<<ubi->exponente;
            }
           ubi=ubi->siguiente; 
          }
         return salida; 
       }


        
   ofstream& operator<<(ofstream& salida, const POLINOMIO& p)
       { MONOMIO* ubi=p.raiz;  
         salida<<" p(x) = ";
         for(int i=1;ubi!=NULL;i++)
          {
            if(ubi->contenido==-123456789) salida<<" \\ VACIO / ";
            else 
            { if(ubi->contenido<0)
                 salida<<" - "<<(-1)*(ubi->contenido)<<" x^"<<ubi->exponente;
              else
                 salida<<" + "<<ubi->contenido<<" x^"<<ubi->exponente;
            }
           ubi=ubi->siguiente; 
          }
         return salida; 
       }



        /* =========================================================
           =                                                       =
           =              CAPTURADOR STRING -> POLINOMIO           =
           =                                                       =
           =========================================================*/


void POLINOMIO::capturar(string s)
{ this->limpiar();
  
  int i,j=0;
  string s_con="",s_exp="";
  double con;
  int exp;
  int antes_x=1;
  
  if(s.size()==0)
    return;
  
  // Detecta la cantidad de monomios para ingresarlos de exponente mayor a menor
  
  for(i=0;i<=s.size();i++)
  { 
    if(antes_x==1&&s_con!="num"&&((s[i]>='0'&&s[i]<='9')||(s[i]=='.')))
      { s_con="num"; 
        continue; 
      }
            
    if(s[i]=='x'||s[i]=='X')
      { antes_x=0;
        if(s_con!="num")
          j++;
        continue;
      }
      
    if(s[i]=='-'||s[i]=='+'||s[i]=='\0')
      { if(s[i]=='-'&&s[i-1]=='^') 
          { s_exp="-"; 
            continue;
          }
        antes_x=1; 
        if (s_con=="num")
           j++;
        s_con="";   
      }
  }
  // Tiene j monomios

  double monomios[j][2];  // Este arreglo se va a ordenar
  int k=0;
  
  // Detecta los monomios
  antes_x=1;
  for(i=0;i<=s.size();i++)
  { 
    if(s[i]=='^')
      continue;
    
    if(antes_x==1&&((s[i]>='0'&&s[i]<='9')||(s[i]=='.')))
      { s_con+=s[i]; 
        continue; 
      }
      
    if(antes_x==0&&s[i]>='0'&&s[i]<='9')
      { s_exp+=s[i];
        continue; 
      }
      
    if(s[i]=='x'||s[i]=='X')
      { antes_x=0;
        continue;
      }
      
    if(s[i]=='-'||s[i]=='+'||s[i]=='\0')
      { if(s[i]=='-'&&s[i-1]=='^') 
          { 
            s_exp="-"; 
            continue;
          }

        antes_x=1;
        
        if(s_con==""||s_con=="-")  // Por si no tiene número el monomio
          s_con+='1';
        con=conversor(s_con);
        
        if(s_exp!="")              // Por si no tiene exponente el monomio
           exp=(int)(conversor(s_exp));
        else
           { if(s[i-1]=='x'||s[i-1]=='X') 
               exp=1;
             else
               exp=0;  
           }
        
        
        if(i!=0)
          { monomios[k][0]=con;
            monomios[k][1]=exp;
            k++;
          }
           
        if(s[i]=='-') 
          { s_con="-";
            s_exp=""; 
            continue;
          }
          
        else 
          { s_con=s_exp="";
            continue;
          }
      }
  }

  
  // Monomios se va a ordenar según los exponentes
  double a;
  for(i=0;i<j-1;i++)
     for(k=j-1;k>i;k--)
        if(monomios[k][1]>monomios[k-1][1])
          { a=monomios[k][1];
            monomios[k][1]=monomios[k-1][1];
            monomios[k-1][1]=a;
            a=monomios[k][0];
            monomios[k][0]=monomios[k-1][0];
            monomios[k-1][0]=a;
          }
  
  // Inserta en polinomio y revisa si hay exponentes iguales
  this->insertaFinal(monomios[0][0],(int)monomios[0][1]);
  for(i=1;i<j;i++)
     { if(monomios[i][1]==monomios[i-1][1])
         { a=(this->regresaNth(i))->contenido;
           if(a+monomios[i][0]==0) // Si se anula este termino
             this->quitaUltimo();
           else  
             this->cambioValor(i,a+monomios[i][0],(int)monomios[i][1]);
         }
       else
         this->insertaFinal(monomios[i][0],(int)monomios[i][1]);
     }
  return;
}



        /* =========================================================
           =                                                       =
           =               CONVERSOR STRING -> NÚMERO              =
           =                                                       =
           =========================================================*/


double POLINOMIO::conversor(string s)
{ double num,num2;
  int punto=0,negativo=0,i;

  // Revisa si es negativo
  if(s[0]=='-')
    negativo=1;

  // Revisa si hay un punto
  for(i=0;i<s.size();i++)
     if(s[i]=='.')
       { punto=1; 
         i=s.size(); 
       }
  
  if(punto==0)
    { num=s[negativo]-'0';
      for(int i=negativo+1;i<s.size();i++)
         num=num*10+(s[i]-'0');
    }     
  else
    { num2=(s[s.size()-1]-'0')/10.0;
      for(int i=s.size()-2;s[i]!='.';i--)
         num2=num2/10.0+(s[i]-'0')/10.0;
         
      num=s[negativo]-'0';
      for(int i=negativo+1;s[i]!='.';i++)
         num=num*10+(s[i]-'0');
         
      num+=num2;
    }     

  
  
  if(negativo==1)
    num*=-1;
    
  return num;   
}



        /* =========================================================
           =                                                       =
           =               CAPTURAR DESDE ARCHIVO                  =
           =                                                       =
           =========================================================*/

/* El archivo debe indicar en el primer renglón la cantidad de polinomios
   2
   4x^4-4.2x^3+5x^2-1
   -3.2x^-5+1.9x^2-0.9x^2
*/



void POLINOMIO::demostracion_archivo()
{ 
  FILE* in=fopen("_Entrada.txt","r");
  int i,j,k,l;
  fscanf(in,"%d",&i);
  if(i<1)
    { fclose(in);
      return;
    }
  ofstream out("_Demostracion.txt");
  out<<"\n\n\tGuillermo Arriaga Garcia\tPROYECTO 1: Polinomios\n\n\n";
  char str2[100];  
  POLINOMIO* polin=new POLINOMIO[i+1];
  
  out<<"\n\n\tLos polinomios capturados desde Entrada.txt son:\n";
  for(j=1;j<=i;j++)
  { fscanf(in,"%s",str2);
    polin[j].capturar((string)str2);
    out<<"\n\t"<<j<<".- ";
    out<<polin[j];
  }
  fclose(in);

  out<<"\n\n\n\tPOLINOMIOS A OPERAR:\n\t********************\n\t";   
  for(j=1;j<=i;j++)
      { out<<"\n\t p"<<j<<" -> "; 
        out<<polin[j];
      }  
      out<<"\n\n\t********************\n\n\n\t";
      l=9*(i*(i-1))/2;  // 9 veces i Comb 2
      POLINOMIO* pol2=new POLINOMIO[l];
      l=0;
      int m;
      for(k=1;k<=i;k++)
       for(j=k;j<=i;j++)
      { 
        out<<"\n\n\n\tSUMA: p"<<k<<" + p"<<j<<"\n\n\t";
        pol2[l]=(polin[k]+polin[j]);
        out<<pol2[l]<<"\n\t"<<" p("<<(m=(rand()%10))<<") = "
           <<pol2[l].evaluar(m);
        l++;

        out<<"\n\n\n\tRESTA: p"<<k<<" - p"<<j<<"\n\n\t";
        pol2[l]=(polin[k]-polin[j]);
        out<<pol2[l]<<"\n\t"<<" p("<<(m=(rand()%10))<<") = "
           <<pol2[l].evaluar(m);
        l++;

        out<<"\n\n\n\tMULTIPLICACION: p"<<k<<" * p"<<j<<"\n\n\t";
        pol2[l]=(polin[k]*polin[j]);
        out<<pol2[l]<<"\n\t"<<" p("<<(m=(rand()%10))<<") = "
           <<pol2[l].evaluar(m);
        l++;

        out<<"\n\n\n\n\t\t\t* * *  *  * * *\n\n";
      }
                 
      delete [] pol2;
      delete [] polin;
      out.close(); 
}
