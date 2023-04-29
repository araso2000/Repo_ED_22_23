#include "Punto2D.h"
#include "math.h"
#include "stdio.h"

Punto2D crear(double x, double y){
    Punto2D nuevoPunto;
    nuevoPunto.x=x;
    nuevoPunto.y=y;
    
    return nuevoPunto;
}

Punto2D desplazar(Punto2D punto, double despX, double despY){
    Punto2D temp;
    temp.x = punto.x + despX;
    temp.y = punto.y + despY;

    return temp;
}

double calcularDistanciaOrigen(Punto2D punto){
    double sumaCuadrados = (punto.x * punto.x) + (punto.y * punto.y);
    return (sqrtf(sumaCuadrados));
}

void imprimir(Punto2D punto){
    printf("Punto: Coordenada x: %f ; Coordenada y: %f ; (%f,%f)\n\n", punto.x,punto.y,punto.x,punto.y);
}