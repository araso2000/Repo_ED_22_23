//En este archivo ya implementamos la funcionalidad predefinida en la cabecera

#include "Racional.h" //Hay que importar la cabecera para que se tengan en cuenta las funciones y los objetos definidos
#include "stdio.h" 
#include "stdlib.h" 
#include "math.h" 
#include "assert.h" 


int calcularMaximoComunDivisor(int operando1, int operando2) {
	assert(operando1 >= 0 && operando2 >= 0);//Nos permite comprobar precondiciones de variables.
    //Si no se cumplen, se cierra el programa indicando la violación

	while (operando2 != 0) {
		int resto = operando1 % operando2; 
		operando1 = operando2;
		operando2 = resto;
	}
	return(operando1);
}

Racional crearRacional(int nuevoNumerador, int nuevoDenominador) {
	assert(nuevoDenominador != 0);

	if (nuevoDenominador < 0) {
		nuevoDenominador = -nuevoDenominador;
		nuevoNumerador = -nuevoNumerador;
	}

	Racional r;
	r.numerador = nuevoNumerador;
	r.denominador = nuevoDenominador;

	return (r);
}

Racional sumar(Racional sumando1, Racional sumando2) {
	int numerador1 = sumando1.numerador;
	int denominador1 = sumando1.denominador;
	int numerador2 = sumando2.numerador;
	int denominador2 = sumando2.denominador;

	int nuevoDenominador;
	int nuevoNumerador;   

	nuevoDenominador = denominador1 * denominador2;

	numerador1 = numerador1 * denominador2;
	numerador2 = numerador2 * denominador1;

	nuevoNumerador = numerador1 + numerador2;

	Racional r;
	r.numerador = nuevoNumerador;
	r.denominador = nuevoDenominador;
	return (r);
}

Racional multiplicar(Racional multiplicador1, Racional multiplicador2) {
	int nuevoNumerador = multiplicador1.numerador * multiplicador2.numerador;
	int nuevoDenominador = multiplicador1.denominador * multiplicador2.denominador;

	Racional r;
	r.numerador = nuevoNumerador;
	r.denominador = nuevoDenominador;
	return (r);
}

void simplificar(Racional* racional) {
	int maximoComunDivisor; 
	maximoComunDivisor = calcularMaximoComunDivisor(abs(racional->numerador), abs(racional->denominador));
	racional->numerador = racional->numerador / maximoComunDivisor;
	racional->denominador = racional->denominador / maximoComunDivisor;
}

void escribir(Racional racional) {
	if (racional.numerador == 0 || racional.denominador == 1){
        printf("%d", racional.numerador);
    }else{ 
        printf("%d/%d", racional.numerador, racional.denominador); 
    }
}
