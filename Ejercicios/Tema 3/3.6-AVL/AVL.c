#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "AVL.h"

AVL* construirAVL(){
    AVL *arbol = (AVL*)malloc(sizeof(AVL));
    arbol->n = 0;
    arbol->raiz = NULL;

    return(arbol);
}

Nodo* buscarRecursivo(Nodo *raizSubarbol, int elementoABuscar){ //Mismo que en un ABB
    assert(raizSubarbol != NULL);

    if(raizSubarbol->contenido == elementoABuscar){ //Si el elemento buscado es la raizSubarbol
        return(raizSubarbol);
    }else if(elementoABuscar < raizSubarbol->contenido){ //Si el elemento buscado es menor que la raizSubarbol
        if(raizSubarbol->hijoIzquierdo == NULL){ //Si no tiene hizo izquierdo (menor) devolvemos el padre
            return(raizSubarbol);
        }else{ //Si no seguimos buscando por el subarbol izquierdo
            return(buscarRecursivo(raizSubarbol->hijoIzquierdo, elementoABuscar));
        }
    }else{ //Si el elemento buscado es mayor que la raizSubarbol
        if(raizSubarbol->hijoDerecho == NULL){ //Si no tiene hizo derecho (mayor) devolvemos el padre
            return(raizSubarbol);
        }else{ //Si no seguimos buscando por el subarbol derecho
            return(buscarRecursivo(raizSubarbol->hijoDerecho, elementoABuscar));
        }
    }
}

int buscar(AVL *arbol, int elementoABuscar){
    assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido
	if (arbol->n == 0){
        return(0); //Obviamente si el arbol está vacio no tendrá nada que buscar
    }else {
		Nodo* nodo = buscarRecursivo(arbol->raiz, elementoABuscar);
		if (nodo->contenido == elementoABuscar){
            return(1); //Si coincide TRUE
        }else{
            return (0);
        }
	}
}

void imprimirRecursivo(Nodo *raizSubarbol, int numeroTabulaciones, int orientacion){
    assert(raizSubarbol != NULL);
	assert(numeroTabulaciones >= 0);
	assert(orientacion == 1 || orientacion == -1 || orientacion == 0);

	for (int i = 0; i < numeroTabulaciones; i++){
        printf("\t");
    }
	printf("%d", raizSubarbol->contenido);
	if (orientacion == -1){
        printf("(izq)");
    }
	if (orientacion == 1){
        printf("(der)");
    }
	printf("\n");

	if (raizSubarbol->hijoIzquierdo != NULL){ //Si tiene hijo izquierdo
        imprimirRecursivo(raizSubarbol->hijoIzquierdo, numeroTabulaciones + 1, -1);
    }
	if (raizSubarbol->hijoDerecho != NULL){ //Si tiene hijo derecho
        imprimirRecursivo(raizSubarbol->hijoDerecho, numeroTabulaciones + 1, 1);
    }
}

void imprimir(AVL *arbol){
    assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido

    if(arbol->n > 0){
        imprimirRecursivo(arbol->raiz, 0, 0);
    }else{
        printf("Arbol vacio\n");
    }
}

void eliminarSubarbol(AVL *arbol, Nodo *raizSubarbol){
    assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido
	assert(raizSubarbol != NULL);

    if(raizSubarbol->hijoDerecho != NULL){ //Si existe el hijo derecho
        eliminarSubarbol(arbol,raizSubarbol->hijoDerecho); //Recursivamente borramos el subarbol derecho
    }
    if(raizSubarbol->hijoIzquierdo != NULL){ //Si existe el hijo izquierdo
        eliminarSubarbol(arbol,raizSubarbol->hijoIzquierdo); //Recursivamente borramos el subarbol izquierdo
    }

    Nodo *padre = raizSubarbol->padre;

    if(padre != NULL){ //Si la raiz tiene padre
        if(padre->hijoIzquierdo == raizSubarbol){ //Si la raiz es el hijo derecho de su padre, le quitamos la referencia
            padre->hijoIzquierdo = NULL;
        }
        if(padre->hijoDerecho == raizSubarbol){ //Si es el hijo izquierdo haremos lo mismo
            padre->hijoDerecho = NULL;
        }
    }else{ //Si no tiene padre pues borramos la raiz del arbol
        arbol->raiz = NULL;
    }

    free(raizSubarbol);
    arbol->n--;
}

void destruirAVL(AVL *arbol){
    assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido
	if (arbol->n > 0){
        eliminarSubarbol(arbol, arbol->raiz);
    }
	free(arbol);
}

