#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define MAX_PRODUCTOS 5

int main() {
    char nombres[MAX_PRODUCTOS][50];
    int tiempos[MAX_PRODUCTOS];
    int recursosFinancieros[MAX_PRODUCTOS];
    int demandas[MAX_PRODUCTOS];


    inicializarProductos(nombres, tiempos, recursosFinancieros, demandas, MAX_PRODUCTOS);

    int opcion;
    do {
        printf("\nMenu\n");
        printf("1. Ingresar productos\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Calcular tiempo total\n");
        printf("5. Calcular recursos financieros totales\n");
        printf("6. Realizar pedido de un producto\n");
        printf("7. Verificar viabilidad\n");
        printf("8. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarProductos(nombres, tiempos, recursosFinancieros, demandas, MAX_PRODUCTOS);
                break;
            case 2:
                editarProducto(nombres, tiempos, recursosFinancieros, demandas, MAX_PRODUCTOS);
                break;
            case 3:
                eliminarProducto(nombres, tiempos, recursosFinancieros, demandas, MAX_PRODUCTOS);
                break;
            case 4:
                printf("Tiempo total: %d minutos\n", calcularTiempoTotal(tiempos, demandas, MAX_PRODUCTOS));
                break;
            case 5:
                printf("Recursos financieros totales: %d\n", calcularRecursosTotales(recursosFinancieros, demandas, MAX_PRODUCTOS));
                break;
            case 6:
                realizarPedido(nombres, demandas, MAX_PRODUCTOS);
                break;
            case 7: {
                int recursosDisp, tiempoDisp;
                printf("Ingrese presupuesto disponible (mensual): ");
                scanf("%d", &recursosDisp);
                printf("Ingrese tiempo disponible (en minutos): ");
                scanf("%d", &tiempoDisp);
                int cumple = verificarViabilidad(tiempos, recursosFinancieros, demandas, MAX_PRODUCTOS, tiempoDisp, recursosDisp);
                break;
            }
            case 8:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 8);

    return 0;
}