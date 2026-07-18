#include <stdio.h>
void generarMatrizUnidad(int matriz[10][10], int n);
void mostrarMatriz(int matriz[10][10], int n);
int main() {
	int matriz[10][10], tam;
    do {
    printf("Ingrese la dimension de la matriz: ");
    scanf("%d", &tam);
    }
    while(tam <= 0 || tam > 10);
    generarMatrizUnidad(matriz, tam);
    mostrarMatriz(matriz, tam);
	return 0;
}
void generarMatrizUnidad(int matriz[10][10], int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i == j) {
                matriz[i][j] = 1;
            }
            else {
                matriz[i][j] = 0;
            }
        }
    }
}
void mostrarMatriz(int matriz[10][10], int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}