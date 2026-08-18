#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void GenerarMatriz(int n, int m);
void MenorNum(int n, int m);
void GenerarVector(int n, int m);
void MostrarVector(int n);
void OrdenarVector(int n);
int matriz[5][4];
int VECMAX[20];
int main() {
    srand(time(NULL));
	int n, m;
    do {
        printf("Ingrese la cantidad de filas de la matriz: ");
        scanf("%d", &n);
    }
    while(n <= 0 || n >= 5);
    do {
    printf("Ingrese la cantidad de columnas de la matriz: ");
    scanf("%d", &m);
    }
    while(m <= 0 || m >= 4);
    GenerarMatriz(n, m);
    MenorNum(n, m);
    GenerarVector(n, m);
    MostrarVector(n);
    OrdenarVector(n);
    MostrarVector(n);
	return 0;
}
void GenerarMatriz(int n, int m) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            matriz[i][j] = rand() % 100;
        }
    }
}
void MenorNum(int n, int m) {
    int i, j;
    int menor = matriz[0][0], menorfila = 0, menorcolumna = 0;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(matriz[i][j] < menor) {
                menor = matriz[i][j];
                menorfila = i;
                menorcolumna = j;
            }
        }
    }
    printf("El menor numero generado fue %d, correspondiente a la fila %d y a la columna %d", menor, menorfila, menorcolumna);
}
void GenerarVector(int n, int m) {
    int i, j;
    int max;
    for(i = 0; i < n; i++) {
    max = matriz[i][0];
        for(j = 1; j < m; j++) {
            if(matriz[i][j] > max) {
                max = matriz[i][j];
            }
        }
        VECMAX[i] = max;
    }
}
void MostrarVector(int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", VECMAX[i]);
    }
}
void OrdenarVector(int n) {
    int i, j, aux;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-1 - i; j++) {
            if(VECMAX[j+1] > VECMAX[j]) {
                aux = VECMAX[j];
                VECMAX[j] = VECMAX[j+1];
                VECMAX[j+1] = aux;
            }
        }
    }
}