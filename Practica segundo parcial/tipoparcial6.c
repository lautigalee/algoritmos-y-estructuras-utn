#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void CargarMatriz(int n, int m);
void ConsumoProm(int n, int m);
int GenerarVector(int n, int m);
void MostrarVector(int k);
void OrdenarVector(int k);
int matriz[5][6];
int VEC_IMPARES[30];
int main() {
	srand(time(NULL));
    int n, m, k;
    do {
        printf("Ingrese la cantidad de filas de la matriz: ");
        scanf("%d", &n);
    }
    while(n <= 0 || n >= 5);
    do {
        printf("Ingrese la cantidad de columnas de la matriz: ");
        scanf("%d", &m);
    }
    while(m <= 0 || m >= 6);
    CargarMatriz(n, m);
    ConsumoProm(n, m);
    k = GenerarVector(n, m);
    MostrarVector(k);
    OrdenarVector(k);
    MostrarVector(k);
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
void ConsumoProm(int n, int m) {
    int i, j, suma;
    float prom;
    float maxProm = 0;
    int plantaMayor = 0;
    for(i = 0; i < n; i++) {
        suma = 0; 
        for(j = 0; j < m; j++) {
            suma += matriz[i][j];
        }
        prom = (float)suma / m;
        printf("Planta %d - Consumo promedio: %.2f kWh\n", i, prom);
        if(prom > maxProm) {
            maxProm = prom;
            plantaMayor = i;
        }
    }
    printf("\nLa planta con mayor promedio fue la Planta %d (%.2f kWh)\n\n", plantaMayor, maxProm);
}
int GenerarVector(int n, int m) {
    int i, j, k = 0;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(matriz[i][j] % 2 != 0 && matriz[i][j] > 40) {
                VEC_IMPARES[k] = matriz[i][j];
                k++;
            }
        }
    }
    return k;
}
void MostrarVector(int k) {
    int i;
    for(i = 0; i < k; i++) {
        printf("%d ", VEC_IMPARES[i]);
    }
    printf("\n");
}
void OrdenarVector(int k) {
    int i, j, aux;
    for(i = 0; i < k-1; i++) {
        for(j = 0; j < k-1 - i; j++) {
            if(VEC_IMPARES[j+1] > VEC_IMPARES[j]) {
                aux = VEC_IMPARES[j];
                VEC_IMPARES[j] = VEC_IMPARES[j+1];
                VEC_IMPARES[j+1] = aux;
            }
        }
    }
}