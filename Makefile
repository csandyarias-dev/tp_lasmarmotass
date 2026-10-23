# --- Variables ---
# Definimos el compilador
CC = gcc
# Flags de compilación: -c (solo compilar), -Wall (mostrar warnings), -I (incluir headers)
CFLAGS = -c -Wall -I./inc
# Flags de linkeo
LDFLAGS = -Wall

# --- Directorios ---
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
BIN_DIR = bin

# Nombre del archivo ejecutable
EJECUTABLE = $(BIN_DIR)/programa.out

# --- Archivos ---
# Busca automáticamente todos los archivos .c dentro de la carpeta src/
SOURCES = $(wildcard $(SRC_DIR)/*.c)
# Reemplaza la ruta src/ y extensión .c por obj/ y .o
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

# --- Reglas ---
# La primera regla es la que se ejecuta por defecto si haces un simple "make"
all: $(EJECUTABLE)

# Regla para linkear y generar el ejecutable final
# La macro $@ representa el nombre de la regla (el target)
$(EJECUTABLE): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)

# Regla genérica (usando el comodín %) para compilar los objetos
# $< representa el primer archivo de las dependencias (el .c correspondiente)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	$(CC) $(CFLAGS) $< -o $@

# Regla para limpiar los objetos y el ejecutable
clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(EJECUTABLE)

# Regla para borrar todo y recompilar desde cero
new: clean all
