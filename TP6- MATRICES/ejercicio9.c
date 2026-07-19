#include <stdio.h>
void cargarCompetidores(int matriz[3][100], int n);
void cargarGanadores(int vector[100], int n);
int estaEnGanadores(int vector[100], int n, int numero);
int generarResto(int competidores[3][100], int ganadores[100], int resto[3][100], int n);
void mostrarMatriz(int matriz[3][100], int columnas);
int main() {
    int competidores[3][100];
    int ganadores[100];
    int resto[3][100];
    int n;
    int m;
    do {
        printf("Ingrese la cantidad de competencias: ");
        scanf("%d", &n);
    } 
    while(n <= 0 || n > 100);
    cargarCompetidores(competidores, n);
    cargarGanadores(ganadores, n);
    m = generarResto(competidores, ganadores, resto, n);
    mostrarMatriz(resto, m);
    return 0;
}
void cargarCompetidores(int matriz[3][100], int n) {
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < n; j++) {
            do {
                printf("Ingrese el numero de identificacion del competidor: ");
                scanf("%d", &matriz[i][j]);
            }
            while(matriz[i][j] < 100 || matriz[i][j] > 999);
        }
    }
}
void cargarGanadores(int vector[100], int n) {
    int i;
    for(i = 0; i < n; i++) {
        do {
            printf("Ingrese el numero de identificacion del competidor: ");
            scanf("%d", &vector[i]);
        }
        while(vector[i] < 100 || vector[i] > 999);
    }
}
int estaEnGanadores(int vector[100], int n, int numero) {
    int i;
for(i = 0; i < n; i++) {
    if(vector[i] == numero) {
        return 1;
    }
}
return 0;
}
int generarResto(int competidores[3][100], int ganadores[100], int resto[3][100], int n) {
    int k = 0, j;
    for(j = 0; j < n; j++) {
        if(estaEnGanadores(ganadores, n, competidores[0][j]) == 0) {
            resto[0][k] = competidores[0][j];
            resto[1][k] = competidores[1][j];
            resto[2][k] = competidores[2][j];
            k++;
        }
    }
    return k;
}
void mostrarMatriz(int matriz[3][100], int columnas) {
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}