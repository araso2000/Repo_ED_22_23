#include <stdio.h>
#include <stdlib.h>

double serie(double x, int n){ //2 elementales por 2 parametros
    double s; //1 elemental por creacion
    int ii; //1 elemental por creacion
    s = 0.0; //1 elemental por asigancion

    for(ii = 1 ; ii <= n; ii++){ //3 elemental por asignacion, comparacion y suma
        s += ii*x;               //3 elemental por suma, asignacion y multiplicacion
    }
    //Esto se repite n veces mas 1 elemental por la comprobacion final que no entra en el bucle
    //TOTAL: 3 * 3 * n = 9n+1
    return s; //1 elemental                   
}//TOTAL: 9n+7



int main(){
    int i;
    int* p;
    p = NULL;
    i = 7;
    p = &i; // Asignar la dirección de la variable i a p.
    *p = 5; // Cambiar el contenido de lo apuntado por p.
    printf("%d\n",i); // Escribe el valor 3.
}

