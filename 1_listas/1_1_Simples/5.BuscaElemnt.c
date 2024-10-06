#include <stdio.h>
#include <stdlib.h>


struct Nodo {
    int info;
    struct Nodo* liga;
};


struct Nodo* crearNodo(int dato) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->info = dato;
    nuevoNodo->liga = NULL;
    return nuevoNodo;
}


void buscarElemento(struct Nodo* p, int x) {
    if (p == NULL) {
        printf("No hay elementos donde buscar.\n");
        return;
    }

    struct Nodo* q = p;

    
    while (q != NULL && q->info != x) {
        q = q->liga;
    }

    
    if (q != NULL && q->info == x) {
        printf("El elemento sí existe.\n");
    } else {
        printf("El elemento no existe.\n");
    }
}

int main() {
    struct Nodo *p = NULL, *q = NULL;
    char resp;
    int dato, x;

    
    printf("Ingrese el dato: ");
    scanf("%d", &dato);
    
    p = crearNodo(dato);  
    q = p;

    printf("¿Ingresarás más datos (S/N)? ");
    scanf(" %c", &resp);

    while (resp == 'S' || resp == 's') {
        printf("Ingrese el siguiente dato: ");
        scanf("%d", &dato);

        q->liga = crearNodo(dato);  
        q = q->liga;  

        printf("¿Ingresarás más datos (S/N)? ");
        scanf(" %c", &resp);
    }

    
    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &x);

    buscarElemento(p, x);

    return 0;
}

