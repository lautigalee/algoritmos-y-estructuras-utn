#include <stdio.h>
int sonIguales(int x, int y, int z);
int main() {
	int a, b, c, iguales = 0;
    printf("Ingrese una terna de numeros (separados por espacios): ");
    scanf("%d %d %d", &a, &b, &c);
    while (a != 0 || b != 0 || c != 0) {
        if (sonIguales(a, b, c) == 1) {
            iguales++;
        }
    printf("Ingrese otra terna de numeros (0 0 0 para salir): ");
    scanf("%d %d %d", &a, &b, &c);
    }
printf("\nCantidad de ternas con valores iguales: %d", iguales);
	return 0;
}
int sonIguales(int x, int y, int z) {
    if (x == y && x == z) {
        return 1;
    }
    else {
        return 0;
    }
}