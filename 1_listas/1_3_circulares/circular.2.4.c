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


struct Nodo* encontrarUltimo(struct Nodo* principal) {
    struct Nodo* auxiliar = principal;
    while (auxiliar->nuevo != principal) {
        auxiliar = auxiliar->nuevo;
    }
    return auxiliar;
}

void eliminarDespuesDe(struct Nodo** principal, int valor) {
    if (*principal == NULL) {
        printf("Lista vacia, no se puede eliminar.\n");
        return;
    }

    struct Nodo* auxiliar = *principal;
    do {
        if (auxiliar->info == valor) {
            struct Nodo* eliminar = auxiliar->nuevo;
            if (eliminar == *principal) {
                // Eliminando el primer elemento
                struct Nodo* ultimo = encontrarUltimo(*principal);
                ultimo->nuevo = eliminar->nuevo;
                free(eliminar);
                *principal = eliminar->nuevo;
            } else {
                // Eliminando un elemento en medio o al final
                auxiliar->nuevo = eliminar->nuevo;
                free(eliminar);
            }
            printf("Elemento eliminado.\n");
            return;
        }
        auxiliar = auxiliar->nuevo;
    } while (auxiliar != *principal);

    printf("Valor %d no encontrado en la lista.\n", valor);
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
        int valor;
        printf("Ingrese el valor del nodo despues del cual desea eliminar un elemento: ");
        scanf("%d", &valor);

        eliminarDespuesDe(&principal, valor);
        printf("Lista despues de la eliminacion: ");
        mostrarLista(principal);

        printf("¿Desea eliminar otro elemento? (s/n): ");
        scanf(" %c", &resp);
    } while (resp == 's' || resp == 'S');

    return 0;
}

