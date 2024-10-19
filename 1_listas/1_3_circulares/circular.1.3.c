#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int info;
    struct Nodo* nuevo;
};

struct Nodo* crearNodo(int info) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->info = info;
    nuevoNodo->nuevo = NULL;
    return nuevoNodo;
}

void insertarFinal(struct Nodo** principal, int info) {
    struct Nodo* nuevoNodo = crearNodo(info);
    if (*principal == NULL) {
        *principal = nuevoNodo;
        nuevoNodo->nuevo = nuevoNodo;
        return;
    }
    struct Nodo* auxiliar = *principal;
    while (auxiliar->nuevo != *principal) {
        auxiliar = auxiliar->nuevo;
    }
    auxiliar->nuevo = nuevoNodo;
    nuevoNodo->nuevo = *principal;
}

void mostrarLista(struct Nodo* principal) {
    if (principal == NULL) {
        printf("Lista vacía.\n");
        return;
    }
    struct Nodo* auxiliar = principal;
    do {
        printf("%d -> ", auxiliar->info);
        auxiliar = auxiliar->nuevo;
    } while (auxiliar != principal);
    printf("(vuelve al inicio)\n");
}

void eliminarPrimerElemento(struct Nodo** principal) {
    if (*principal == NULL) {
        printf("Lista inexistente.\n");
        return;
    }

    struct Nodo* eliminar = *principal;

    if (eliminar->nuevo == *principal) {
        free(eliminar);
        *principal = NULL;
        printf("Último elemento eliminado, la lista ahora está vacía.\n");
    } else {
        struct Nodo* auxiliar = *principal;
        while (auxiliar->nuevo != *principal) {
            auxiliar = auxiliar->nuevo;
        }
        *principal = eliminar->nuevo;
        auxiliar->nuevo = *principal;
        free(eliminar);
        printf("Primer elemento eliminado.\n");
    }
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
        eliminarPrimerElemento(&principal);
        printf("Lista después de eliminar el primer elemento: ");
        mostrarLista(principal);

        printf("¿Desea eliminar el primer elemento nuevamente? (s/n): ");
        scanf(" %c", &resp);
    } while (resp == 's' || resp == 'S');

    return 0;
}

