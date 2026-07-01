#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void calcularFrecuencias(int frec[]);
void mostrarGrafico(int frec[]);
int main() {
	int frecuencias[10] = {0};
    srand(time(NULL));
    calcularFrecuencias(frecuencias);
    mostrarGrafico(frecuencias);
	return 0;
}
void calcularFrecuencias(int frec[]) {
    int i, decena, numero;
    for(i = 0; i < 80; i++) {
        numero = rand() % 100;
        decena = numero/10;
        frec[decena] ++;
    }
}
void mostrarGrafico(int frec[]) {
    int i, j;
    for(i = 0; i < 10; i++) {
        printf("%2d - %2d I ", i * 10, (i * 10) + 9);
        for(j = 0; j < frec[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}