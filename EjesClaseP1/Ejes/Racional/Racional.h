//Una cabecera sirve para definir los objetos y funciones que vayamos a usar

typedef struct { 
	int numerador; // Numerador
	int denominador; // Denominador. Precondici�n: denominador > 0
} Racional;

int calcularMaximoComunDivisor(int operando1, int operando2);

Racional crearRacional(int nuevoNumerador, int nuevoDenominador);

Racional sumar(Racional sumando1, Racional sumando2);

Racional multiplicar(Racional multiplicador1, Racional multiplicador2);

void simplificar(Racional *racional);

void escribir(Racional racional);
