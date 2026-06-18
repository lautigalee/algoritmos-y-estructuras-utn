#include <stdio.h>
void procesarCompra(float *stJudias, float *stLentejas, float *stGarbanzos, float *importe);
int main() {
	int N, i;
    float judias = 100, lentejas = 100, garbanzos = 100, importecliente = 0, pago, vuelto;
    printf("ingrese la cantidad de clientes: ");
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        importecliente = 0;
        procesarCompra(&judias, &lentejas, &garbanzos, &importecliente);
        if (importecliente > 0) {
            printf("\n el total a pagar es de: %.2f", importecliente);
            printf("\ncon cuanto va a pagar?: ");
            scanf("%f", &pago);
            while (pago < importecliente) {
                printf("\nPAGO INSUFICIENTE, debe pagar al menos %.2f", importecliente);
                scanf("%f", &pago);
            }
        vuelto = pago - importecliente;
        printf("\nsu vuelto es de %.2f", vuelto);
        }
        else {
            printf("\nel cliente no compro nada");
        }
    }
    printf("\nel stock final de judias es de: %.2f", judias);
    printf("\nel stock final de lentejas es de: %.2f", lentejas);
    printf("\nel stock final de garbanzos es de: %.2f", garbanzos);
	return 0;
}
void procesarCompra(float *stJudias, float *stLentejas, float *stGarbanzos, float *importe) {
    int opcion;
    float cantidad, precio;
    printf("seleccione una opcion (1 para judias, 2 para lentejas, 3 para garbanzos, 4 para salir: )");
    scanf("%d", &opcion);
        while (opcion != 4) {
            switch (opcion) {
                case 1:
                printf("ingrese la cantidad de judias que desea: ");
                scanf("%f", &cantidad);
                if (cantidad <= *stJudias) {
                    printf("ingrese el precio por kg: ");
                    scanf("%f", &precio);
                *importe = *importe + (cantidad * precio);
                *stJudias = *stJudias - cantidad;
                }
                break;
                case 2:
                printf("Ingrese la cantidad de lentejas que desea: ");
                scanf("%f", &cantidad);
                if (cantidad <= *stLentejas) {
                    printf("ingrese el precio por kg: ");
                    scanf("%f", &precio);
                *importe = *importe + (cantidad * precio);
                *stLentejas = *stLentejas - cantidad;
                }
                break;
                case 3:
                printf("ingrese la cantidad de garbanzos que desea: ");
                scanf("%f", &cantidad);
                if (cantidad <= *stGarbanzos) {
                    printf("Ingrese el precio por kg: ");
                    scanf("%f", &precio);
                *importe = *importe + (cantidad * precio);
                *stGarbanzos = *stGarbanzos - cantidad;
                }
                break;
            }
            printf("seleccione una opcion: ");
            scanf("%d", &opcion);
        }
    }
