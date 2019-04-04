
// GAG 4-2-11 Biblioteca de VECTORES N-D

// VECTORES en nd

#ifndef VECTOR_nd_H
#define VECTOR_nd_H

class vector
{
   private:
            int n;
            double* datos;

   public:
            vector();                                 // Constructor default
            vector(int tamano, double* arr);          // Constructor
            ~vector();                                // Destructor de punteros
            vector(int tamano);                       // Para crear el datos[]
            double ProductoPunto (vector &a);
            int size();                               // Regresa n (tamano)
            void set (int pos, double val);           // Para capturar
            double get (int pos);                     // Para obtener un valor
            void set (double val);               // A todos les pone cierto valor            
            void set (int ini, int fin, double val); // A los del intervalo les pone cierto valor
            void guarda(char* file);   // Imprime en un archivo todo el arreglo
            vector operator+(vector &a);
            vector operator-(vector &a);
            vector operator*(double c);       // Multi. por escalar por derecha
            
};

#endif
