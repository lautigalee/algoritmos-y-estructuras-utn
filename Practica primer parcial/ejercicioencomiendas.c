#include <stdio.h>

int main() {
	int numguia, destino, encl = 0, encp = 0, encn = 0, bandera = 1, maxdestino = 0, esprimo = 1, i, intpeson, maxguia = 0;
    float peso, pesol = 0, pesop = 0, peson = 0, maxpeso = 0, prom1 = 0, prom2 = 0, prom3 = 0;
    printf("ingrese el numero de guia: ");
    scanf("%d", &numguia);
    while (numguia != 0) {
        printf("ingrese el destino: ");
        scanf("%d", &destino);
        while (destino < 1 || destino > 3) {
            printf("ingrese un destino valido: ");
            scanf("%d", &destino);
        }
        printf("ingrese el peso del paquete: ");
        scanf("%f", &peso);
        switch (destino) {
            case 1:
            pesol += peso;
            encl ++;
            break;
            case 2:
            pesop += peso;
            encp ++;
            break;
            case 3:
            peson += peso;
            encn ++;
            break;
        }
        if (bandera == 1) {
            maxpeso = peso;
            maxdestino = destino;
            maxguia = numguia;
            bandera = 0;
        }
        else {
            if (peso > maxpeso) {
                maxpeso = peso;
                maxdestino = destino;
                maxguia = numguia;
        }
        }
        printf("ingrese otro numero de guia: ");
        scanf("%d", &numguia);
    }
if (encl != 0) {prom1 = pesol / encl;}
if (encp != 0) {prom2 = pesop / encp;}
if (encn != 0) {prom3 = peson / encn;}
        intpeson = (int) peson;
        if(intpeson <= 1) {
            esprimo = 0;
        }
        else {
            esprimo = 1;
        }
        for(i = 2; i <= intpeson - 1; i++) {
            if (intpeson % i == 0) {
                esprimo = 0;
                break;
            }
        }
printf("\nel promedio de peso de encomiendas locales fue de: %.2f kg", prom1);
printf("\nel promedio de peso de encomiendas provinciales fue de: %.2f kg", prom2);
printf("\nel promedio de peso de encomiendas nacionales fue de: %.2f kg", prom3);
printf("\nel numero de guia con mayor peso fue %d", maxguia);
printf("\neste mayor peso se dio en el destino: %d", maxdestino);
if (esprimo == 1) {
    printf ("El total de peso Nacional es un número primo");
}
else {
    if (esprimo == 0) {
        printf("\nEl total de peso Nacional no es un número primo");
    }
}
	return 0;
}

