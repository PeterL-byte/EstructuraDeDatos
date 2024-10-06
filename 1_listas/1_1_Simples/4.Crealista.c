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

int main() {
    struct Nodo *p = NULL, *q = NULL;
    char resp;
    int dato;

    
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

        printf("¿Ingresaras mas datos (S/N)? ");
        scanf(" %c", &resp);
    }

    
    printf("\nElementos en la lista enlazada: ");
    q = p;
    while (q != NULL) {
        printf("%d -> ", q->info);
        q = q->liga;
    }
    printf("NULL\n");

    return 0;
}

