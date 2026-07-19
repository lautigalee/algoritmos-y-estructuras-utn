#include <stdio.h>
void cargarMatriz(int matriz[10][10], int n);
void intercambiarTriangulares(int matriz[10][10], int n);
void mostrarMatriz(int matriz[10][10], int n);
int main() {
	int matriz[10][10];
int n;
do {
    printf("Ingrese el tamaño de la matriz: ");
    scanf("%d", &n);
} while(n <= 0 || n > 10);
cargarMatriz(matriz, n);
intercambiarTriangulares(matriz, n);
mostrarMatriz(matriz, n);
	return 0;
}
void cargarMatriz(int matriz[10][10], int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("Ingrese el elemento [%d][%d] de la matriz: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}
void intercambiarTriangulares(int matriz[10][10], int n) {
    int i, j, aux;
    for(i = 0; i < n; i++) {
    for(j = i + 1; j < n; j++) {
        aux = matriz[i][j];
        matriz[i][j] = matriz[j][i];
        matriz[j][i] = aux;
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