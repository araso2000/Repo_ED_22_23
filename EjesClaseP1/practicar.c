#include <stdio.h>
#include <stdlib.h>

struct Ficha{
    char* nombre;
    int edad;
};

int main(){
    int i; //Variable normal
    int* p; //Puntero 
    p = NULL; //Puntero ahora apunta a NULL
    i = 7;
    p = &i; //El puntero p apunta a la dirección hexadecimal de la variable i, osea, al contenido entonces de i
    printf("%d\n",p); //Imprimo la direccion de memoria de p
    printf("%d\n",*p); //Imprimo el contenido al que apunta p
    *p = 3; //Ahora el puntero p apunta a 3
    printf("%d\n",p); //Imprimo la direccion de memoria de p
    printf("%d\n",*p); //Imprimo el contenido al que apunta p


    int* a;
    a = (int*) malloc (sizeof(int));    
    free(a);

    int* array = (int*) malloc (3*sizeof(int));
    *a = 1;
    *(a+1) = 2;
    *(a+2) = 3;
}