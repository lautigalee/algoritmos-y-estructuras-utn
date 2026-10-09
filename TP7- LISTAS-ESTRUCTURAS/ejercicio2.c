#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *sig;
} Nodo;

Nodo *insertarAlFinal(Nodo *lista, int numero);
int contarNulos(Nodo *lista);
int sumarPositivos(Nodo *lista);
int contarPositivos(Nodo *lista);
float promedioPositivos(Nodo *lista);
int contarNegativos(Nodo *lista);
int obtenerMayor(Nodo *lista);
void mostrarLista(Nodo *lista);
void liberarLista(Nodo *lista);

int main() {
    Nodo *lista = NULL;
    int N, numero, i;

    printf("Ingrese la cantidad de elementos: ");
    scanf("%d", &N);

    if (N < 0) {
        printf("La cantidad no puede ser negativa.\n");
        return 1;
    }

    for (i = 0; i < N; i++) {
        printf("Ingrese un numero entero: ");
        scanf("%d", &numero);

        lista = insertarAlFinal(lista, numero);
    }

    printf("\nLista cargada: ");
    mostrarLista(lista);

    printf("Cantidad de elementos nulos: %d\n", contarNulos(lista));
    printf("Suma de los positivos: %d\n", sumarPositivos(lista));

    if (contarPositivos(lista) > 0) {
        printf("Promedio de los positivos: %.2f\n", promedioPositivos(lista));
    } else {
        printf("No hay elementos positivos para calcular el promedio.\n");
    }

    printf("Cantidad de elementos negativos: %d\n", contarNegativos(lista));

    if (lista != NULL) {
        printf("Mayor elemento: %d\n", obtenerMayor(lista));
    } else {
        printf("La lista esta vacia: no existe un mayor elemento.\n");
    }

    liberarLista(lista);

    return 0;
}

Nodo *insertarAlFinal(Nodo *lista, int numero) {
    Nodo *nuevo = malloc(sizeof(Nodo));

    if (nuevo == NULL) {
        printf("Error al reservar memoria.\n");
        exit(EXIT_FAILURE);
    }

    nuevo->dato = numero;
    nuevo->sig = NULL;

    if (lista == NULL) {
        lista = nuevo;
    } else {
        Nodo *actual = lista;

        while (actual->sig != NULL) {
            actual = actual->sig;
        }

        actual->sig = nuevo;
    }

    return lista;
}

int contarNulos(Nodo *lista) {
    int cantidad = 0;
    Nodo *actual = lista;

    while (actual != NULL) {
        if (actual->dato == 0) {
            cantidad++;
        }

        actual = actual->sig;
    }

    return cantidad;
}

int sumarPositivos(Nodo *lista) {
    int suma = 0;
    Nodo *actual = lista;

    while (actual != NULL) {
        if (actual->dato > 0) {
            suma += actual->dato;
        }

        actual = actual->sig;
    }

    return suma;
}

int contarPositivos(Nodo *lista) {
    int cantidad = 0;
    Nodo *actual = lista;

    while (actual != NULL) {
        if (actual->dato > 0) {
            cantidad++;
        }

        actual = actual->sig;
    }

    return cantidad;
}

float promedioPositivos(Nodo *lista) {
    int suma = sumarPositivos(lista);
    int cantidad = contarPositivos(lista);

    if (cantidad > 0) {
        return (float)suma / cantidad;
    }

    return 0.0f;
}

int contarNegativos(Nodo *lista) {
    int cantidad = 0;
    Nodo *actual = lista;

    while (actual != NULL) {
        if (actual->dato < 0) {
            cantidad++;
        }

        actual = actual->sig;
    }

    return cantidad;
}

int obtenerMayor(Nodo *lista) {
    int mayor = lista->dato;
    Nodo *actual = lista->sig;

    while (actual != NULL) {
        if (actual->dato > mayor) {
            mayor = actual->dato;
        }

        actual = actual->sig;
    }

    return mayor;
}
void mostrarLista(Nodo *lista) {
    Nodo *actual = lista;

    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->sig;
    }

    printf("\n");
}

void liberarLista(Nodo *lista) {
    Nodo *actual;

    while (lista != NULL) {
        actual = lista;
        lista = lista->sig;
        free(actual);
    }
}