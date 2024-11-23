void inicializarProductos(char (*nombres)[50], int *tiempos, int *recursosFinancieros, int *demandas, int maxProductos);
void ingresarProductos(char (*nombres)[50], int *tiempos, int *recursosFinancieros, int *demandas, int maxProductos);
void editarProducto(char (*nombres)[50], int *tiempos, int *recursosFinancieros, int *demandas, int maxProductos);
void eliminarProducto(char (*nombres)[50], int *tiempos, int *recursosFinancieros, int *demandas, int maxProductos);
int calcularTiempoTotal(int *tiempos, int *demandas, int maxProductos);
int calcularRecursosTotales(int *recursosFinancieros, int *demandas, int maxProductos);
int verificarViabilidad(int *tiempos, int *recursosFinancieros, int *demandas, int maxProductos, int tiempoDisp, int presupuestoMensual);
void realizarPedido(char (*nombres)[50], int *demandas, int maxProductos);