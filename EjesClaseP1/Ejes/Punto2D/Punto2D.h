typedef struct{
    double x;
    double y;
}Punto2D;

Punto2D crear(double x, double y);

Punto2D desplazar(Punto2D punto, double despX, double despY);

double calcularDistanciaOrigen(Punto2D punto);

void imprimir(Punto2D punto);