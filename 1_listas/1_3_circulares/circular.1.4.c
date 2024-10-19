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

void buscarElemento(struct Nodo* principal, int info) {
    if (principal == NULL) {
        printf("Lista inexistente.\n");
        return;
    }

    struct Nodo* auxiliar = principal;
    do {
        if (auxiliar->info == info) {
            struct Nodo* antecedente = (auxiliar == principal) ? NULL : principal;
            while (antecedente->nuevo != auxiliar) {
                antecedente = antecedente->nuevo;
            }
            printf("Direccion del antecedente: %p\n", (void*)antecedente);
            printf("Informacion del consecuente: %d\n", auxiliar->nuevo->info);
            return;
        }
        auxiliar = auxiliar->nuevo;
    } while (auxiliar != principal);

    printf("Ningun nodo coincide con la informacion dada.\n");
}

int main() {
    struct Nodo* principal = NULL;
    insertarFinal(&principal, 1);
    insertarFinal(&principal, 2);
    insertarFinal(&principal, 3);

    mostrarLista(principal);

    char resp;
    do {
        int infoBuscar;
        printf("Ingrese el elemento a buscar: ");
        scanf("%d", &infoBuscar);
        buscarElemento(principal, infoBuscar);

        printf("¿Desea buscar otro elemento? (s/n): ");
        scanf(" %c", &resp);
    } while (resp == 's' || resp == 'S');

    return 0;
}

