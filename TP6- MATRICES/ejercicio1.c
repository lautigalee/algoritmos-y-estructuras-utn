#include <stdio.h>
#include <stdlib.h>
void cargarMatrizPares(int matriz[4][4]);
void mostrarMatriz(int matriz[4][4]);
int main() {
	int matriz[4][4];
    cargarMatrizPares(matriz);
    mostrarMatriz(matriz);
	return 0;
}
void cargarMatrizPares(int matriz[4][4]) {
    int i, j, numero;
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
            numero = 2 * (rand() % 45 + 5);
            matriz[i][j] = numero;
        }
    }
}
void mostrarMatriz(int matriz[4][4]) {
    int i, j;
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}