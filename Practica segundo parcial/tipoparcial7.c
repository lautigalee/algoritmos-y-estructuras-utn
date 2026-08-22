#include <stdio.h>

void CargarMatriz(int n);
void CalcularPromedio(int n);
int DiasMasDe80(int n);
void GenerarVector(int n);
void OrdenarVector(int n);
void MostrarVector(int n);
int matriz[100][3];
int TOTAL[100];
int main()
{
    int n, cont;
    printf("Ingrese la cantidad de dias: ");
    scanf("%d", &n);
    CargarMatriz(n);
    CalcularPromedio(n);
    cont = DiasMasDe80(n);
    printf("La cantidad de dias con entregas mayores a 80 del producto C fueron: %d\n", cont);
    GenerarVector(n);
    OrdenarVector(n);
    MostrarVector(n);
    return 0;
}
void CargarMatriz(int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("Ingrese la cantidad de entregas del dia [%d], producto [%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }
}
void CalcularPromedio(int n)
{
    int i, j;
    int sumaTotal = 0;
    float promedio;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 3; j++)
        {
            sumaTotal += matriz[i][j];
        }
    }
    promedio = (float)sumaTotal / n;
    printf("El promedio de productos entregados por dia fue: %.2f\n", promedio);
}
int DiasMasDe80(int n)
{
    int i;
    int cont = 0;
    for(i = 0; i < n; i++)
    {
        if(matriz[i][2] > 80)
        {
            cont++;
        }
    }
    return cont;
}
void GenerarVector(int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        TOTAL[i] = matriz[i][0] + matriz[i][1];
    }
}
void OrdenarVector(int n)
{
    int i, j, aux;
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - 1 - i; j++)
        {
            if(TOTAL[j + 1] < TOTAL[j])
            {
                aux = TOTAL[j];
                TOTAL[j] = TOTAL[j + 1];
                TOTAL[j + 1] = aux;
            }
        }
    }
}
void MostrarVector(int n)
{
    int i;
    printf("Vector TOTAL ordenado: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", TOTAL[i]);
    }
    printf("\n");
}