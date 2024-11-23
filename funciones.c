#include <stdio.h>
#include <string.h>

void inicializarProductos(char (*nombres)[50], int *tiempos, int *recursosFinancieros, int *demandas, int maxProductos) {
    for (int i = 0; i < maxProductos; i++) {
        nombres[i][0] = '\0';
        *(tiempos + i) = -1; 
        *(recursosFinancieros + i) = -1;
        *(demandas + i) = 0;
    }
}

void ingresarProductos(char (*nombres)[50], int *tiempos, int *recursosFinancieros, int *demandas, int maxProductos) {
    for (int i = 0; i < maxProductos; i++) {
        if (*(tiempos + i) == -1) {
            printf("Ingrese el nombre del producto: ");
            getchar();
            fgets(*(nombres + i), 50, stdin);
            nombres[i][strcspn(*(nombres + i), "\n")] = '\0';

            printf("Ingrese el tiempo de produccion (en minutos): ");
            scanf("%d", (tiempos + i));

            printf("Ingrese el costo por unidad: ");
            scanf("%d", (recursosFinancieros + i));

            printf("Producto '%s' ingresado correctamente.\n", *(nombres + i));
            break;
        }
    }
}

void editarProducto(char (*nombres)[50], int *tiempos, int *recursosFinancieros, int *demandas, int maxProductos) {
    char nombre[50];
    printf("Ingrese el nombre del producto a editar: ");
    getchar();
    fgets(nombre, 50, stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    for (int i = 0; i < maxProductos; i++) {
        if (strcmp(*(nombres + i), nombre) == 0) {
            printf("Nuevo nombre (actual: %s): ", *(nombres + i));
            fgets(*(nombres + i), 50, stdin);
            nombres[i][strcspn(*(nombres + i), "\n")] = '\0';

            printf("Nuevo tiempo de producción (actual: %d): ", *(tiempos + i));
            scanf("%d", (tiempos + i));

            printf("Nuevo costo financiero por unidad (actual: %d): ", *(recursosFinancieros + i));
            scanf("%d", (recursosFinancieros + i));
            return;
        }
    }

    printf("Producto no encontrado.\n");
}

void eliminarProducto(char (*nombres)[50], int *tiempos, int *recursosFinancieros, int *demandas, int maxProductos) {
    char nombre[50];
    printf("Ingrese el nombre del producto a eliminar: ");
    getchar();
    fgets(nombre, 50, stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    for (int i = 0; i < maxProductos; i++) {
        if (strcmp(*(nombres + i), nombre) == 0) {
            *(nombres + i)[0] = '\0';
            *(tiempos + i) = -1;
            *(recursosFinancieros + i) = -1;
            *(demandas + i) = 0;
            printf("Producto eliminado.\n");
            return;
        }
    }

    printf("Producto no encontrado.\n");
}

int calcularTiempoTotal(int *tiempos, int *demandas, int maxProductos) {
    int total = 0;
    for (int i = 0; i < maxProductos; i++) {
        if (*(tiempos + i) != -1 && *(demandas + i) > 0) {
            total += (*(tiempos + i)) * (*(demandas + i));
        }
    }
    return total;
}

int calcularRecursosTotales(int *recursosFinancieros, int *demandas, int maxProductos) {
    int total = 0;
    for (int i = 0; i < maxProductos; i++) {
        if (*(recursosFinancieros + i) != -1 && *(demandas + i) > 0) {
            total += (*(recursosFinancieros + i)) * (*(demandas + i));
        }
    }
    return total;
}

int verificarViabilidad(int *tiempos, int *recursosFinancieros, int *demandas, int maxProductos, int tiempoDisp, int presupuestoMensual) {
    int tiempoTotal = calcularTiempoTotal(tiempos, demandas, maxProductos);
    int recursosTotal = calcularRecursosTotales(recursosFinancieros, demandas, maxProductos);

    printf("\nVerificacion de Viabilidad\n");
    printf("Presupuesto mensual disponible: %d\n", presupuestoMensual);
    printf("Tiempo disponible: %d minutos\n", tiempoDisp);
    printf("Recursos financieros requeridos: %d\n", recursosTotal);
    printf("Tiempo total requerido: %d minutos\n", tiempoTotal);

    int tiempoViable = (tiempoTotal <= tiempoDisp);
    int presupuestoViable = (recursosTotal <= presupuestoMensual);

    if (tiempoViable && presupuestoViable) {
        printf("El pedido es viable.Cumple con tiempo y presupuesto.\n");
    } else {
        printf("El pedido NO es viable. Razones:\n");
        
        if (!tiempoViable) {
            printf(" - Tiempo insuficiente: Requerido: %d minutos, Disponible: %d minutos\n", tiempoTotal, tiempoDisp);
        }
        if (!presupuestoViable) {
            printf(" - Presupuesto insuficiente: Requerido: %d, Disponible: %d\n", recursosTotal, presupuestoMensual);
        }
    }

    return (tiempoViable && presupuestoViable);
}

void realizarPedido(char (*nombres)[50], int *demandas, int maxProductos) {
    char nombre[50];
    printf("Ingrese el nombre del producto para realizar un pedido: ");
    getchar();
    fgets(nombre, 50, stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    for (int i = 0; i < maxProductos; i++) {
        if (strcmp(*(nombres + i), nombre) == 0) {
            printf("\nProducto encontrado: %s\n", *(nombres + i));
            printf("Cantidad actual pedida: %d\n", *(demandas + i));

            int nuevaDemanda;
            printf("Ingrese la nueva cantidad del pedido: ");
            scanf("%d", &nuevaDemanda);

            *(demandas + i) = nuevaDemanda;
            printf("Pedido actualizado para '%s'. Nueva demanda: %d\n", *(nombres + i), *(demandas + i));
            return;
        }
    }
    printf("Producto no encontrado. Verifique el nombre e intente nuevamente.\n");
}
