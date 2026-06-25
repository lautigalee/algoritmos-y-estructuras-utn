#include <stdio.h>
void cargarVector(float vector[50]);
float mayorNota(float vector[50]);
float promedioNotas(float vector[50]);
float porcentajeAprobados(float vector[50]);
float buscarMenornota(float vector[50]);
void mostrarPosicionesmenor(float vector[50], float menor);
int main() {
float notas[50];
    float elMayor, prom, porc, notamasbaja;
    cargarVector(notas);
    elMayor = mayorNota(notas);
    prom = promedioNotas(notas);
    porc = porcentajeAprobados(notas);
    notamasbaja = buscarMenornota(notas);
    printf("La mayor nota es: %.2f\n", elMayor);
    printf("el promedio de notas es: %.2f\n", prom);
    printf("el porcentaje de aprobados fue de: %.2f\n", porc);
    mostrarPosicionesmenor(notas, notamasbaja);
	return 0;
}
void cargarVector(float vector[50]) {
    int i;
    for (i = 0; i < 50; i++) {
        do {
            printf("Ingrese la nota del alumno %d (0 a 10): ", i + 1);
            scanf("%f", &vector[i]);
            
            if (vector[i] < 0 || vector[i] > 10) {
                printf("Error: La nota debe estar entre 0 y 10.\n");
            }
        } while (vector[i] < 0 || vector[i] > 10); 
    }
}
float mayorNota(float vector[50]){
    float mayor = 0;
    int i;
    for(i = 0; i < 50; i++){
        if(vector [i] > mayor) {
            mayor = vector[i];
        }
    }
    return mayor;
}
float promedioNotas(float vector[50]){
    int i;
    float totalnotas = 0, promedio;
    for(i = 0; i < 50; i++) {
        totalnotas += vector[i];
    }
    if (totalnotas != 0) {
    promedio = totalnotas/50;
}
    return promedio;
}
float porcentajeAprobados(float vector[50]) {
    float porcentaje;
    int i, aprobados = 0;
    for (i = 0; i < 50; i++) {
        if (vector [i] > 6) {
            aprobados ++;
        }
    }
    porcentaje = (float)(aprobados * 100) / 50;
    return porcentaje;
}
float buscarMenornota(float vector[50]) {
    int i;
    float menor = vector[0];
    for (i = 0; i < 50; i++) {
        if (vector [i] < menor) {
            menor = vector[i];
        }
    }
    return menor;
}
void mostrarPosicionesmenor(float vector[50], float menor) {
    int i;
    printf("Las posiciones de los alumnos con la menor nota (%.2f) son: ", menor);
    for (i = 0; i < 50; i++) {
        if (vector [i] == menor) {
            printf("[%d] ", i);
        }
    }
    printf("\n");
}