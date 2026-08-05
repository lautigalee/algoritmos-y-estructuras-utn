#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void cargarMatriz(int n, int m, int matriz[5][6]);
void mostrarMatriz(int n, int m, int matriz[5][6]);
void buscarMenorDiagonal(int n, int m, int matriz[5][6]);
void generarVecMin(int n, int m, int matriz[5][6], int vector[30]);
void ordenarVector(int vector[30], int m);
void mostrarVector(int vector[30], int m);
int main()
{
    int n, m;
    int matriz[5][6];
    int vector[30];
    do
    {
        printf("Ingrese el valor de N: ");
        scanf("%d", &n);
    } while (n <= 0 || n > 5);
    do
    {
        printf("Ingrese el valor de M: ");
        scanf("%d", &m);
    } while (m <= 0 || m > 6);
    srand(time(NULL));
    cargarMatriz(n, m, matriz);
    printf("\nMATRIZ GENERADA\n");
    mostrarMatriz(n, m, matriz);
    buscarMenorDiagonal(n, m, matriz);
    generarVecMin(n, m, matriz, vector);
    printf("\nVECTOR MINIMO POR COLUMNA\n");
    mostrarVector(vector, m);
    ordenarVector(vector, m);
    printf("\nVECTOR ORDENADO DE MAYOR A MENOR\n");
    mostrarVector(vector, m);
    return 0;
}
void cargarMatriz(int n, int m, int matriz[5][6])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            matriz[i][j] = rand() % 900 + 100;
        }
    }
}
void mostrarMatriz(int n, int m, int matriz[5][6])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}
void buscarMenorDiagonal(int n, int m, int matriz[5][6])
{
    int i;
    int menor;
    int filaMenor;
    int columnaMenor;
    if (n != m)
    {
        printf("\nLa matriz no es cuadrada\n");
        return;
    }
    menor = matriz[0][0];
    filaMenor = 0;
    columnaMenor = 0;
    for (i = 1; i < n; i++)
    {
        if (matriz[i][i] < menor)
        {
            menor = matriz[i][i];
            filaMenor = i;
            columnaMenor = i;
        }
    }
    printf("\nEl menor de la diagonal principal es: %d\n", menor);
    printf("Se encuentra en la posicion [%d][%d]\n", filaMenor, columnaMenor);
}
void generarVecMin(int n, int m, int matriz[5][6], int vector[30])
{
    int i, j;
    int menor;
    for (j = 0; j < m; j++)
    {
        menor = matriz[0][j];
        for (i = 1; i < n; i++)
        {
            if (matriz[i][j] < menor)
            {
                menor = matriz[i][j];
            }
        }
        vector[j] = menor;
    }
}
void ordenarVector(int vector[30], int m)
{
    int i, j;
    int aux;
    for (i = 0; i < m - 1; i++)
    {
        for (j = 0; j < m - 1 - i; j++)
        {
            if (vector[j] < vector[j + 1])
            {

                aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
            }
        }
    }
}
void mostrarVector(int vector[30], int m)
{
    int i;
    for (i = 0; i < m; i++)
    {

        printf("%d ", vector[i]);
    }
    printf("\n");
}