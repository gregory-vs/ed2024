# Variáveis
CC = gcc
CFLAGS = -Iinclude -Wall
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
EXEC = $(BIN_DIR)/matop

# Lista de arquivos objeto
OBJ = $(OBJ_DIR)/mat.o $(OBJ_DIR)/matop.o

# Regra principal para compilar e linkar
all: $(EXEC)

# Linkar os objetos para gerar o executável
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Compilar mat.c
$(OBJ_DIR)/mat.o: $(SRC_DIR)/mat.c include/mat.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/mat.c -o $(OBJ_DIR)/mat.o

# Compilar matop.c
$(OBJ_DIR)/matop.o: $(SRC_DIR)/matop.c include/mat.h include/msgassert.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/matop.c -o $(OBJ_DIR)/matop.o

# Limpeza dos arquivos compilados
clean:
	rm -f $(OBJ_DIR)/*.o $(EXEC)

# Executar o programa
run: all
	./$(EXEC) -s -x 5 -y 5
	./$(EXEC) -m -x 5 -y 5
	./$(EXEC) -t -x 5 -y 5
