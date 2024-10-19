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

void eliminarNodoPorInfo(struct Nodo** principal, int info) {
    if (*principal == NULL) {
        printf("Lista inexistente.\n");
        return;
    }

    struct Nodo* auxiliar = *principal;
    struct Nodo* previo = NULL;

    while (auxiliar != NULL && auxiliar->info != info) {
        previo = auxiliar;
        auxiliar = auxiliar->nuevo;
    }

    if (auxiliar == NULL) {
        printf("Ningún nodo coincide con la información dada.\n");
        return;
    }

    if (previo == NULL) {
        if (auxiliar->nuevo == NULL) {
            free(auxiliar);
            *principal = NULL;
            printf("Último elemento eliminado, la lista ahora está vacía.\n");
        } else {
            *principal = auxiliar->nuevo;
            free(auxiliar);
            printf("Primer elemento eliminado.\n");
        }
    } else {
        previo->nuevo = auxiliar->nuevo;
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
        eliminarNodoPorInfo(&principal, infoEliminar);
        
        printf("Lista después de eliminar el elemento: ");
        mostrarLista(principal);

        printf("¿Desea eliminar otro elemento? (s/n): ");
        scanf(" %c", &resp);
    } while (resp == 's' || resp == 'S');

    return 0;
}

