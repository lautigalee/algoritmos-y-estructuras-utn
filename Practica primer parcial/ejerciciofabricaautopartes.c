#include <stdio.h>

int main() {
	int numlote, tipofalla, falla1 = 0, falla2 = 0, falla3 = 0, bandera = 1, minlote = 0, minfalla = 0, esprimo = 1, i;
    float costoperdida, perdidafalla1 = 0, perdidafalla2 = 0, perdidafalla3 = 0, minperdida = 0, prom1 = 0, prom2 = 0, prom3 = 0;
    printf("ingrese el numero de lote de origen: ");
    scanf("%d", &numlote);
    while(numlote != 0) {
        printf("ingrese el tipo de falla: ");
        scanf("%d", &tipofalla);
        while(tipofalla < 1 || tipofalla > 3) {
            printf("ingrese un tipo de falla valido: ");
            scanf("%d", &tipofalla);
        }
        printf("ingrese el costo de la perdida");
        scanf("%f", &costoperdida);
        switch (tipofalla) {
            case 1:
            falla1 ++;
            perdidafalla1 += costoperdida;
            break;
            case 2:
            falla2 ++;
            perdidafalla2 += costoperdida;
            break;
            case 3:
            falla3 ++;
            perdidafalla3 += costoperdida;
            break;
        }
        if (bandera == 1) {
            minperdida = costoperdida;
            minfalla = tipofalla;
            minlote = numlote;
            bandera = 0;
        }
        else {
            if (minperdida > costoperdida) {
            minperdida = costoperdida;
            minfalla = tipofalla;
            minlote = numlote;
            }
        }
        printf("ingrese el numero de lote de origen: ");
        scanf("%d", &numlote);
    }
    if(falla1 != 0){prom1 = perdidafalla1/falla1;}
    if(falla2 != 0){prom2 = perdidafalla2/falla2;}
    if(falla3 != 0){prom3 = perdidafalla3/falla3;}
if (falla1 <= 1) {
    esprimo = 0;
}
else {
    esprimo = 1;
}
for(i = 2; i <= falla1 - 1; i++) {
    if(falla1 % i == 0) {
        esprimo = 0;
    }
}
printf("\nel promedio de costo de perdida de la primera falla es %.2f", prom1);
printf("\nel promedio de costo de perdida de la segunda falla es %.2f", prom2);
printf("\nel promedio de costo de perdida de la tercera falla es %.2f", prom3);
printf("\nel numero de lote que genero la menor perdida fue %d", minlote);
printf("\nla menor perdida fue de %.2f", minperdida);
printf("\nla falla que genero la menor perdida fue %d", minfalla);
if (esprimo == 1) {
    printf("La cantidad de piezas con falla de matriz es un número primo");
}
else {
    if (bandera == 0) {
        printf("La cantidad de piezas con falla de matriz no es un número primo");
    }
}
	return 0;
}

