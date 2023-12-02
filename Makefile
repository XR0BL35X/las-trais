# Directorios de origen y destino
SRC_DIR := src
BIN_DIR := bin

SFML := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lchipmunk
PROYECT := $(BIN_DIR)/LasTrais


# Obtener todos los archivos .cpp en el directorio de origen
CPP_FILES := $(wildcard $(SRC_DIR)/*.cpp)

# Regla para compilar el proyecto
$(PROYECT) : $(CPP_FILES)
	g++ $? -o $@ $(SFML) -Iinclude

# Regla para ejecutar cada archivo .exe
run: $(PROYECT)
	./$<

