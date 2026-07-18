#include <stdio.h>
float calcularDescuento(int modelo, int color, float total);
void cargarVentas(int modelo[], int color[], float total[], float descuento[], int n);
float sumarVentas(float totalVenta[], int n);
void buscarMayor(float totalVenta[], int modelo[], int color[], int n, float *mayor, int *modeloMayor, int *colorMayor);
int contarSinDescuento(float descuento[], int n);
int generarVectorNegro(float totalVenta[], int modelo[], int color[], float vector[], int n);
void generarValoresFinales(float totalVenta[], float descuento[], float finales[], int n);
float sumarFinales(float finales[], int n);
int main() {
    int modelo[100];
    int color[100];
    float totalVenta[100];
    float descuento[100];
    float vectorNegro[100];
    float valoresFinales[100];
    float totalGeneral, mayor, totalRecaudado;
    int n, modeloMayor, colorMayor;
    int sinDescuento;
    int cantidadVector;
    int i;
    do {
        printf("Ingrese la cantidad de ventas: ");
        scanf("%d", &n);
    }
    while(n <= 0 || n > 100);
    cargarVentas(modelo, color, totalVenta, descuento, n);
    totalGeneral = sumarVentas(totalVenta, n);
    printf("\nTotal vendido sin descuentos: %.2f\n", totalGeneral);
    buscarMayor(totalVenta, modelo, color, n, &mayor, &modeloMayor, &colorMayor);
    printf("\nMayor venta individual: %.2f\n", mayor);
    printf("Modelo: %d\n", modeloMayor);
    printf("Color: %d\n", colorMayor);
    sinDescuento = contarSinDescuento(descuento, n);
    printf("\nVentas sin descuento: %d\n", sinDescuento);
    cantidadVector = generarVectorNegro(totalVenta, modelo, color, vectorNegro, n);
    printf("\nVentas modelos 3,4,5 color 1:\n");
    for(i = 0; i < cantidadVector; i++) {
        printf("%.2f\n", vectorNegro[i]);
    }
    generarValoresFinales(totalVenta, descuento, valoresFinales, n);
    printf("\nValores finales por venta:\n");
    for(i = 0; i < n; i++) {
        printf("Venta %d: %.2f\n", i, valoresFinales[i]);
    }
    totalRecaudado = sumarFinales(valoresFinales, n);
    printf("\nTotal recaudado realmente: %.2f\n", totalRecaudado);
    return 0;
}
float calcularDescuento(int modelo, int color, float total) {
    float descuento = 0;
    if(total > 12000) {
        descuento += total * 0.10;
    }
    if(modelo == 4 || modelo == 5) {
        descuento += total * 0.05;
    }
    if(color == 2) {
        descuento += total * 0.15;
    }
    return descuento;
}
void cargarVentas(int modelo[], int color[], float total[], float descuento[], int n) {
    int i, cantidad;
    float precio;
    for(i = 0; i < n; i++) {
        printf("\nModelo: ");
        scanf("%d", &modelo[i]);
        printf("Color: ");
        scanf("%d", &color[i]);
        printf("Cantidad vendida: ");
        scanf("%d", &cantidad);
        printf("Precio unitario: ");
        scanf("%f", &precio);
        total[i] = cantidad * precio;
        descuento[i] = calcularDescuento(modelo[i], color[i], total[i]);
    }
}
float sumarVentas(float totalVenta[], int n) {
    int i;
    float suma = 0;
    for(i = 0; i < n; i++) {
        suma += totalVenta[i];
    }
    return suma;
}
void buscarMayor(float totalVenta[], int modelo[], int color[], int n, float *mayor, int *modeloMayor, int *colorMayor) {
    int i;
    *mayor = totalVenta[0];
    *modeloMayor = modelo[0];
    *colorMayor = color[0];
    for(i = 1; i < n; i++) {
        if(totalVenta[i] > *mayor) {
            *mayor = totalVenta[i];
            *modeloMayor = modelo[i];
            *colorMayor = color[i];
        }
    }
}
int contarSinDescuento(float descuento[], int n) {
    int i;
    int contador = 0;
    for(i = 0; i < n; i++) {
        if(descuento[i] == 0) {
            contador++;
        }
    }
    return contador;
}
int generarVectorNegro(float totalVenta[], int modelo[], int color[], float vector[], int n) {
    int i;
    int k = 0;
    for(i = 0; i < n; i++) {
        if((modelo[i] == 3 || modelo[i] == 4 || modelo[i] == 5) && color[i] == 1) {
            vector[k] = totalVenta[i];
            k++;
        }
    }
    return k;
}
void generarValoresFinales(float totalVenta[], float descuento[], float finales[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        finales[i] = totalVenta[i] - descuento[i];
    }
}
float sumarFinales(float finales[], int n) {
    int i;
    float suma = 0;
    for(i = 0; i < n; i++) {
        suma += finales[i];
    }
    return suma;
}