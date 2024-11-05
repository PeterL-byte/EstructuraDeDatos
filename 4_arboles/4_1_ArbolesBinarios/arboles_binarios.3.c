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

void recorridoInorden(struct Nodo* raiz) {
    if (raiz == NULL) {
        return;
    }
    recorridoInorden(raiz->izquierdo);
    printf("%d ", raiz->info);
    recorridoInorden(raiz->derecho);
}

int main() {
    struct Nodo* raiz = nuevoNodo(1);
    raiz->izquierdo = nuevoNodo(2);
    raiz->derecho = nuevoNodo(3);
    raiz->izquierdo->izquierdo = nuevoNodo(4);
    raiz->izquierdo->derecho = nuevoNodo(5);
    raiz->derecho->izquierdo = nuevoNodo(6);
    raiz->derecho->derecho = nuevoNodo(7);

    printf("Recorrido en orden (inorden) del árbol binario: ");
    recorridoInorden(raiz);
    printf("\n");

    return 0;
}





