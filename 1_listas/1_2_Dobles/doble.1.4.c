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

void eliminarElementoPorInfo(struct Nodo** principal, int info) {
    if (*principal == NULL) {
        printf("Lista inexistente.\n");
        return;
    }

    struct Nodo* auxiliar = *principal;

    while (auxiliar != NULL && auxiliar->info != info) {
        auxiliar = auxiliar->ligader;
    }

    if (auxiliar == NULL) {
        printf("Ningún nodo coincide con la información dada.\n");
        return;
    }

    if (auxiliar->ligaizq == NULL) {  // Solo un elemento en la lista
        free(auxiliar);
        *principal = NULL;
        printf("Último elemento eliminado, la lista ahora está vacía.\n");
    } else if (auxiliar->ligader == NULL) {  // El último elemento
        auxiliar->ligaizq->ligader = NULL;
        free(auxiliar);
        printf("Último elemento eliminado.\n");
    } else {  // Elemento en medio
        auxiliar->ligaizq->ligader = auxiliar->ligader;
        auxiliar->ligader->ligaizq = auxiliar->ligaizq;
        free(auxiliar);
        printf("Elemento %d eliminado.\n", info);
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
        int infoEliminar;
        printf("Ingrese el elemento a eliminar: ");
        scanf("%d", &infoEliminar);
        eliminarElementoPorInfo(&principal, infoEliminar);
        
        printf("Lista después de eliminar el elemento: ");
        mostrarLista(principal);

        printf("¿Desea eliminar otro elemento? (s/n): ");
        scanf(" %c", &resp);
    } while (resp == 's' || resp == 'S');

    return 0;
}

