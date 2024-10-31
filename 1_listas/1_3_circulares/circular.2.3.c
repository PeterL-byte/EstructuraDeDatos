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

void insertarFinal(struct Nodo** principal, int info) {
    struct Nodo* nuevoNodo = crearNodo(info);
    if (*principal == NULL) {
        *principal = nuevoNodo;
        nuevoNodo->nuevo = nuevoNodo;
    } else {
        struct Nodo* auxiliar = *principal;
        while (auxiliar->nuevo != *principal) {
            auxiliar = auxiliar->nuevo;
        }
        auxiliar->nuevo = nuevoNodo;
        nuevoNodo->nuevo = *principal;
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

void eliminarFinal(struct Nodo** principal) {
    if (*principal == NULL) {
        printf("Lista vacia, no se puede eliminar.\n");
        return;
    }

    struct Nodo* auxiliar = *principal;

    if (auxiliar->nuevo == *principal) {
        free(auxiliar);
        *principal = NULL;
    } else {
        while (auxiliar->nuevo->nuevo != *principal) {
            auxiliar = auxiliar->nuevo;
        }
        free(auxiliar->nuevo);
        auxiliar->nuevo = *principal;
    }
    printf("Ultimo elemento eliminado.\n");
}

int main() {
    struct Nodo* principal = NULL;
    insertarFinal(&principal, 1);
    insertarFinal(&principal, 2);
    insertarFinal(&principal, 3);

    printf("Lista inicial: ");
    mostrarLista(principal);

    char resp;
    do {
        eliminarFinal(&principal);
        printf("Lista despues de eliminar el ultimo elemento: ");
        mostrarLista(principal);

        printf("¿Desea eliminar otro elemento? (s/n): ");
        scanf(" %c", &resp);
    } while (resp == 's' || resp == 'S');

    return 0;
}

