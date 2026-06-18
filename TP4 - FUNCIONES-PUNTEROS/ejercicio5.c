#include <stdio.h>
#include <math.h>
float calcularFx(float x);
int main() {
	float x, resultado;
    for (x = 1.5; x <= 7.0; x = x + 0.5) {
        resultado = calcularFx (x);
        printf("Para x = %.1f -> f(x) = %.2f\n", x, resultado);
    }
	return 0;
}
float calcularFx(float n) {
    float resul;
    resul = pow(n, 3) - 9 * pow(n, 2) + 5;
    return resul;
}