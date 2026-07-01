#include <stdio.h>
void cargaVector( int vector[], int tam);
int generarIngresos(int antiguedad[], int tam, int ingresos[]);
void clasificarRangos(int ingresos[], int tamF, int *c1, int *c2, int *c3);
float calcularTotalSueldos(int antiguedad[], int tam);
void mostrarVector(int vector[], int tam);
int main() {
	int antiguedad[100], ingresoFiltrado[100], cont1 = 0, cont2 = 0, cont3 = 0, n, tamFiltrado = 0;
    float totalsueldos = 0;
    do {
        printf("Ingrese la cantidad de empleados (entre 1 y 100) : ");
        scanf("%d", &n);
    }
    while(n <= 0 || n > 100);
    cargaVector(antiguedad, n);
    tamFiltrado = generarIngresos(antiguedad, n, ingresoFiltrado);
    clasificarRangos(ingresoFiltrado, tamFiltrado, &cont1, &cont2, &cont3);
    totalsueldos = calcularTotalSueldos(antiguedad, n);
    printf("\nVector de Antigüedades\n");
    printf("\nVector de Años de Ingreso Filtrados\n");
    mostrarVector(antiguedad, n);
    mostrarVector(ingresoFiltrado, tamFiltrado);
    printf("\nIngresados entre 1980 y 2000 inclusive: %d", cont1);
    printf("\nIngresados entre 2001 y 2010 inclusive: %d", cont2);
    printf("\nIngresados entre 2011 y 2022 inclusive: %d\n", cont3);
    printf("\nTOTAL EN SUELDOS A ABONAR: $%.2f\n", totalsueldos);
	return 0;
}
void cargaVector( int vector[], int tam) {
    int i;
    for (i = 0; i < tam; i ++) {
        do {
            printf("Ingrese los años de antiguedad: ");
            scanf("%d", &vector[i]);
        }
        while(vector[i] <= 0);
    }
}
int generarIngresos(int antiguedad[], int tam, int ingresos[]) {
    int i, cant = 0, añoingreso = 0;
    for (i = 0; i < tam; i++) {
        añoingreso = 2026 - antiguedad[i];
        if(añoingreso <= 2022){
            ingresos[cant] = añoingreso;
            cant++;
        }
    }
    return cant;
}
void clasificarRangos(int ingresos[], int tamF, int *c1, int *c2, int *c3) {
    int i;
    for (i = 0; i < tamF; i++) {
        if (ingresos[i] >= 1980 && ingresos[i] <= 2000) {
            (*c1)++;
        } else if (ingresos[i] >= 2001 && ingresos[i] <= 2010) {
            (*c2)++;
        } else if (ingresos[i] >= 2011 && ingresos[i] <= 2022) {
            (*c3)++;
        }
    }
}
float calcularTotalSueldos(int antiguedad[], int tam) {
    int i, basico = 880000;
    float sueldo, acum = 0;
    for(i = 0; i < tam; i++) {
        if(antiguedad[i] <= 5) {
            sueldo = basico * 1.05;
        }
        else if (antiguedad[i] > 5 && antiguedad [i] <= 20) {
            sueldo = basico * 1.10;
        }
        else if (antiguedad[i] > 20) {
            sueldo = basico * 1.20;
        }
        acum += sueldo;
    }
    return acum;
}
void mostrarVector(int vector[], int tam) {
    int i;
    for(i = 0; i < tam; i++) {
        printf("[%d]", vector[i]);
    }
    printf("\n");
}