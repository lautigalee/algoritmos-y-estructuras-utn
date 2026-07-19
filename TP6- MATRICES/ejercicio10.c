#include <stdio.h>
void cargarViajes(int viajes[4][100], int *n);
void contarDestinos(int viajes[4][100], int cantidadDestino[], int n);
void buscarMenorKm(int viajes[4][100], int n, int *menor, int *choferMenor);
int generarDestino6(int viajes[4][100], int patentes[], int choferes[], int n);
void ordenarDestino6(int patentes[], int choferes[], int cantidad);
int main() {
    int cantidadDestino[7] = {0};
    int viajes[4][100];
    int patentes[100];
    int choferes[100];
    int n;
    int menor;
    int choferMenor;
    int cantidad6;
    int i;
    cargarViajes(viajes, &n);
    contarDestinos(viajes, cantidadDestino, n);
    printf("\nCantidad de viajes por destino:\n");
    for(i = 1; i <= 6; i++)
    {
        printf("Destino %d: %d viajes\n", i, cantidadDestino[i]);
    }
    buscarMenorKm(viajes, n, &menor, &choferMenor);
    printf("\nViaje con menor cantidad de km:\n");
    printf("Kilometros recorridos: %d\n", menor);
    printf("Chofer: %d\n", choferMenor);
    cantidad6 = generarDestino6(viajes, patentes, choferes, n);
    ordenarDestino6(patentes, choferes, cantidad6);
    printf("\nPatentes que viajaron al destino 6 ordenadas por chofer:\n");
    for(i = 0; i < cantidad6; i++)
    {
        printf("Patente: %d - Chofer: %d\n", patentes[i], choferes[i]);
    }
    return 0;
}
void cargarViajes(int viajes[4][100], int *n) {
    int i = 0;
    int opcion;
    do {
        printf("Patente: ");
        scanf("%d", &viajes[0][i]);
        printf("Destino: ");
        scanf("%d", &viajes[1][i]);
        printf("Chofer: ");
        scanf("%d", &viajes[2][i]);
        printf("Distancia: ");
        scanf("%d", &viajes[3][i]);
        i++;
        printf("Desea ingresar otro viaje? 1-Si 0-No: ");
        scanf("%d", &opcion);
    } while(opcion == 1 && i < 100);
    *n = i;
}
void contarDestinos(int viajes[4][100], int cantidadDestino[], int n) {
    int i;
    for(i = 0; i < n; i++)
    {
        cantidadDestino[viajes[1][i]]++;
    }
}
void buscarMenorKm(int viajes[4][100], int n, int *menor, int *choferMenor) {
    int i;
    *menor = viajes[3][0];
    *choferMenor = viajes[2][0];
    for(i = 1; i < n; i++)
    {
        if(viajes[3][i] < *menor)
        {
            *menor = viajes[3][i];
            *choferMenor = viajes[2][i];
        }
    }
}
int generarDestino6(int viajes[4][100], int patentes[], int choferes[], int n) {
    int i, k = 0;
    for(i = 0; i < n; i++)
    {
        if(viajes[1][i] == 6)
        {
            patentes[k] = viajes[0][i];
            choferes[k] = viajes[2][i];
            k++;
        }
    }
    return k;
}
void ordenarDestino6(int patentes[], int choferes[], int cantidad) {
    int i, j;
    int aux;
    for(i = 0; i < cantidad - 1; i++)
    {
        for(j = 0; j < cantidad - 1 - i; j++)
        {
            if(choferes[j] < choferes[j + 1])
            {
                aux = choferes[j];
                choferes[j] = choferes[j + 1];
                choferes[j + 1] = aux;
                aux = patentes[j];
                patentes[j] = patentes[j + 1];
                patentes[j + 1] = aux;
            }
        }
    }
}