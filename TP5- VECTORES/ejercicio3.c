#include <stdio.h>
#include <stdlib.h>
void cargarAleatorio (int vector[80], int n);
int sumaValpares (int vector [80], int n);
float porcentajeImpares (int vector [80], int n);
int cantNulos (int vector[80], int n);
int buscarMayor(int vector[80], int n);
int main() {
int notasSensores[80];
int n;
do {
    printf("Ingrese la cantidad de sensores (1 a 79): ");
    scanf("%d", &n);
} while (n <= 0 || n >= 80);
cargarAleatorio(notasSensores, n);
int sum, cantidadnulos, may;
float porc;
sum = sumaValpares(notasSensores, n);
cantidadnulos = cantNulos(notasSensores, n);
porc = porcentajeImpares(notasSensores, n);
may = buscarMayor(notasSensores, n);
printf("\nla suma de valores pares es de: %d", sum);
printf("\nla cantidad de sensores nulos fueron: %d", cantidadnulos);
printf("\nel porcentaje de numeros impares fue de: %.2f", porc);
printf("\nel mayor valor registrado por los sensores fue: %d", may);
	return 0;
}
void cargarAleatorio (int vector[80], int n) {
    int i;
    for (i = 0; i < n; i++) {
        vector[i] = rand() % 100;
    }
}
int sumaValpares (int vector [80], int n) {
    int suma = 0, i;
    for (i = 0; i < n; i++) {
        if (vector[i] % 2 == 0) {
            suma += vector [i];
        }
    }
    return suma;
}
float porcentajeImpares (int vector [80], int n) {
    int i, impares = 0;
    float porcentaje;
    for (i = 0; i < n; i++) {
        if (vector[i] % 2 != 0) {
            impares ++;
        }
    }
    porcentaje = (float)(impares * 100) /n;
    return porcentaje;
}
int cantNulos (int vector[80], int n) {
    int i, nulos = 0;
    for (i = 0; i < n; i++) {
        if (vector[i] == 0) {
            nulos++;
        }
    }
    return nulos;
}
int buscarMayor(int vector[80], int n) {
    int mayor = 0, i;
    for (i = 0; i < n; i++) {
        if (vector [i] > mayor) {
            mayor = vector [i];
        }
    }
    return mayor;
}