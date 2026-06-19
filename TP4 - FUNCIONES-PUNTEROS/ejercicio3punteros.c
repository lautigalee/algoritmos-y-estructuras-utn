#include <stdio.h>
int calcularPuntaje(float *acumuladorIndices);
int main() {
	int N, i, puntajepostulante;
    float sumaindices = 0;
    printf("indique la cantidad de participantes: ");
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
    puntajepostulante = calcularPuntaje (&sumaindices);
    printf("\nel puntaje del postulante es de: %d", puntajepostulante);
    }
    printf("\nel total de indices fue de: %.2f", sumaindices);
	return 0;
}
int calcularPuntaje(float *acumuladorIndices) {
    int correctas = 0, blanco = 0, incorrectas = 0, puntaje = 0;
    float indice;
    printf("Ingrese la cantidad de respuestas correctas: ");
    scanf("%d", &correctas);
    printf("Ingrese la cantidad de respuestas incorrectas: ");
    scanf("%d", &incorrectas);
    printf("Ingrese la cantidad de respuestas en blanco: ");
    scanf("%d", &blanco);
    puntaje = (correctas * 4) + (incorrectas * (-1));
    indice = puntaje * 1.5;
    *acumuladorIndices = *acumuladorIndices + indice;
    return puntaje;
}

