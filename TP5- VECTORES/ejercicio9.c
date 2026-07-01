#include <stdio.h>
void cargaTiempos (float vector[], int tam);
void inicializacionVec (int vector[], int tam);
void calcularTotal(float bici[], float aPie[], float total[], int tam);
void ordenarRanking(float total[], int atletas[], int tam);
void mostrarRanking(int atletas[], float total[], int tam);
int main() {
	float ciclismo[90], pedestrismo[90], tiempoTotal[90];
    int participantes[90], n;
    do {
        printf("Ingrese la cantidad de atletas (entre 1 y 89)");
        scanf("%d", &n);
    }
    while(n <= 0 || n >= 90);
    cargaTiempos(ciclismo, n);
    cargaTiempos(pedestrismo, n);
    inicializacionVec(participantes, n);
    calcularTotal(ciclismo, pedestrismo, tiempoTotal, n);
    ordenarRanking(tiempoTotal, participantes, n);
    mostrarRanking(participantes, tiempoTotal, n);
	return 0;
}
void cargaTiempos (float vector[], int tam) {
    int i;
    float t;
    for (i = 0; i < tam; i++) {
        printf("Ingrese los tiempos de cada participante: ");
        scanf("%f", &t);
        vector[i] = t;
    }
}
void inicializacionVec (int vector[], int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        vector[i] = i + 1;
    }
}
void calcularTotal(float bici[], float aPie[], float total[], int tam) {
    int i;
    for(i = 0; i < tam; i++) {
        total[i] = bici[i] + aPie[i];
    }
}
void ordenarRanking(float total[], int atletas[], int tam) {
    int i, j, auxAtleta;
    float auxTiempo;
    for (i = 0; i < tam-1; i++) {
        for (j = 0; j < tam - 1 - i; j++) {
            if(total [j] > total [j+1]) {
                auxTiempo = total[j];
                total[j] = total[j+1];
                total[j+1] = auxTiempo;
                auxAtleta = atletas[j];
                atletas[j] = atletas[j+1];
                atletas[j+1] = auxAtleta;
            }
        }
    }
}
void mostrarRanking(int atletas[], float total[], int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        printf("%d\t\t%d\t\t%.2f min\n", i + 1, atletas[i], total[i]);
    }
}