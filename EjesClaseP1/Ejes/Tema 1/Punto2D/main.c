#include "stdio.h"
#include "Punto2D.h" 

int main(){
    Punto2D punto1 = crear(2.5,3.8);
    imprimir(punto1);
    punto1 = desplazar(punto1, -2.4, 1.0);
    imprimir(punto1);
    printf("Distancia al origen: %f\n\n", calcularDistanciaOrigen(punto1));
}