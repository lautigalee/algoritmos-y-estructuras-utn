#include <stdio.h>
int trasladarMayores50(int matriz[5][4], int vector[20]);
void matrizAVector(int matriz[5][4], int vector[20]);
void ordenarVector(int vector[20]);
void vectorAMatriz(int vector[20], int matriz[5][4]);
int main() {
int matriz[5][4];
int vectorMayores[20];
int vectorOrdenamiento[20];
int cantidad;
cantidad = trasladarMayores50(matriz, vectorMayores);
matrizAVector(matriz, vectorOrdenamiento);
ordenarVector(vectorOrdenamiento);
vectorAMatriz(vectorOrdenamiento, matriz);
	return 0;
}
int trasladarMayores50(int matriz[5][4], int vector[20]) {
    int i, j, k = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 4; j++) {
            if(matriz[i][j] > 50) {
                vector[k] = matriz[i][j];
                k++;
                matriz[i][j] = -1;
            }
        }
    }
    return k;
}
void matrizAVector(int matriz[5][4], int vector[20]) {
    int i, j, k = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 4; j++) {
            vector[k] = matriz[i][j];
            k++;
        }
    }
}
void ordenarVector(int vector[20]) {
    int i, j, aux;
    for(i = 0; i < 20 - 1; i++) {
        for(j = 0; j < 20-1 -i; j++) {
            if(vector[j] < vector[j+1]) {
                aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
            }
        }
    }
}
void vectorAMatriz(int vector[20], int matriz[5][4]) {
    int i, j, k = 0;

    for(i = 0; i < 5; i++) {
        for(j = 0; j < 4; j++) {
            matriz[i][j] = vector[k];
            k++;
        }
    }
}