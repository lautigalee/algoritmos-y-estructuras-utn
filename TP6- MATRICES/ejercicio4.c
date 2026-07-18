#include <stdio.h>
void cargarMatriz(int matriz[10][10], int campos, int zonas);
void promedioPorZona(int matriz[10][10], int campos, int zonas);
void promedioPorCampo(int matriz[10][10], int campos, int zonas);
void buscarMayor(int matriz[10][10],int campos,int zonas,int *mayor,int *campoMayor,int *zonaMayor);
float promedioGeneral(int matriz[10][10], int campos, int zonas);
void mostrarMatriz(int matriz[10][10], int campos, int zonas);
int main() {
	int matriz[10][10], camp, zon, mayor, campMayor, zonMayor;
    float prom = 0;
    do {
        printf("Ingrese la cantidad de campos: ");
        scanf("%d", &camp);
    }
    while(camp <= 0 || camp > 10);
    do {
        printf("Ingrese la cantidad de zonas: ");
        scanf("%d", &zon);
    }
    while(zon <= 0 || zon > 10);
    cargarMatriz(matriz, camp, zon);
    promedioPorZona(matriz, camp, zon);
    promedioPorCampo(matriz, camp, zon);
    buscarMayor(matriz, camp, zon, &mayor, &campMayor, &zonMayor);
    printf("Mayor lluvia: %d\n", mayor);
    printf("Campo: %d Zona: %d\n", campMayor, zonMayor);
    prom = promedioGeneral(matriz, camp, zon);
    printf("El promedio general de lluvias fue %.2f", prom);
    mostrarMatriz(matriz, camp, zon);
	return 0;
}
void cargarMatriz(int matriz[10][10], int campos, int zonas) {
    int i, j;
    for(i = 0; i < campos; i++) {
        for(j = 0; j < zonas; j++) {
            printf("Ingrese el elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}
void promedioPorZona(int matriz[10][10], int campos, int zonas) {
    int i, j, suma;
    float promedio;
    for(j = 0; j < zonas; j++){
    suma = 0;
    for(i = 0; i < campos; i++)
    {
    suma += matriz[i][j];
    }
    promedio = (float)suma / campos;
    printf("Promedio zona %d: %.2f\n", j, promedio);
}
}
void promedioPorCampo(int matriz[10][10], int campos, int zonas) {
    int i, j, suma;
    float promedio;
    for(i = 0; i < campos; i++) {
        suma = 0;
        for(j = 0; j < zonas; j++) {
            suma += matriz[i][j];
        }
        promedio = (float)suma/zonas;
        printf("Promedio campo %d: %.2f\n", i, promedio);
    }
}
void buscarMayor(int matriz[10][10],int campos,int zonas,int *mayor,int *campoMayor,int *zonaMayor) {
    int i, j;
    *mayor = matriz[0][0];
    *campoMayor = 0;
    *zonaMayor = 0;
    for(i = 0; i < campos; i++) {
        for(j = 0; j < zonas; j++) {
            if(matriz[i][j] > *mayor) {
                *mayor = matriz[i][j];
                *campoMayor = i;
                *zonaMayor = j;
            }
        }
    }
}
float promedioGeneral(int matriz[10][10], int campos, int zonas) {
    int i, j, sumaTotal = 0;
    float promedio;
    for(i = 0; i < campos; i++) {
        for(j = 0; j < zonas; j++) {
            sumaTotal += matriz[i][j];
        }
    }
    promedio = (float) sumaTotal / (campos * zonas);
    return promedio;
}
void mostrarMatriz(int matriz[10][10], int campos, int zonas) {
    int i, j;
    for(i = 0; i < campos; i++) {
        for(j = 0; j < zonas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}