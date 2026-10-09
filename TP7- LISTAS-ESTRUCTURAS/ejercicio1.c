#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    char letra;
    struct Nodo *sig;
} Nodo;

Nodo *insertarAlFinal(Nodo *lista, char letra);
void mostrarLista(Nodo *lista);
int contarNodos(Nodo *lista);
void liberarLista(Nodo *lista);

int main() {
    Nodo *lista = NULL;
    char letra;
    int cantidadA = 0;

    printf("Ingrese una letra (* para finalizar): ");
    scanf(" %c", &letra);

    while (letra != '*') {
        lista = insertarAlFinal(lista, letra);

        if (letra == 'A' || letra == 'a') {
            cantidadA++;
        }

        printf("Ingrese una letra (* para finalizar): ");
        scanf(" %c", &letra);
    }

    printf("\nLetras almacenadas en la lista:\n");
    mostrarLista(lista);

    printf("\nCantidad de letras A o a: %d\n", cantidadA);

    printf("Cantidad de nodos de la lista: %d\n", contarNodos(lista));

    liberarLista(lista);

    return 0;
}

Nodo *insertarAlFinal(Nodo *lista, char letra) {
    Nodo *nuevo = malloc(sizeof(Nodo));

    if (nuevo == NULL) {
        printf("Error al reservar memoria.\n");
        exit(EXIT_FAILURE);
    }

    nuevo->letra = letra;
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
        printf("%c ", actual->letra);
        actual = actual->sig;
    }

    printf("\n");
}
int contarNodos(Nodo *lista) {
    int cantidad = 0;
    Nodo *actual = lista;

    while (actual != NULL) {
        cantidad++;
        actual = actual->sig;
    }

    return cantidad;
}
void liberarLista(Nodo *lista) {
    Nodo *actual;

    while (lista != NULL) {
        actual = lista;
        lista = lista->sig;
        free(actual);
    }
}