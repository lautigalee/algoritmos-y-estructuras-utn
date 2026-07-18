#include <stdio.h>
void cargarMatriz(int matriz[5][5]);
int detectarPares(int matriz[5][5]);
void generarResumen(int matriz[5][5], int vector[5]);
void mostrarVector(int vector[5]);
void buscarCeros(int matriz[5][5]);
int main() {
	int matriz[5][5], vector[5], pares = 0;
    cargarMatriz(matriz);
    pares = detectarPares(matriz);
    printf("Cantidad de lecturas no confiables: %d\n", pares);
    generarResumen(matriz, vector);
    mostrarVector(vector);
    buscarCeros(matriz);
	return 0;
}
void cargarMatriz(int matriz[5][5]) {
    int i, j;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("Ingrese el elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}
int detectarPares(int matriz[5][5]) {
    int i, j, pares = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            if(matriz[i][j] % 2 == 0) {
                pares++;
                matriz[i][j] = -1;
            }
        }
    }
    return pares;
}
void generarResumen(int matriz[5][5], int vector[5]) {
    int i, j, cantidad;
    for(i = 0; i < 5; i++) {
        cantidad = 0;
        for(j = 0; j < 5; j++) {
            if(matriz[i][j] == -1) {
                cantidad++;
            }
        }
        vector[i] = cantidad;
            if(cantidad == 5) {
                printf("La fila %d esta completamente invalida\n", i);
            }
    }
}
void mostrarVector(int vector[5]) {
    int i;
    for(i = 0; i < 5; i++) {
        printf("Fila %d: [%d] errores\n", i, vector[i]);
    }
}
void buscarCeros(int matriz[5][5]) {
    int i, j, encontrado = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            if(matriz[i][j] == 0) {
                printf("0 Encontrado en la posicion [%d] [%d]\n", i, j);
                encontrado = 1;
            }
        }
    }
    if(encontrado == 0) {
        printf("No se encontro ningun 0");
    }
}