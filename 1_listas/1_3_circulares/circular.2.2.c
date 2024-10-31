#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int info;
    struct Nodo* nuevo;
};

struct Nodo* crearNodo(int info) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (!nuevoNodo) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    nuevoNodo->info = info;
    nuevoNodo->nuevo = NULL;
    return nuevoNodo;
}

void insertarPrincipio(struct Nodo** principal, int info) {
    struct Nodo* nuevoNodo = crearNodo(info);

    if (*principal == NULL) {
        *principal = nuevoNodo;
        nuevoNodo->nuevo = nuevoNodo;
    } else {
        struct Nodo* ultimo = *principal;
        while (ultimo->nuevo != *principal) {
            ultimo = ultimo->nuevo;
        }
        nuevoNodo->nuevo = *principal;
        ultimo->nuevo = nuevoNodo;
        *principal = nuevoNodo;
    }
}

void mostrarLista(struct Nodo* principal) {
    if (principal == NULL) {
        printf("Lista vacia.\n");
        return;
    }
    struct Nodo* auxiliar = principal;
    do {
        printf("%d -> ", auxiliar->info);
        auxiliar = auxiliar->nuevo;
    } while (auxiliar != principal);
    printf("(vuelve al inicio)\n");
}

int main() {
    struct Nodo* principal = NULL;
    insertarPrincipio(&principal, 1);
    insertarPrincipio(&principal, 2);
    insertarPrincipio(&principal, 3);

    printf("Lista inicial: ");
    mostrarLista(principal);

    char resp;
    do {
        int nuevoValor;
        printf("Ingrese el valor del nuevo elemento al principio: ");
        scanf("%d", &nuevoValor);

        insertarPrincipio(&principal, nuevoValor);

        printf("Lista despues de la insercion: ");
        mostrarLista(principal);

        printf("¿Desea insertar otro elemento? (s/n): ");
        scanf(" %c", &resp);
    } while (resp == 's' || resp == 'S');

    return 0;
}

