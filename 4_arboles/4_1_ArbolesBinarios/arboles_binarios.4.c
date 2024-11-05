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

void recorridoPostorden(struct Nodo* raiz) {
    if (raiz == NULL) {
        return;
    }
    recorridoPostorden(raiz->izquierdo);
    recorridoPostorden(raiz->derecho);
    printf("%d ", raiz->info);
}

int main() {
    struct Nodo* raiz = nuevoNodo(1);
    raiz->izquierdo = nuevoNodo(2);
    raiz->derecho = nuevoNodo(3);
    raiz->izquierdo->izquierdo = nuevoNodo(4);
    raiz->izquierdo->derecho = nuevoNodo(5);
    raiz->derecho->izquierdo = nuevoNodo(6);
    raiz->derecho->derecho = nuevoNodo(7);

    printf("Recorrido en postorden del árbol binario: ");
    recorridoPostorden(raiz);
    printf("\n");

    return 0;
}

