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
        return;
    }
    struct Nodo* auxiliar = *principal;
    while (auxiliar->nuevo != NULL) {
        auxiliar = auxiliar->nuevo;
    }
    auxiliar->nuevo = nuevoNodo;
}

void mostrarLista(struct Nodo* principal) {
    struct Nodo* auxiliar = principal;
    while (auxiliar != NULL) {
        printf("%d -> ", auxiliar->info);
        auxiliar = auxiliar->nuevo;
    }
    printf("NULL\n");
}

int main() {
    struct Nodo* principal = NULL;

    insertarFinal(&principal, 2);
    insertarFinal(&principal, 3);

    int info;
    char resp;

    do {
        printf("Lista actual: ");
        mostrarLista(principal);

        printf("Ingrese un elemento a insertar: ");
        scanf("%d", &info);
        insertarFinal(&principal, info);

        printf("¿Desea insertar otro elemento? (s/n): ");
        scanf(" %c", &resp);

    } while (resp == 's' || resp == 'S');

    printf("Lista final: ");
    mostrarLista(principal);

    struct Nodo* auxiliar;
    while (principal != NULL) {
        auxiliar = principal;
        principal = principal->nuevo;
        free(auxiliar);
    }

    return 0;
}

