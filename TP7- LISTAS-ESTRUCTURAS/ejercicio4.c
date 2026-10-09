#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int numPedido;
    long long dniCliente;
    int codProducto;
    int cantidad;
    int tipoPedido;
} Pedido;

typedef struct Nodo {
    Pedido info;
    struct Nodo* sig;
} Nodo;

void insertarInicio(Nodo** lista, Pedido p);
void insertarFinal(Nodo** lista, Pedido p);
void cargarPedidos(Nodo** lista); // b
void mostrarLista(const Nodo* lista); // c y g
void buscarPorDNI(const Nodo* lista, long long dniBusqueda); // d
void generarVectorUrgentes(const Nodo* lista); // e
void eliminarPedido(Nodo** lista, int numEliminar); // f
void liberarMemoria(Nodo** lista);

int main() {
    Nodo* listaPedidos = NULL;

    printf("=== GESTION DE PEDIDOS DE LA EMPRESA DE DISTRIBUCION ===\n");
    cargarPedidos(&listaPedidos);
    printf("\n----------------------------------------\n");
    printf("c) Lista de pedidos registrados:\n");
    mostrarLista(listaPedidos);
    if (listaPedidos != NULL) {
        long long dni;
        printf("\n----------------------------------------\n");
        printf("d) Ingrese DNI del cliente a buscar: ");
        scanf("%lld", &dni);
        buscarPorDNI(listaPedidos, dni);
    }

    printf("e) Generacion de vector con codigos de productos urgentes:\n");
    generarVectorUrgentes(listaPedidos);

    if (listaPedidos != NULL) {
        int numEliminar;
        printf("\n----------------------------------------\n");
        printf("f) Ingrese el numero de pedido a eliminar: ");
        scanf("%d", &numEliminar);
        eliminarPedido(&listaPedidos, numEliminar);

        printf("\ng) Lista de pedidos despues de la eliminacion:\n");
        mostrarLista(listaPedidos);
    }
    liberarMemoria(&listaPedidos);

    return 0;
}

void insertarInicio(Nodo** lista, Pedido p) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        printf("Error: Memoria insuficiente.\n");
        return;
    }
    nuevo->info = p;
    nuevo->sig = *lista;
    *lista = nuevo;
}

void insertarFinal(Nodo** lista, Pedido p) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        printf("Error: Memoria insuficiente.\n");
        return;
    }
    nuevo->info = p;
    nuevo->sig = NULL;

    if (*lista == NULL) {
        *lista = nuevo;
    } else {
        Nodo* aux = *lista;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void cargarPedidos(Nodo** lista) {
    Pedido p;
    printf("\nCarga de pedidos (Ingrese 0 en Numero de Pedido para finalizar):\n");

    printf("\nNumero de pedido: ");
    scanf("%d", &p.numPedido);

    while (p.numPedido != 0) {
        printf("DNI del cliente: ");
        scanf("%lld", &p.dniCliente);
        printf("Codigo del producto: ");
        scanf("%d", &p.codProducto);
        printf("Cantidad solicitada: ");
        scanf("%d", &p.cantidad);

        do {
            printf("Tipo de pedido (1: Urgente, 2: Normal): ");
            scanf("%d", &p.tipoPedido);
            if (p.tipoPedido != 1 && p.tipoPedido != 2) {
                printf("Opcion invalida. Reintente.\n");
            }
        } while (p.tipoPedido != 1 && p.tipoPedido != 2);
        if (p.tipoPedido == 1) {
            insertarInicio(lista, p);
        } else {
            insertarFinal(lista, p);
        }

        printf("\nNumero de pedido (0 para terminar): ");
        scanf("%d", &p.numPedido);
    }
}

void mostrarLista(const Nodo* lista) {
    if (lista == NULL) {
        printf("La lista esta vacia.\n");
        return;
    }

    const Nodo* aux = lista;
    while (aux != NULL) {
        printf("Pedido Nro: %d\n", aux->info.numPedido);
        printf("DNI Cliente: %lld\n", aux->info.dniCliente);
        printf("Cod. Producto: %d\n", aux->info.codProducto);
        printf("Cantidad: %d\n", aux->info.cantidad);
        printf("Tipo: %s\n", aux->info.tipoPedido == 1 ? "Urgente" : "Normal");
        aux = aux->sig;
    }
}

void buscarPorDNI(const Nodo* lista, long long dniBusqueda) {
    const Nodo* aux = lista;
    int encontrado = 0;

    while (aux != NULL) {
        if (aux->info.dniCliente == dniBusqueda) {
            if (!encontrado) {
                printf("Pedidos encontrados para el DNI %lld:\n", dniBusqueda);
                encontrado = 1;
            }
            printf("- Pedido Nro: %d | Cod. Prod: %d | Cantidad: %d | Tipo: %s\n", aux->info.numPedido, aux->info.codProducto, aux->info.cantidad, aux->info.tipoPedido == 1 ? "Urgente" : "Normal");
        }
        aux = aux->sig;
    }

    if (!encontrado) {
        printf("El cliente con DNI %lld no posee pedidos registrados.\n", dniBusqueda);
    }
}

void generarVectorUrgentes(const Nodo* lista) {
    int cantUrgentes = 0;
    const Nodo* aux = lista;
    while (aux != NULL) {
        if (aux->info.tipoPedido == 1) {
            cantUrgentes++;
        }
        aux = aux->sig;
    }

    if (cantUrgentes == 0) {
        printf("No existen pedidos urgentes registrados.\n");
        return;
    }

    int* vecProductosUrgentes = (int*)malloc(cantUrgentes * sizeof(int));
    if (vecProductosUrgentes == NULL) {
        printf("Error: No se pudo asignar memoria para el vector.\n");
        return;
    }

    aux = lista;
    int pos = 0;
    while (aux != NULL) {
        if (aux->info.tipoPedido == 1) {
            vecProductosUrgentes[pos] = aux->info.codProducto;
            pos++;
        }
        aux = aux->sig;
    }

    printf("Codigos de productos correspondientes a pedidos urgentes (%d en total):\n", cantUrgentes);
    printf("[ ");
    for (int i = 0; i < cantUrgentes; i++) {
        printf("%d%s", vecProductosUrgentes[i], (i < cantUrgentes - 1 ? ", " : " "));
    }
    printf("]\n");

    free(vecProductosUrgentes);
}

void eliminarPedido(Nodo** lista, int numEliminar) {
    if (*lista == NULL) {
        printf("La lista esta vacia, no se puede eliminar.\n");
        return;
    }

    Nodo* aux = *lista;
    Nodo* ant = NULL;

    while (aux != NULL && aux->info.numPedido != numEliminar) {
        ant = aux;
        aux = aux->sig;
    }

    if (aux == NULL) {
        printf("El pedido Nro %d no fue encontrado en la lista.\n", numEliminar);
        return;
    }

    if (ant == NULL) {
        *lista = (*lista)->sig;
    }
    else {
        ant->sig = aux->sig;
    }

    free(aux);
    printf("El pedido Nro %d fue eliminado con exito.\n", numEliminar);
}

void liberarMemoria(Nodo** lista) {
    Nodo* aux;
    while (*lista != NULL) {
        aux = *lista;
        *lista = (*lista)->sig;
        free(aux);
    }
}