# Variáveis
CC = g++
CFLAGS = -Iinclude -Wall -pg
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
EXEC = $(BIN_DIR)/programa

# Lista de arquivos objeto
OBJ = $(OBJ_DIR)/ord_alg.o $(OBJ_DIR)/ordind.o $(OBJ_DIR)/utils.o $(OBJ_DIR)/main.o

# Regra principal para compilar e linkar
all: $(EXEC)

# Linkar os objetos para gerar o executável
$(EXEC): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJ) -o $(EXEC) -pg 

# Compilar ord_alg.cpp
$(OBJ_DIR)/ord_alg.o: $(SRC_DIR)/ord_alg.cpp include/ord_alg.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/ord_alg.cpp -o $(OBJ_DIR)/ord_alg.o

# Compilar ordind.cpp
$(OBJ_DIR)/ordind.o: $(SRC_DIR)/ordind.cpp include/ordind.h include/ord_alg.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/ordind.cpp -o $(OBJ_DIR)/ordind.o

# Compilar utils.cpp
$(OBJ_DIR)/utils.o: $(SRC_DIR)/utils.cpp include/utils.h include/ordind.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/utils.cpp -o $(OBJ_DIR)/utils.o

# Compilar main.cpp
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp include/ordind.h include/ord_alg.h include/utils.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o

# Limpeza dos arquivos compilados
clean:
	rm -f $(OBJ_DIR)/*.o $(EXEC) gmon.out saida.xcsv

# Executar o programa
run: all
	./$(EXEC) ../entrada.xcsv ../saida.xcsv

# Profiling com gprof
profile: run
	gprof $(EXEC) gmon.out > gprof_report.txt
