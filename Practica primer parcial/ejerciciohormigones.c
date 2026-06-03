#include <stdio.h>

int main() {
    int numremito, tipohormigon, hormigon1 = 0, hormigon2 = 0, hormigon3 = 0, esprimo = 1, i, intvolumen2;
    float volumen, volumen1 = 0, volumen2 = 0, volumen3 = 0, prom1 = 0, prom2 = 0, prom3 = 0;
    printf("ingrese el numero de remito: ");
    scanf ("%d", &numremito);
    while (numremito != 0) {
        printf("ingrese el tipo de hormigon: ");
        scanf ("%d", &tipohormigon);
        while (tipohormigon < 1 || tipohormigon > 3) {
            printf("ingrese un tipo de hormigon valido: ");
            scanf("%d", &tipohormigon);
        }
        printf("ingrese el volumen despachado: ");
        scanf("%f", &volumen);
        switch (tipohormigon) {
            case 1: 
            volumen1 += volumen;
            hormigon1 ++;
            break;
            case 2:
            volumen2 += volumen;
            hormigon2 ++;    
            break;
            case 3:
            volumen3 += volumen;
            hormigon3 ++;
            break;    
        }
        printf("ingrese el numero de remito: ");
        scanf ("%d", &numremito);
    }
    if (hormigon1 != 0) {prom1 = volumen1/hormigon1;}
    if (hormigon2 != 0) {prom2 = volumen2/hormigon2;}
    if(hormigon3 != 0) {prom3 = volumen3/hormigon3;}
    intvolumen2 = (int) volumen2;
    
    if (intvolumen2 <= 1) {
        esprimo = 0; 
    } else {
        esprimo = 1; 
        for (i = 2; i <= intvolumen2 - 1; i++) {
            if (intvolumen2 % i == 0) {
                esprimo = 0;
                break;
            }
        }
    }
    printf("\nel promedio de volumen del primer tipo de hormigon fue: %.2f", prom1);
    printf("\nel promedio de volumen del segundo tipo de hormigon fue: %.2f", prom2);
    printf("\nel promedio de volumen del tercer tipo de hormigon fue: %.2f", prom3);
    if (esprimo == 1) {
        printf("\nEl total de volumen del Tipo 2 es un número primo");
    }
    else {
        printf("\nEl total de volumen del Tipo 2 no es un número primo");
    }

	return 0;
}

