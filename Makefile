SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/union_cronologias $(BIN)/filtradoPalabraClave $(BIN)/filtradoIntervalo
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/union_cronologias:
	g++ src/union_cronologias.cpp src/cronologia.cpp src/eventohistorico.cpp -o bin/union_cronologias -Iinclude -std=c++14 -g

$(BIN)/filtradoPalabraClave:
	g++ src/filtradoPalabraclave.cpp src/cronologia.cpp src/eventohistorico.cpp -o bin/filtradoPalabraClave -Iinclude -std=c++14 -g

$(BIN)/filtradoIntervalo:
	g++ src/filtradoIntervalo.cpp src/cronologia.cpp src/eventohistorico.cpp -o bin/filtradoIntervalo -Iinclude -std=c++14 -g

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
