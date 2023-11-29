#include <stdio.h>
#include <string.h>
#include "funciones.h"


int main() {
    char nombres[100][50];
    int cantidades[100];
    float precios[100];
    float preciosTotales[100];
    int numProductos = 0;
    int opcion;

    do {
        mostrarMenu();
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        if (validarOpcion(opcion)) {
            switch (opcion) {
                case 1:
                    ingresarProducto(nombres, cantidades, precios, preciosTotales, &numProductos);
                    break;
                case 2:
                    editarProducto(nombres, cantidades, precios, preciosTotales, numProductos);
                    break;
                case 3:
                    eliminarProducto(nombres, cantidades, precios, preciosTotales, &numProductos);
                    break;
                case 4:
                    listarProductos(nombres, cantidades, precios, preciosTotales, numProductos);
                    break;
            }
        } else {
            printf("Opción no válida. Por favor, seleccione una opción válida.\n");
        }
    } while (opcion != 5);

    printf("¡ADMINISTRADOR RECUERDA SIEMPRE REGISTRAR EL STOCK BAY!\n");

    return 0;
}
