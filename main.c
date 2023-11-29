#include <stdio.h>
#include <string.h>
#include "funciones.h"
#include <math.h>


int main() {
    char nombres[100][50];
    int cantidades[100];
    float precios[100];
    float preciosTotales[100];
    int numProductos = 0;
    int escoger;

    do {
        mostrarMenu();
        printf("Seleccione una opción: ");
        scanf("%d", &escoger);

        if (validarOpcion(escoger)) {
            switch (escoger) {
                case 1:
                    ingresarP(nombres, cantidades, precios, preciosTotales, &numProductos);
                    break;
                case 2:
                    editarPr(nombres, cantidades, precios, preciosTotales, numProductos);
                    break;
                case 3:
                    eliminarP(nombres, cantidades, precios, preciosTotales, &numProductos);
                    break;
                case 4:
                    lista(nombres, cantidades, precios, preciosTotales, numProductos);
                    break;
            }
        } else {
            printf("Opción no válida. Escoge una opción valida\n");
        }
    } while (escoger != 5);

    printf("¡ADMINISTRADOR RECUERDA SIEMPRE REGISTRAR EL STOCK BAY!\n");

    return 0;
}
