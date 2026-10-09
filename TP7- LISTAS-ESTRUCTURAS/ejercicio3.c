#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int numero;
    struct Nodo *sig;
} Nodo;
Nodo *insertarAlInicio(Nodo *lista, int numero);
Nodo *insertarAlFinal(Nodo *lista, int numero);
void mostrarLista(Nodo *lista);
void liberarLista(Nodo *lista);

int main() {
    Nodo *lista = NULL;
    int numero;
    int i;

    printf("QUINIELA NACIONAL MATUTINA\n");

    for (i = 0; i < 10; i++) {
        printf("Ingrese el numero %d: ", i + 1);
        scanf("%d", &numero);

        lista = insertarAlFinal(lista, numero);
    }

    printf("\nQUINIELA PROVINCIAL\n");

    for (i = 0; i < 5; i++) {
        printf("Ingrese el numero %d: ", i + 1);
        scanf("%d", &numero);

        lista = insertarAlInicio(lista, numero);
    }

    printf("\nSORTEO ESPECIAL\n");

    for (i = 0; i < 5; i++) {
        printf("Ingrese el numero %d: ", i + 1);
        scanf("%d", &numero);

        lista = insertarAlFinal(lista, numero);
    }

    printf("\nLISTA RESULTANTE\n");
    mostrarLista(lista);

    liberarLista(lista);

    return 0;
}

Nodo *insertarAlInicio(Nodo *lista, int numero) {
    Nodo *nuevo = malloc(sizeof(Nodo));

    if (nuevo == NULL) {
        printf("Error al reservar memoria.\n");
        exit(EXIT_FAILURE);
    }

    nuevo->numero = numero;
    nuevo->sig = lista;

    lista = nuevo;

    return lista;
}
Nodo *insertarAlFinal(Nodo *lista, int numero) {
    Nodo *nuevo = malloc(sizeof(Nodo));

    if (nuevo == NULL) {
        printf("Error al reservar memoria.\n");
        exit(EXIT_FAILURE);
    }

    nuevo->numero = numero;
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
void mostrarLista(Nodo *lista) {
    Nodo *actual = lista;

    while (actual != NULL) {
        printf("%d -> ", actual->numero);
        actual = actual->sig;
    }

    printf("NULL\n");
}
void liberarLista(Nodo *lista) {
    Nodo *actual;

    while (lista != NULL) {
        actual = lista;
        lista = lista->sig;
        free(actual);
    }
}