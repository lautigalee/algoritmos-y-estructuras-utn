#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void CargarMatriz(int n, int m);
void MayorNum(int n, int m);
void GenerarVector(int n, int m);
void MostrarVector(int m);
void OrdenarVector(int m);
int matriz[6][5];
int VECMIN[30];
int main() {
	srand(time(NULL));
    int n, m;
    do {
        printf("Ingrese la cantidad de filas de la matriz: ");
        scanf("%d", &n);
    }
    while(n <= 0 || n >= 6);
    do {
        printf("Ingrese la cantidad de columnas de la matriz: ");
        scanf("%d", &m);
    }
    while(m <= 0 || m >= 5);
    CargarMatriz(n, m);
    MayorNum(n, m);
    GenerarVector(n, m);
    MostrarVector(m);
    OrdenarVector(m);
    MostrarVector(m);
	return 0;
}
void CargarMatriz(int n, int m) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            matriz[i][j] = rand() % 90 + 10;
        }
    }
}
void MayorNum(int n, int m) {
    int mayor = matriz[0][0], fila = 0, columna = 0, i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(matriz[i][j] > mayor) {
                mayor = matriz[i][j];
                fila = i;
                columna = j;
            }
        }
    }
    printf("El mayor numero generado fue %d, en la fila %d y la columna %d ", mayor, fila, columna);
}
void GenerarVector(int n, int m) {
    int i, j, menor;
    for(j = 0; j < m; j++) {
        menor = matriz[0][j];
        for(i = 1; i < n; i++) {
            if(matriz[i][j] < menor) {
                menor = matriz[i][j];
            }
        }
        VECMIN[j] = menor;
    }
}
void MostrarVector(int m) {
    int i;
    for(i = 0; i < m; i++) {
        printf("%d ", VECMIN[i]);
    }
    printf("\n");
}
void OrdenarVector(int m) {
    int i, j, aux;
    for(i = 0; i < m-1; i++) {
        for(j = 0; j < m-1 - i; j++) {
            if(VECMIN[j+1] < VECMIN[j]) {
                aux = VECMIN[j];
                VECMIN[j] = VECMIN[j+1];
                VECMIN[j+1] = aux;
            }
        }
    }
}