void actualizarAlturaYFactorDeEquilibrio(Nodo *nodo){
    assert(nodo != NULL);

    int alturaHijoIzquierdo = -1; //-1 significa que no existe
    if(nodo->hijoIzquierdo != NULL){ //Altura del hijo izquierdo si existe
        alturaHijoIzquierdo = nodo->hijoIzquierdo->altura;
    }

    int alturaHijoDerecho = -1;
    if(nodo->hijoDerecho != NULL){ //Altura del hijo derecho si existe
        alturaHijoDerecho = nodo->hijoDerecho->altura;
    }

    //Calculamos segun la teoria la altura del nodo pasado por parametro
    if(alturaHijoIzquierdo >= alturaHijoDerecho){ 
        nodo->altura = alturaHijoIzquierdo + 1;
    }else{
        nodo->altura = alturaHijoDerecho + 1;
    }

    nodo->factorEquilibrio = (alturaHijoDerecho - alturaHijoIzquierdo);
}

//Método básico para darle hijos a un padre y configurar ese nodo
void setHijo(Nodo *padre, Nodo *nuevoHijo, int lado){
    assert(padre != NULL);
    assert(lado == 0 | lado == 1); // 0 = derecho / 1 = izquierdo

    if(lado == 0){
        padre->hijoDerecho = nuevoHijo;
    }else{
        padre->hijoIzquierdo = nuevoHijo;
    }

    if(nuevoHijo != NULL){
        nuevoHijo->padre = padre;
    }
}

void cambiarHijo(AVL *arbol, Nodo *antiguoHijo, Nodo *nuevoHijo){
    assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido
	assert(antiguoHijo != NULL);
	assert(nuevoHijo != NULL);

    Nodo *padre = antiguoHijo->padre; //Obtenemos el padre del nodo a sustituir

    if(padre == NULL){ //Si un nodo no tiene padre es porque es la raiz del arbol completo
        arbol->raiz = nuevoHijo;
        nuevoHijo->padre = NULL;
    }else{ //Si sí tiene padre
        if (padre->hijoDerecho == antiguoHijo){ //Si es el hijo derecho el cambio
            setHijo(padre, nuevoHijo, 0); //Diremos al metodo anterior que realice el cambio 
        }
		if (padre->hijoIzquierdo == antiguoHijo){ //Igual con el hijo izquierdo
            setHijo(padre, nuevoHijo, 1);
        }
    }
    antiguoHijo->padre = NULL; //El nodo sustituido ha perdido a su padre
}

Nodo* rotarSimpleIzquierda(AVL *arbol, Nodo* raizSubarbol){
    assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido

	// Precondición: la raiz existe y tiene un factor de equilibrio de 2
	assert(raizSubarbol != NULL);
	assert(raizSubarbol->factorEquilibrio == 2);

	// Precondición: el hijo derecho existe y tiene un factor de equilibrio de 1
	Nodo* hijoDerecho = raizSubarbol->hijoDerecho; // Hijo derecho de la raiz 
	assert(hijoDerecho != NULL);
	assert(hijoDerecho->factorEquilibrio == 1);

	// Para mayor claridad, vamos a usar la nomenclatura de 
	// la diapositiva que explica esta rotación: "x", "y", "A", "B" y "C"
	// No necesitamos guardar ni "A" ni "C" porque no cambian de sitio
	Nodo* x = raizSubarbol;
	Nodo* y = hijoDerecho;
	Nodo* B = y->hijoIzquierdo;

	// Hacemos que el padre de "x" pase a apuntar a "y" en vez de a "x"
	cambiarHijo(arbol, x, y);

	// Hacemos que "B" sea hijo derecho de "x"
	setHijo(x, B, 0);

	// Hacemos que "x" sea hijo izquierdo de "y"
	setHijo(y, x, 1);

	// Recalculamos las alturas de "x" e "y", en este orden
	actualizarAlturaYFactorDeEquilibrio(x);
	actualizarAlturaYFactorDeEquilibrio(y);

	// Devolvemos la nueva raiz del subarbol
	return(y);
}

