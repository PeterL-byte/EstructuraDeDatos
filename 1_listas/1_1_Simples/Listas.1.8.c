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

void eliminarPrimerElemento(struct Nodo** principal) {
    if (*principal == NULL) {
        printf("Lista inexistente\n");
        return;
    }
    
    struct Nodo* auxiliar = *principal;
    
    if (auxiliar->nuevo == NULL) {
        free(auxiliar);
        *principal = NULL;
        printf("Último elemento eliminado, la lista ahora está vacía.\n");
    } else {
        *principal = auxiliar->nuevo;
        free(auxiliar);
        printf("Primer elemento eliminado.\n");
    }
}

int main() {
    struct Nodo* principal = NULL;
    insertarFinal(&principal, 2);
    insertarFinal(&principal, 3);
    insertarFinal(&principal, 4);

    printf("Lista inicial: ");
    mostrarLista(principal);

    eliminarPrimerElemento(&principal);
    printf("Lista despues de eliminar el primer elemento: ");
    mostrarLista(principal);

    char resp;
    do {
        printf("¿Desea eliminar el primer elemento? (s/n): ");
        scanf(" %c", &resp);
        if (resp == 's' || resp == 'S') {
            eliminarPrimerElemento(&principal);
            printf("Lista actual: ");
            mostrarLista(principal);
        }
    } while (resp == 's' || resp == 'S');

    return 0;
}

