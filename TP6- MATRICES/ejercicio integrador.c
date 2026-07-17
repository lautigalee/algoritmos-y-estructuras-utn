#include <stdio.h>
void cargarMatriz(int matriz[10][10], int filas, int columnas);
void mostrarMatriz(int matriz[10][10], int filas, int columnas);
void buscarMayorMatriz(int matriz[10][10],int filas,int columnas,int *mayor,int *filaMayor,int *columnaMayor);
void sumarFilas(int matriz[10][10], int filas, int columnas);
void sumarColumnas(int matriz[10][10], int filas, int columnas);
float promedioMatriz(int matriz[10][10], int filas, int columnas);
void cantidadesMatriz(int matriz[10][10], int filas, int columnas, int *pos, int *neg, int *cer);
int main() {
	int matriz[10][10], f, c, mayor, filamayor, columnamayor, positivos, negativos, ceros;
	float promedio = 0;
	printf("Ingrese la cantidad de filas de la matriz: ");
	scanf("%d", &f);
	printf("Ingrese la cantidad de columnas de la matriz: ");
	scanf("%d", &c);
	cargarMatriz(matriz, f, c);
	mostrarMatriz(matriz, f, c);
	buscarMayorMatriz(matriz, f, c, &mayor, &filamayor, &columnamayor);
	printf("\nEl mayor elemento de la matriz es: %d\n", mayor);
	printf("Se encuentra en la posicion [%d][%d]\n", filamayor, columnamayor);
	sumarFilas(matriz, f, c);
	sumarColumnas(matriz, f, c);
	promedio = promedioMatriz(matriz, f, c);
	printf("\nEl promedio de los elementos de la matriz es: %.2f\n", promedio);
	cantidadesMatriz(matriz, f, c, &positivos, &negativos, &ceros);
	printf("\nCantidad de positivos: %d\n", positivos);
	printf("Cantidad de negativos: %d\n", negativos);
	printf("Cantidad de ceros: %d\n", ceros);
	return 0;
}
void cargarMatriz(int matriz[10][10], int filas, int columnas) {
    int i, j;
    for(i = 0; i < filas; i++) {
        for(j = 0; j < columnas; j++) {
            printf("Ingrese el elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}
void mostrarMatriz(int matriz[10][10], int filas, int columnas) {
	int i, j;
	for(i = 0; i < filas; i++) {
		for(j = 0; j < columnas; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}
void buscarMayorMatriz(int matriz[10][10],int filas,int columnas,int *mayor,int *filaMayor,int *columnaMayor) {
	int i, j;
	*mayor = matriz[0][0];
	*filaMayor = 0;
	*columnaMayor = 0;
	for(i = 0; i < filas; i++) {
		for(j = 0; j < columnas; j++) {
			if(matriz[i][j] > *mayor) {
				*mayor = matriz[i][j];
				*filaMayor = i;
				*columnaMayor = j;
			}
		}
	}
}
void sumarFilas(int matriz[10][10], int filas, int columnas) {
	int i, j, suma;
for(i = 0; i < filas; i++) {
    suma = 0;
    for(j = 0; j < columnas; j++) {
        suma += matriz[i][j];
    }
    printf("Suma fila %d: %d\n", i, suma);
}
}
void sumarColumnas(int matriz[10][10], int filas, int columnas) {
int i, j, suma;
for(j = 0; j < columnas; j++) {
	suma = 0;
	for(i = 0; i < filas; i++) {
		suma += matriz[i][j];
	}
	printf("Columna %d: %d\n", j, suma);
}
}
float promedioMatriz(int matriz[10][10], int filas, int columnas) {
	int i, j, suma = 0;
	float prom;
	for(i = 0; i < filas; i++) {
		for(j = 0; j < columnas; j++) {
			suma += matriz[i][j];
		}
	}
	prom = (float)suma / (filas * columnas);
	return prom;
}
void cantidadesMatriz(int matriz[10][10], int filas, int columnas, int *pos, int *neg, int *cer) {
	int i, j;
	*pos = 0;
	*neg = 0;
	*cer = 0;
	for(i = 0; i < filas; i++) {
		for(j = 0; j < columnas; j++) {
			if(matriz[i][j] > 0) {
				(*pos)++;
			}
			else if(matriz[i][j] == 0) {
				(*cer)++;
			}
			else {
				(*neg)++;
			}
		}
	}
}