Nodo* rotarSimpleDerecha(AVL *arbol, Nodo* raizSubarbol){
    assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido

	// Precondición: la raiz existe y tiene un factor de equilibrio de -2
	assert(raizSubarbol != NULL);
	assert(raizSubarbol->factorEquilibrio == -2);

	// Precondición: el hijo izquierdo existe y tiene un factor de equilibrio de -1
	Nodo* hijoIzquierdo = raizSubarbol->hijoIzquierdo; // Hijo izquierdo de la raiz 
	assert(hijoIzquierdo != NULL);
	assert(hijoIzquierdo->factorEquilibrio == -1);

	// Para mayor claridad, vamos a usar la nomenclatura de 
	// la diapositiva que explica esta rotación: "x", "y", "A", "B" y "C"
	// No necesitamos guardar ni "A" ni "C" porque no cambian de sitio
	Nodo* x = hijoIzquierdo;
	Nodo* y = raizSubarbol;
	Nodo* B = x->hijoDerecho;

	// Hacemos que el padre de "y" pase a apuntar a "x" en vez de a "y"
	cambiarHijo(arbol, y, x);

	// Hacemos que "B" sea hijo izquierdo de "y"
	setHijo(y, B, 1);

	// Hacemos que "y" sea hijo derecho de "x"
	setHijo(x, y, 0);

	// Recalculamos las alturas de "y" y "x", en este orden	
	actualizarAlturaYFactorDeEquilibrio(y);
	actualizarAlturaYFactorDeEquilibrio(x);

	// Devolvemos la nueva raiz del subarbol
	return(x);
}

Nodo* rotarCompuestaDerechaIzquierda(AVL *arbol, Nodo* raizSubarbol){
    assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido

	// Precondición: la raiz existe y tiene un factor de equilibrio de 2
	assert(raizSubarbol != NULL);
	assert(raizSubarbol->factorEquilibrio == 2);

	// Precondición: el hijo derecho existe y tiene un factor de equilibrio de -1
	Nodo* hijoDerecho = raizSubarbol->hijoDerecho; // Hijo derecho de la raiz 
	assert(hijoDerecho != NULL);
	assert(hijoDerecho->factorEquilibrio == -1);

	// Para mayor claridad, vamos a usar la nomenclatura de 
	// la diapositiva que explica esta rotación: "x", "y", "z", "A", "B", "C" y "D"
	// No necesitamos guardar ni "A" ni "D" porque no cambian de sitio
	Nodo* x = raizSubarbol;
	Nodo* z = hijoDerecho;
	Nodo* y = z->hijoIzquierdo;
	Nodo* B = y->hijoIzquierdo;
	Nodo* C = y->hijoDerecho;

	// Hacemos que el padre de "x" pase a apuntar a "y" en vez de a "x"
	cambiarHijo(arbol, x, y);

	// Hacemos que "B" sea hijo derecho de "x"
	setHijo(x, B, 0);

	// Hacemos que "C" sea hijo izquierdo de "z"
	setHijo(z, C, 1);

	// Hacemos que "x" y "z" sean hijos de "y"
	setHijo(y, x, 1);
	setHijo(y, z, 0);

	// Recalculamos las alturas de "x", "z" e "y", en este orden	
	actualizarAlturaYFactorDeEquilibrio(x);
	actualizarAlturaYFactorDeEquilibrio(z);
	actualizarAlturaYFactorDeEquilibrio(y);

	// Devolvemos la nueva raiz del subarbol
	return(y);
}

Nodo* rotarCompuestaIzquierdaDerecha(AVL *arbol, Nodo* raizSubarbol){
    assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido

	// Precondición: la raiz existe y tiene un factor de equilibrio de -2
	assert(raizSubarbol != NULL);
	assert(raizSubarbol->factorEquilibrio == -2);

	// Precondición: el hijo izquierdo existe y tiene un factor de equilibrio de 1
	Nodo* hijoIzquierdo = raizSubarbol->hijoIzquierdo; // Hijo izquierdo de la raiz 
	assert(hijoIzquierdo != NULL);
	assert(hijoIzquierdo->factorEquilibrio == 1);

	// Para mayor claridad, vamos a usar la nomenclatura de 
	// la diapositiva que explica esta rotación: "x", "y", "z", "A", "B", "C" y "D"
	// No necesitamos guardar ni "A" ni "D" porque no cambian de sitio
	Nodo* z = raizSubarbol;
	Nodo* x = hijoIzquierdo;
	Nodo* y = x->hijoDerecho;
	Nodo* B = y->hijoIzquierdo;
	Nodo* C = y->hijoDerecho;

	// Hacemos que el padre de "z" pase a apuntar a "y" en vez de a "z"
	cambiarHijo(arbol, z, y);

	// Hacemos que "B" sea hijo derecho de "x"
	setHijo(x, B, 0);

	// Hacemos que "C" sea hijo izquierdo de "z"
	setHijo(z, C, 1);

	// Hacemos que "x" y "z" sean hijos de "y"
	setHijo(y, x, 1);
	setHijo(y, z, 0);

	// Recalculamos las alturas de "x", "z" e "y", en este orden	
	actualizarAlturaYFactorDeEquilibrio(x);
	actualizarAlturaYFactorDeEquilibrio(z);
	actualizarAlturaYFactorDeEquilibrio(y);

	// Devolvemos la nueva raiz del subarbol
	return(y);
}

