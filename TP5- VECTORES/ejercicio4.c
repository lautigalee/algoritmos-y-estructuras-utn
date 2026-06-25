#include <stdio.h>
void ordenarBurbuja(int vector[6], int tam);
float codigosPares(int vector[6], int tam);
int multiplosDe4 (int vector[6], int tam);
int main() {
int vectorPares[6], prod, pares = 0;
do {
    printf("Ingrese el codigo de producto (99 para terminar): ");
    scanf("%d", &prod);
    if (prod != 99) {
        if (prod % 2 == 0) {
            vectorPares[pares] = prod; 
            pares++; 
        }
    }

} while (prod != 99 && pares < 6);
if(pares == 0) {
    printf("\nno se ingresaron codigos pares: ");
    return 0;
}
float promedio;
int multiplos4, i;
ordenarBurbuja(vectorPares, pares);
promedio = codigosPares(vectorPares, pares);
multiplos4 = multiplosDe4(vectorPares, pares);
printf("\ncodigos pares ordenados de menor a mayor: ");
for(i = 0; i < pares; i++) {
    printf("[%d]", vectorPares[i]);
}
printf("\nel menor codigo par es: %d", vectorPares[0]);
printf("\nel mayor codigo par es: %d", vectorPares[pares - 1]);
printf("\nel promedio de codigos pares fue: %.2f", promedio);
printf("\nlos codigos multiplos de 4 fueron: %d", multiplos4);
return 0;
}
void ordenarBurbuja(int vector[6], int tam) {
    int i, j, aux;
    for (i = 0; i < tam - 1; i++) {
        for(j = 0; j < tam - 1 - i; j++) {
            if (vector[j] > vector [j+1]) {
                aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
            }
        }
    }
}
float codigosPares(int vector[6], int tam) {
    int i, suma = 0;
    float prom = 0;
    for (i = 0; i < tam; i++) {
        suma += vector[i];
        }
    prom = (float) suma/tam;
    return prom;
}
int multiplosDe4 (int vector[6], int tam) {
    int i, mult4 = 0;
    for(i = 0; i < tam; i++) {
        if(vector[i] % 4 == 0) {
            mult4++;
        }
    }
    return mult4;
}