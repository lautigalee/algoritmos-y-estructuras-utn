#include <stdio.h>
void cargarMaterias (int vector[], int tam);
void generarUnion(int salaA[], int m, int salaB[], int n, int vectorC[]);
int generarDeudores(int vectorC[], int tamC, int vectorD[]);
void mostrarVector(int vector[], int tam, char nombre);
int main() {
	int salaA[10], salaB[15];
    int vectorC[25], vectorD[25];
    int m, n;
    do {
        printf("ingrese el tamaño de la sala A (entre 0 y 10)");
        scanf("%d", &m);
    }
    while (m <= 0 || m > 10);
    do {
        printf("ingrese el tamaño de la sala B (entre 1 y 14)");
        scanf("%d", &n);
    }
    while (n <= 0 || n >= 15);
    cargarMaterias(salaA, m);
    cargarMaterias(salaB, n);
    generarUnion(salaA, m, salaB, n, vectorC);
    int tamD = generarDeudores(vectorC, m + n, vectorD);
    mostrarVector(vectorC, m + n, 'C');
    mostrarVector(vectorD, tamD,'D');
	return 0;
}
void cargarMaterias (int vector[], int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        do {
            printf("ingrese la cantidad de materias que adeuda el alumno: ");
            scanf("%d", &vector[i]);
        }
        while (vector[i] < 0);
    }
}
void generarUnion(int salaA[], int m, int salaB[], int n, int vectorC[]) {
    int i, k = 0;
    for (i = 0; i < m; i++) {
        vectorC[k] = salaA[i];
        k++;
    }
    for (i = 0; i < n; i++) {
        vectorC[k] = salaB[i];
        k++;
    }
}
int generarDeudores(int vectorC[], int tamC, int vectorD[]) {
    int i, cantD = 0;
    for (i = 0; i < tamC; i++) {
        if (vectorC[i] > 0) {
            vectorD[cantD] = vectorC[i];
            cantD++;
        }
    }
    return cantD;
}
void mostrarVector(int vector[], int tam, char nombre) {
    int i;
    printf("\n--- Vector %c ---", nombre);
    for (i = 0; i < tam; i++) {
        printf("\n[%d]", vector[i]);
    }
    printf("\n");
}