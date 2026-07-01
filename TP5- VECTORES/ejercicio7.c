#include <stdio.h>
void cargarVentas(float vector[], int tam);
int generarRango(float ventas[], int tamVentas, float rango[]);
void mostrarVector(float vector[], int tam, char nombre[]);
void ordenarMayorMenor(float vector[], int tam);
int main() {
	float ventas[100], rango[100];
    int n, tamrango;
    do {
        printf("Ingrese la cantidad de ventas(entre 1 y 100): ");
        scanf("%d", &n);
    }
    while (n <= 0 || n > 100);
    cargarVentas(ventas, n);
    tamrango = generarRango(ventas, n, rango);
    mostrarVector(rango, tamrango, "rango");
    ordenarMayorMenor(rango, tamrango);
    mostrarVector(ventas, n, "Ventas");
    mostrarVector(rango, tamrango, "Rango");
	return 0;
}
void cargarVentas(float vector[], int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        do {
            printf("Cargue los importes de ventas: ");
            scanf("%f", &vector[i]);
        }
        while(vector[i] < 0);
    }
}
int generarRango(float ventas[], int tamVentas, float rango[]) {
    int i, cantrango = 0;
    for(i = 0; i < tamVentas; i++) {
        if (ventas[i] >= 5000 && ventas[i] <= 28700) {
            rango[cantrango] = ventas[i];
            cantrango ++;
        }
    }
    return cantrango;
}
void mostrarVector(float vector[], int tam, char nombre[]) {
int i;
    printf("\n--- Vector %s ---\n", nombre);
    for (i = 0; i < tam; i++) {
        printf("[%.2f] ", vector[i]);
    }
    printf("\n");
}
void ordenarMayorMenor(float vector[], int tam) {
    int i, j;
    float aux;
    for (i = 0; i < tam - 1; i++) {
        for (j = 0; j < tam - 1 - i; j++) {
            if(vector[j+1] > vector[j]) {
                aux = vector[j+1];
                vector[j+1] = vector[j];
                vector[j] = aux;
            }
        }
    }
}