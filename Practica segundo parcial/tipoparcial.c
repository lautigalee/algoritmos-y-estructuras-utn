#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void cargarMatriz(int matriz[5][6], int n, int m);
void mostrarMatriz(int matriz[5][6], int n, int m);
void buscarMayor(int matriz[5][6], int n, int m);
void generarVecMax(int matriz[5][6], int n, int m, int vector[30]);
void ordenarVector(int vector[30], int n);
void mostrarVector(int vector[30], int n);
int main() {
    int n, m, matriz[5][6], vector[30];
    do {
        printf("Ingrese N: ");
        scanf("%d", &n);
    } while(n <= 0 || n >= 5);
    do {
        printf("Ingrese M: ");
        scanf("%d", &m);
    } while(m <= 0 || m >= 6);
    srand(time(NULL));
    cargarMatriz(matriz, n, m);
    printf("\nMATRIZ GENERADA:\n");
    mostrarMatriz(matriz, n, m);
    buscarMayor(matriz, n, m);
    generarVecMax(matriz, n, m, vector);
    printf("\nVECTOR MAXIMO POR FILA:\n");
    mostrarVector(vector, n);
    ordenarVector(vector, n);
    printf("\nVECTOR ORDENADO:\n");
    mostrarVector(vector, n);
    return 0;
}
void cargarMatriz(int matriz[5][6], int n, int m) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            matriz[i][j] = rand() % 100;
        }
    }
}
void mostrarMatriz(int matriz[5][6], int n, int m) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}
void buscarMayor(int matriz[5][6], int n, int m) {
    int i, j;
    int mayor = matriz[0][0];
    int filaMayor = 0;
    int columnaMayor = 0;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(matriz[i][j] > mayor) {
                mayor = matriz[i][j];
                filaMayor = i;
                columnaMayor = j;
            }
        }
    }
    printf("\nEl mayor numero fue: %d\n", mayor);
    printf("Se encuentra en la posicion [%d][%d]\n", filaMayor, columnaMayor);
}
void generarVecMax(int matriz[5][6], int n, int m, int vector[30]) {
    int i, j;
    int maximo;
    for(i = 0; i < n; i++) {
        maximo = matriz[i][0];
        for(j = 1; j < m; j++) {
            if(matriz[i][j] > maximo) {
                maximo = matriz[i][j];
            }
        }
        vector[i] = maximo;
    }
}
void ordenarVector(int vector[30], int n) {
    int i, j, aux;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - 1 - i; j++) {
            if(vector[j] > vector[j+1]) {
                aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
            }
        }
    }
}
void mostrarVector(int vector[30], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}
