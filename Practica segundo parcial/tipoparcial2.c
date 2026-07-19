#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void cargarMatriz(int matriz[4][5], int n, int m);
void mostrarMayor(int matriz[4][5], int n, int m);
void generarVecMin(int matriz[4][5], int vecMin[5], int n, int m);
void ordenarVector(int vecMin[], int m);
void mostrarVector(int vecMin[], int m);
int main() {
    int n, m, matriz[4][5], vecMin[5];
	do {
    printf("Ingrese N: ");
    scanf("%d", &n);
} while(n <= 0 || n >= 4);
do {
    printf("Ingrese M: ");
    scanf("%d", &m);
} while(m <= 0 || m >= 5);
srand(time(NULL));
cargarMatriz(matriz, n, m);
mostrarMayor(matriz, n, m);
generarVecMin(matriz, vecMin, n, m);
ordenarVector(vecMin, m);
mostrarVector(vecMin, m);
	return 0;
}
void cargarMatriz(int matriz[4][5], int n, int m) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            matriz[i][j] = rand() % 100;
        }
    }
}
void mostrarMayor(int matriz[4][5], int n, int m) {
    int i, j, mayor, filaMayor, columnaMayor;
    mayor = matriz[0][0];
    filaMayor = 0;
    columnaMayor = 0;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(matriz[i][j] > mayor) {
                mayor = matriz[i][j];
                filaMayor = i;
                columnaMayor = j;
            }
        }
    }
    printf("El mayor numero fue %d\n", mayor);
    printf("La posicion mayor es [%d][%d]\n", filaMayor, columnaMayor);
}
void generarVecMin(int matriz[4][5], int vecMin[5], int n, int m) {
    int i, j;
    int minimo;
    for(j = 0; j < m; j++){
    minimo = matriz[0][j];
        for(i = 1; i < n; i++){
            if(matriz[i][j] < minimo)
            {
                minimo = matriz[i][j];
            }
        }
        vecMin[j] = minimo;
    }
}
void ordenarVector(int vecMin[], int m) {
    int i, j, aux;
    for(i = 0; i < m-1; i++) {
        for(j = 0; j < m-1 - i; j++) {
            if(vecMin[j] > vecMin[j+1]) {
                aux = vecMin[j];
                vecMin[j] = vecMin[j+1];
                vecMin[j+1] = aux;
            }
        }
    }
}
void mostrarVector(int vecMin[], int m) {
    int i;
    for(i = 0; i < m; i++) {
        printf("%d ", vecMin[i]);
    }
}