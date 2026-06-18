#include <stdio.h>
#include <math.h>
float POLIN (float a, int n);
int main() {
    int grado;
    float valora, resultado;
    printf("Ingrese el grado del polinomio: ");
    scanf("%d", &grado);
    printf("Ingrese el valor real que quiere evaluar: ");
    scanf("%f", &valora);
    resultado = POLIN (valora, grado);
    printf("\nEl resultado de P(%.2f) es: %.2f\n", valora, resultado);
	return 0;
}
float POLIN (float a, int n) {
    int i;
	float suma = 0, coef;
    for (i = n; i >= 0; i --) {
    printf("Ingrese el coeficiente de grado %d: ", i);
    scanf("%f", &coef);
    suma = suma + (coef * pow(a, i));
    }
    return suma;
}