#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int info;
    struct Nodo* ligaizq;
    struct Nodo* ligader;
};

struct Nodo* crearNodo(int info) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->info = info;
    nuevoNodo->ligaizq = NULL;
    nuevoNodo->ligader = NULL;
    return nuevoNodo;
}

void insertarFinal(struct Nodo** principal, int info) {
    struct Nodo* nuevoNodo = crearNodo(info);
    if (*principal == NULL) {
        *principal = nuevoNodo;
        return;
    }
    struct Nodo* auxiliar = *principal;
    while (auxiliar->ligader != NULL) {
        auxiliar = auxiliar->ligader;
    }
    auxiliar->ligader = nuevoNodo;
    nuevoNodo->ligaizq = auxiliar;
}

void mostrarLista(struct Nodo* principal) {
    struct Nodo* auxiliar = principal;
    while (auxiliar != NULL) {
        printf("%d <-> ", auxiliar->info);
        auxiliar = auxiliar->ligader;
    }
    printf("NULL\n");
}

void eliminarUltimoElemento(struct Nodo** principal) {
    if (*principal == NULL) {
        printf("Lista inexistente.\n");
        return;
    }

    struct Nodo* auxiliar = *principal;

    while (auxiliar->ligader != NULL) {
        auxiliar = auxiliar->ligader;
    }

    if (auxiliar->ligaizq == NULL) {  
        free(auxiliar);
        *principal = NULL;
        printf("Último elemento eliminado, la lista ahora está vacía.\n");
    } else {  
        auxiliar->ligaizq->ligader = NULL;
        free(auxiliar);
        printf("Último elemento eliminado.\n");
    }
}

int main() {
    struct Nodo* principal = NULL;
    insertarFinal(&principal, 2);
    insertarFinal(&principal, 3);
    insertarFinal(&principal, 4);

    printf("Lista inicial: ");
    mostrarLista(principal);

    char resp;
    do {
        eliminarUltimoElemento(&principal);
        printf("Lista después de eliminar el último elemento: ");
        mostrarLista(principal);

        printf("¿Desea eliminar otro último elemento? (s/n): ");
        scanf(" %c", &resp);
    } while (resp == 's' || resp == 'S');

    return 0;
}

