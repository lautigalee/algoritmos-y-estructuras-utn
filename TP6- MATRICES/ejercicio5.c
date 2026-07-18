#include <stdio.h>
void cargarMatriz(int matriz[5][4]);
float promedioNotas(int matriz[5][4]);
void buscarMayorMenor(int matriz[5][4], int *mayor,int *filaMayor,int *columnaMayor, int *menor, int *filaMenor, int *columnaMenor);
void intercambiarDiagonal(int matriz[5][4]);
void mostrarMatriz(int matriz[5][4]);
int main() {
	int matriz[5][4], mayor, fmayor, cmayor, menor, fmenor, cmenor;
    float prom;
    cargarMatriz(matriz);
    prom = promedioNotas(matriz);
    printf("El promedio general de notas fue de %.2f\n", prom);
    buscarMayorMenor(matriz, &mayor, &fmayor, &cmayor, &menor, &fmenor, &cmenor);
    printf("\nLa nota mas alta fue : %d\n", mayor);
	printf("Se encuentra en la posicion [%d][%d]\n", fmayor, cmayor);
    printf("\nLa nota mas baja fue : %d\n", menor);
	printf("Se encuentra en la posicion [%d][%d]\n", fmenor, cmenor);
    intercambiarDiagonal(matriz);
    mostrarMatriz(matriz);
	return 0;
}
void cargarMatriz(int matriz[5][4]) {
    int i, j;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 4; j++) {
            printf("Ingrese el elemento [%d][%d]", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}
float promedioNotas(int matriz[5][4]) {
    int i, j, suma = 0;
	float prom;
	for(i = 0; i < 5; i++) {
		for(j = 0; j < 4; j++) {
			suma += matriz[i][j];
		}
	}
	prom = (float)suma / (5 * 4);
	return prom;
}
void buscarMayorMenor(int matriz[5][4], int *mayor,int *filaMayor,int *columnaMayor, int *menor, int *filaMenor, int *columnaMenor) {
    int i, j;
    *mayor = matriz[0][0];
    *filaMayor = 0;
    *columnaMayor = 0;
    *menor = matriz[0][0];
    *filaMenor = 0;
    *columnaMenor = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 4; j++) {
            if (matriz[i][j] > *mayor) {
                *mayor = matriz[i][j];
                *filaMayor = i;
                *columnaMayor = j;
            }
            if(matriz[i][j] < *menor) {
                *menor = matriz[i][j];
                *filaMenor = i;
                *columnaMenor = j;
            }
        }
    }
}
void intercambiarDiagonal(int matriz[5][4]) {
    int i, aux;
    for(i = 0; i < 4; i++) {
        aux = matriz[i][i];
        matriz[i][i] = matriz[4][i];
        matriz[4][i] = aux;
    }
}
void mostrarMatriz(int matriz[5][4]) {
    int i, j; 
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 4; j++) {
        printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}