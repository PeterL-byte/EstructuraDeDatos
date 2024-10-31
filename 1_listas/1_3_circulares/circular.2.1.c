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

void insertarAntesDe(struct Nodo** principal, int nuevoValor, int valorAntesDe) {
    if (*principal == NULL) {
        printf("Lista vacia, no se puede insertar.\n");
        return;
    }

    struct Nodo* auxiliar = *principal;
    struct Nodo* nuevoNodo = crearNodo(nuevoValor);

    if (auxiliar->info == valorAntesDe) {
        nuevoNodo->nuevo = auxiliar;
        struct Nodo* ultimo = *principal;
        while (ultimo->nuevo != *principal) {
            ultimo = ultimo->nuevo;
        }
        ultimo->nuevo = nuevoNodo;
        *principal = nuevoNodo;
        return;
    }

    while (auxiliar->nuevo != *principal && auxiliar->nuevo->info != valorAntesDe) {
        auxiliar = auxiliar->nuevo;
    }

    if (auxiliar->nuevo == *principal) {
        printf("Valor %d no encontrado en la lista.\n", valorAntesDe);
        free(nuevoNodo);
    } else {
        nuevoNodo->nuevo = auxiliar->nuevo;
        auxiliar->nuevo = nuevoNodo;
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
        int valorAntesDe, nuevoValor;
        printf("Ingrese el valor del nuevo elemento: ");
        scanf("%d", &nuevoValor);
        printf("Ingrese el valor del nodo antes del cual insertar: ");
        scanf("%d", &valorAntesDe);

        insertarAntesDe(&principal, nuevoValor, valorAntesDe);

        printf("Lista despues de la insercion: ");
        mostrarLista(principal);

        printf("¿Desea insertar otro elemento? (s/n): ");
        scanf(" %c", &resp);
    } while (resp == 's' || resp == 'S');

    return 0;
}



