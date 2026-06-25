#include <stdio.h>
void cargarVector(float vector[20], int tam);
void actualizarDatos(float dato[20], int n, float bajas[20], int m);
int main() {
    int n, m, i;
    float DATO[20];
    float BAJAS[20];
do {
    printf("Ingrese el tamano del vector DATO (1 a 20): ");
    scanf("%d", &n);
} while (n <= 0 || n > 20);
do {
    printf("Ingrese el tamano del vector BAJAS (1 a 20): ");
    scanf("%d", &m);
} while (m <= 0 || m > 20);
cargarVector(DATO, n);
cargarVector(BAJAS, m);
actualizarDatos(DATO, n, BAJAS, m);
for(i = 0; i < n; i++) {
    printf("\n[%.2f]", DATO[i]);
}
	return 0;
}
void cargarVector(float vector[20], int tam) {
    int i;
    for(i = 0; i < tam; i++) {
        do {
printf("Ingrese el valor para la posicion [%d] (mayor a 0): ", i);
scanf("%f", &vector[i]);
        }
        while(vector[i] <= 0 );
    }
}
void actualizarDatos(float dato[20], int n, float bajas[20], int m){
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(dato[i] == bajas[j]) {
                dato[i] = -1;
                break;
            }
        }
    }
}