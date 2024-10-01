#include <stdio.h>
#include <stdlib.h>

void presentacion(){
    printf("Integrantes del equipo:\n\nintegrante1\nintegrante2\nintegrante3\nintegrante4\n\n");
    system("pause");
}

void listas(){
    system("cls");
    printf("Has seleccionado Listas\n");
    system("pause");
}

void pilas(){
    system("cls");
    printf("Has seleccionado Pilas\n");
    system("pause");
}

void colas(){
    system("cls");
    printf("Has seleccionado Colas\n");
    system("pause");
}

void arboles(){
    system("cls");
    printf("Has seleccionado Arboles\n");
    system("pause");
}

void menu(){
    printf("\n--- Menú ---\n");
    printf("1. Listas\n");
    printf("2. Pilas\n");
    printf("3. Colas\n");
    printf("4. Árboles\n\n");
    printf("5. Salida\n\n");
}

int main(){
    int opcion;
    system("cls");
    presentacion();
    do {
        system("cls");
        menu();
        printf("Selecciona una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                listas();
                break;
            case 2:
                pilas();
                break;
            case 3:
                colas();
                break;
            case 4:
                arboles();
                break;
            case 5:
            	system("cls");
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intenta de nuevo.\n");
                system("pause");
        }
    } while (opcion != 5);
    
    return 0;
}

