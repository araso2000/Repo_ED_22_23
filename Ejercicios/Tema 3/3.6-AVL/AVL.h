#pragma once

typedef struct Nodo{
    int contenido;
    struct Nodo *padre;
    struct Nodo *hijoIzquierdo;
    struct Nodo *hijoDerecho;
    int altura;
    int factorEquilibrio;
}Nodo;

typedef struct AVL{
    Nodo *raiz;
    int n;
}AVL;

AVL* construirAVL();

Nodo* buscarRecursivo(Nodo *raizSubarbol, int elementoABuscar);

int buscar(AVL *arbol, int elementoABuscar);

void imprimirRecursivo(Nodo *raizSubarbol, int numeroTabulaciones, int orientacion);

void imprimir(AVL *arbol);

void eliminarSubarbol(AVL *arbol, Nodo *raizSubarbol);

void destruirAVL(AVL *arbol);

void actualizarAlturaYFactorDeEquilibrio(Nodo *nodo);

void setHijo(Nodo *padre, Nodo *nuevoHijo, int lado);

void cambiarHijo(AVL *arbol, Nodo *antiguoHijo, Nodo *nuevoHijo);

Nodo* rotarSimpleIzquierda(AVL *arbol, Nodo* raizSubarbol);

Nodo* rotarSimpleDerecha(AVL *arbol, Nodo* raizSubarbol);

Nodo* rotarCompuestaDerechaIzquierda(AVL *arbol, Nodo* raizSubarbol);

Nodo* rotarCompuestaIzquierdaDerecha(AVL *arbol, Nodo* raizSubarbol);

Nodo* insertarHoja(AVL* arbol, int nuevoElemento);

void reequilibrar(AVL *arbol, Nodo* hoja);

void insertar(AVL* arbol, int nuevoElemento);