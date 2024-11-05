#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int info;
    struct Nodo* izquierdo;
    struct Nodo* derecho;
};

struct Nodo* nuevoNodo(int info) {
    struct Nodo* nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nodo->info = info;
    nodo->izquierdo = NULL;
    nodo->derecho = NULL;
    return nodo;
}

struct Nodo* insertar(struct Nodo* raiz, int info) {
    if (raiz == NULL) {
        return nuevoNodo(info);
    }

    if (info < raiz->info) {
        raiz->izquierdo = insertar(raiz->izquierdo, info);
    } else if (info > raiz->info) {
        raiz->derecho = insertar(raiz->derecho, info);
    }

    return raiz;
}

struct Nodo* buscar(struct Nodo* raiz, int info) {
    if (raiz == NULL || raiz->info == info) {
        return raiz;
    }

    if (info < raiz->info) {
        return buscar(raiz->izquierdo, info);
    }

    return buscar(raiz->derecho, info);
}

int main() {
    struct Nodo* raiz = NULL;
    int valor, valorABuscar;


    raiz = insertar(raiz, 50);
    raiz = insertar(raiz, 30);
    raiz = insertar(raiz, 20);
    raiz = insertar(raiz, 40);
    raiz = insertar(raiz, 70);
    raiz = insertar(raiz, 60);
    raiz = insertar(raiz, 80);


    printf("Introduce el valor a buscar en el árbol: ");
    scanf("%d", &valorABuscar);


    struct Nodo* resultado = buscar(raiz, valorABuscar);

 
    if (resultado != NULL) {
        printf("El valor %d se encontró en el árbol.\n", valorABuscar);
    } else {
        printf("El valor %d no se encuentra en el árbol.\n", valorABuscar);
    }

    return 0;
}


