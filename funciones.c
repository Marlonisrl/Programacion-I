#include <stdio.h>
#include <string.h>
#include "funciones.h"

void mostrarMenu() {
    printf("\n--- Menú ---\n");
    printf("1. Ingresar Producto\n");
    printf("2. Editar Producto\n");
    printf("3. Eliminar Producto\n");
    printf("4. Listar Productos\n");
    printf("5. Salir\n");
}

int validarOpcion(int opcion) {
    return (opcion >= 1 && opcion <= 5);
}

void ingresarProducto(char nombre[][50], int cantidad[], float precio[], float precioTotal[], int *numProductos) {
    printf("\nIngresar Producto\n");
    printf("Nombre: ");
    scanf("%s", nombre[*numProductos]);
    printf("Cantidad: ");
    scanf("%d", &cantidad[*numProductos]);
    printf("Precio: ");
    scanf("%f", &precio[*numProductos]);

    // Calcular precio total con IVA
    precioTotal[*numProductos] = precio[*numProductos] * (1 + 0.12) * cantidad[*numProductos];
    (*numProductos)++;
}

void editarProducto(char nombre[][50], int cantidad[], float precio[], float precioTotal[], int numProductos) {
    printf("\nEditar Producto\n");
    // Mostrar la lista de productos para que el ADMINISTRADOR seleccione cuál editar
    listarProductos(nombre, cantidad, precio, precioTotal, numProductos);

    int indice;
    printf("Ingrese el nombre del producto que desea editar: ");
    scanf("%d", &indice);

    if (indice >= 0 && indice < numProductos) {
        printf("Nuevo producto o corrija sus faltas ortograficas:\n ");
        scanf("%s", nombre[indice]);
      
        printf("Ingrese la nueva cantidad:\n ");
        scanf("%d", &cantidad[indice]);
      
        printf("Ingrese el precio unitario:\n ");
        scanf("%f", &precio[indice]);

        // Calcular el nuevo precio total con IVA
        precioTotal[indice] = precio[indice] * (1 + 0.12) * cantidad[indice];

        printf("Producto editado con éxito.\n");
    } else {
        printf("Índice no válido. La edición ha fallado.\n");
    }
}

void eliminarProducto(char nombre[][50], int cantidad[], float precio[], float precioTotal[], int *numProductos) {
    printf("\nEliminar Producto\n");
    listarProductos(nombre, cantidad, precio, precioTotal, *numProductos);

    char nombreEliminar[50];
    printf("Ingrese el nombre del producto que desea eliminar: ");
    scanf("%s", nombreEliminar);

    int cantidadEliminar;
    printf("Ingrese la cantidad que desea eliminar: ");
    scanf("%d", &cantidadEliminar);

    int indice = -1;  
  // Inicializamos el índice a -1 como indicador de no encontrar
    int cantidadTotal = 0;  
  // Variable para rastrear la cantidad total del producto

    // Buscar el producto por nombre y cantidad
    for (int i = 0; i < *numProductos; i++) {
      //strcmp para comparar
        if (strcmp(nombre[i], nombreEliminar) == 0) {
            cantidadTotal += cantidad[i];

            // Si encontramos suficiente cantidad del producto, establecemos el índice y salimos 
            if (cantidadTotal >= cantidadEliminar) {
                indice = i;
                break;
            }
        }
    }

    if (indice != -1) {
        // Reducir la cantidad del producto
        cantidad[indice] -= cantidadEliminar;

        // Si la cantidad llega a cero, eliminar completamente el producto
        if (cantidad[indice] == 0) {
            // Eliminar el producto moviendo los elementos restantes
          //copia cada cadena de caracteres
            for (int i = indice; i < *numProductos - 1; i++) {
                strcpy(nombre[i], nombre[i + 1]);
                cantidad[i] = cantidad[i + 1];
                precio[i] = precio[i + 1];
                precioTotal[i] = precioTotal[i + 1];
            }
            (*numProductos)--;
        }

        printf("Se eliminaron %d unidades del producto '%s' con éxito.\n", cantidadEliminar, nombreEliminar);
    } else {
        printf("No se pudo eliminar el producto '%s' o la cantidad solicitada es mayor a la disponible.\n", nombreEliminar);
    }
}

void listarProductos(char nombre[][50], int cantidad[], float precio[], float precioTotal[], int numProductos) {
    printf("\nLista de Productos\n");
    printf("%-20s %-10s %-15s %-15s\n", "Nombre", "Cantidad", "Precio Unitario", "Precio Total con IVA");
    for (int i = 0; i < numProductos; i++) {
        printf("%-20s %-10d $%-15.2f $%-15.2f\n", nombre[i], cantidad[i], precio[i], precioTotal[i]);
    }
    printf("\nPolíticas:\n");
    printf("-- No se aceptan devoluciones ni cambios después de salir de la tienda. --\n");
  printf("-- Todos los productos estan bajo la normativa ISO 9001. --\n");
    printf("-- Los datos del cliente para facturación están protegidos. --\n");
}
