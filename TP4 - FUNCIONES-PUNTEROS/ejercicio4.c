#include <stdio.h>
int calcularImporte(char s, int e, int semanas);
int main() {
    int edad, P, totalfactura;
    char sexo;
	printf("ingrese el sexo: ");
    scanf("%c", &sexo);
    if (sexo == 'h') {
        printf("ingrese su edad: ");
        scanf("%d", &edad);
        while (edad <= 70) {
            printf("\nERROR, ingrese una edad válida");
            scanf("%d", &edad);
        }
    }
    else if (sexo == 'm') {
        printf("Ingrese su edad: ");
        scanf("%d", &edad);
        while (edad <= 60) {
            printf("\nERROR, ingrese una edad válida");
            scanf("%d", &edad);
        }
    }
    printf("ingrese la cantidad de semanas: ");
    scanf("%d", &P);
    totalfactura = calcularImporte (sexo, edad, P);
    printf("\nel importe total a abonar es de: %d", totalfactura);
	return 0;
}
int calcularImporte(char s, int e, int semanas) {
    int total = 0;
    if (s == 'h') {
        total = semanas * 15000;
            if (e > 75) {
            total = total + 25000;
        }
    }
if (s == 'm') {
        total = semanas * 14500;
if (e > 65) {
        total = total + 25000;
    }
    }
    return total;
}