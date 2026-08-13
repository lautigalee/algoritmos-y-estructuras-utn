#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void CargaMatriz(int f, int c);
void MenorPromedio(int f, int c);
int GenerarVector(int f, int c);
void MostrarVector(int cant);
void OrdenarVector(int cant);
int VEC_MAYO_50[30];
int stock[5][6];
int main() {
    srand(time(NULL));
	int f, c, cant;
    do {
        printf("Ingrese la cantidad de depósitos: ");
        scanf("%d", &f);
    }
    while(f <= 0 || f >= 5);
    do {
        printf("Ingrese la cantidad de productos: ");
        scanf("%d", &c);
    }
    while(c <= 0 || c >= 6);
    CargaMatriz(f,c);
    MenorPromedio(f, c);
    cant = GenerarVector(f, c);
    MostrarVector(cant);
    OrdenarVector(cant);
    MostrarVector(cant);
	return 0;
}
void CargaMatriz(int f, int c) {
    int i, j;
    for(i = 0; i < f; i++) {
        for(j = 0; j < c; j++) {
            stock[i][j] = rand() % 100;
        }
    }
}
void MenorPromedio(int f, int c) {
int depositoMin = 0;
float minPromedio = 0.0;
int i, j;
for (i = 0; i < f; i++) {
    float suma = 0;
    for (j = 0; j < c; j++) {
        suma += stock[i][j];
    }
    float promedioActual = suma / c; 
    if (i == 0 || promedioActual < minPromedio) {
        minPromedio = promedioActual;
        depositoMin = i;
    }
}
printf("\n1) El deposito con menor promedio es el numero %d (promedio: %.2f)\n", depositoMin, minPromedio);
}
int GenerarVector(int f, int c) {
    int i, j, k = 0;
    for(i = 0; i < f; i++) {
        for(j = 0; j < c; j++) {
            if(stock[i][j] > 50) {
                VEC_MAYO_50[k] = stock[i][j];
                k++;
            }
        }
    }
    return k;
}
void MostrarVector(int cant) {
    int i;
    for(i = 0; i < cant; i++) {
        printf("%d ", VEC_MAYO_50[i]);
    }
}
void OrdenarVector(int cant) {
    int i, j, aux;
    for(i = 0; i < cant-1; i++) {
        for(j = 0; j < cant-1-i; j++) {
            if(VEC_MAYO_50[j+1] > VEC_MAYO_50[j]) {
                aux = VEC_MAYO_50[j];
                VEC_MAYO_50[j] = VEC_MAYO_50[j+1];
                VEC_MAYO_50[j+1] = aux;
            }
        }
    }
}