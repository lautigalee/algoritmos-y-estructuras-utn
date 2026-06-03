#include <stdio.h>
#include <stdlib.h>

int main() {
    int porcentajehgrano, dias = 0, Bmenortemp = 1,  menordia = 0, i, esprimo = 1, diasprimos = 0;
    float temp, porcentajeCO2, menortemp = 0;
    printf("Ingrese la temperatura interna del silo:");
    scanf ("%f", &temp);
    printf("ingrese el porcentaje de CO2:");
    scanf("%f", &porcentajeCO2);
    printf("ingrese el porcentaje de humedad del grano:");
    scanf("%d", &porcentajehgrano);
    while (porcentajehgrano < 1 || porcentajehgrano > 100) {
        printf ("ingrese un valor valido: ");
        scanf("%d", &porcentajehgrano);
    }
    while (temp != 0 || porcentajeCO2 != 0 || porcentajehgrano != 0) {
        dias++;
        if (Bmenortemp == 1) {
            menortemp = temp;
            menordia = dias;
            Bmenortemp = 0;
        }
        else {
            if (temp  < menortemp) {
                menortemp = temp;
                menordia = dias;
            }
        }
if (porcentajehgrano <= 1) {
            esprimo = 0; 
        } else {
            esprimo = 1;
            for (i = 2; i <= porcentajehgrano - 1; i++) {
                if (porcentajehgrano % i == 0) {
                    esprimo = 0;
                    break;    
                }
            }
        }
        if (esprimo == 1) {
            diasprimos ++;
        }
        printf("Ingrese la temperatura interna del silo:");
        scanf ("%f", &temp);
        printf("ingrese el porcentaje de CO2:");
        scanf("%f", &porcentajeCO2);
        printf("ingrese el porcentaje de humedad del grano:");
        scanf("%d", &porcentajehgrano);
        if (temp == 0 && porcentajeCO2 == 0 && porcentajehgrano == 0) {
            break;
        }
        while (porcentajehgrano < 1 || porcentajehgrano > 100) {
            printf("ingrese un valor valido (1 a 100): ");
            scanf("%d", &porcentajehgrano);
        }
    }
printf("el dia que registro la menor temperatura fue el dia %d", menordia);
printf("la temperatura de ese dia fue %.2f", menortemp);
printf("la cantidad de dias con un porcentaje de humedad del grano primos fueron %d", diasprimos);
    return 0;
}