Nodo* insertarHoja(AVL* arbol, int nuevoElemento){
    assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido
	assert(!buscar(arbol, nuevoElemento)); // El nuevo elemento no estaba ya en el árbol

	// Creamos el nuevo nodo que contiene al elemento
	Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
	nuevoNodo->contenido = nuevoElemento;
	nuevoNodo->padre = NULL;
	nuevoNodo->hijoIzquierdo = NULL;
	nuevoNodo->hijoDerecho = NULL;
	nuevoNodo->altura = 0;
	nuevoNodo->factorEquilibrio = 0;

	// Si el arbol está vacío, lo metemos en la raiz sí o sí
	if (arbol->n == 0) {
		arbol->raiz = nuevoNodo;
	}else { // En caso contrario, buscamos el hueco en donde meterlo como una hoja
		// Buscamos el hueco
		Nodo* padreDelHueco = buscarRecursivo(arbol->raiz, nuevoElemento); // Puntero al nodo que es el padre del hueco

		// Metemos el nuevo nodo como hijo izquierdo o derecho
		if (nuevoElemento < padreDelHueco->contenido){ //Si es menor, irá a la izquierda
			setHijo(padreDelHueco, nuevoNodo, 1);
		}else{
			setHijo(padreDelHueco, nuevoNodo, 0);
		}
	}

	// Incrementamos el número de nodos
	arbol->n++;

	// Devolvemos puntero al nuevo nodo
	return(nuevoNodo);
}

void reequilibrar(AVL *arbol, Nodo* hoja){
    assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido
	assert(hoja != NULL);

	// Desde el padre de la hoja, vamos ascendiendo hasta llegar a la raíz.
	// No necesitamos comprobar la hoja, ya que al ser una hoja su altura es 0 y su factor
	// de equilibrio siempre es 0.
	// Por cada nodo que examinamos, actualizamos su altura y su factor de equilibrio,
	// y finalmente rotamos en caso de que dicho factor de equilibrio sea 2 ó -2
	Nodo* nodoActual = hoja->padre; // Calculamos el padre de la hoja inicial
	while (nodoActual != NULL) {

		// Primero calculamos la altura del nodo y su factor de equilibrio
		actualizarAlturaYFactorDeEquilibrio(nodoActual);
		int factorEquilibrio = nodoActual->factorEquilibrio;

		// Si el factor de equilibrio es 2, tenemos dos casos
		if (factorEquilibrio == 2) {
			int factorEquilibrioDerecho = nodoActual->hijoDerecho->factorEquilibrio;
			if (factorEquilibrioDerecho == 1){
				nodoActual = rotarSimpleIzquierda(arbol, nodoActual);
			}
			if (factorEquilibrioDerecho == -1){
				nodoActual = rotarCompuestaDerechaIzquierda(arbol, nodoActual);
			}
		}

		// Si el factor de equilibrio es -2, tenemos otros dos casos
		if (factorEquilibrio == -2) {
			int factorEquilibrioIzquierdo = nodoActual->hijoIzquierdo->factorEquilibrio;
			if (factorEquilibrioIzquierdo == -1){
				nodoActual = rotarSimpleDerecha(arbol, nodoActual);
			}
			if (factorEquilibrioIzquierdo == 1){
				nodoActual = rotarCompuestaIzquierdaDerecha(arbol, nodoActual);
			}
		}

		// En la siguiente iteracion, haremos lo mismo con el padre del nodo actual
		nodoActual = nodoActual->padre;
    }
}

void insertar(AVL* arbol, int nuevoElemento){
    assert(arbol != NULL && arbol->n >= 0); // Árbol tiene sentido
	assert(!buscar(arbol, nuevoElemento));

	// Insertamos el nuevo elemento como una hoja
	Nodo* hojaInsertada = insertarHoja(arbol, nuevoElemento);

	// Reequilibramos el árbol
	reequilibrar(arbol, hojaInsertada);
}