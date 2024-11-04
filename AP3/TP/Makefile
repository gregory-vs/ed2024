# Variáveis
CC = g++
CFLAGS = -Iinclude -Wall
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
EXEC = $(BIN_DIR)/programa

# Lista de arquivos objeto
OBJ = $(OBJ_DIR)/fatorial.o $(OBJ_DIR)/fibonacci.o $(OBJ_DIR)/main.o

# Regra principal para compilar e linkar
all: $(EXEC)

# Linkar os objetos para gerar o executável
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Compilar fatorial.cpp
$(OBJ_DIR)/fatorial.o: $(SRC_DIR)/fatorial.cpp include/fatorial.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/fatorial.cpp -o $(OBJ_DIR)/fatorial.o

# Compilar fibonacci.cpp
$(OBJ_DIR)/fibonacci.o: $(SRC_DIR)/fibonacci.cpp include/fibonacci.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/fibonacci.cpp -o $(OBJ_DIR)/fibonacci.o

# Compilar main.cpp
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp include/fatorial.h include/fibonacci.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o

# Limpeza dos arquivos compilados
clean:
	rm -f $(OBJ_DIR)/*.o $(EXEC)

# Executar o programa
run: all
	./$(EXEC)
