#include <stdio.h>
void cargarVector (int vector[], int tam);
void generarFilaTres(int f1[], int f2[], int tamOriginal, int f3[]);
void mostrarVector(int vector[], int tam);
int main() {
	int filauno [30], filados [30], filatres [60], n;
	do {
		printf("Ingrese la cantidad de elementos de cada fila (entre 1 y 29)");
		scanf("%d", &n);
	}
	while(n <= 0 || n >= 30);
	cargarVector(filauno, n);
	cargarVector(filados, n);
	generarFilaTres(filauno, filados, n, filatres);
	mostrarVector(filauno, n);
	mostrarVector(filados, n);
	mostrarVector(filatres, 2*n);
	return 0;
}
void cargarVector (int vector[], int tam) {
	int i, dni;
	for (i = 0; i < tam; i++) {
		printf("Ingrese los 3 ultimos digitos de su DNI: ");
		scanf("%d", &dni);
		vector[i] = dni;
	}
}
void generarFilaTres(int f1[], int f2[], int tamOriginal, int f3[]) {
	int i;
	for(i = 0; i < tamOriginal; i++) {
		f3[2 * i] = f2[i];
		f3[(2 * i) + 1] = f1[i];
	}
}
void mostrarVector(int vector[], int tam) {
	int i;
	for (i = 0; i < tam; i++) {
		printf("[%d]", vector[i]);
	}
	printf("\n");
}