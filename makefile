SRC_DIR := src
INC_DIR := include
OBJ_DIR := obj
LIB_DIR := libs

# Nome do executável
TARGET := programa

SRCS := $(wildcard $(SRC_DIR)/*.c) main.c

OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(filter-out main.c,$(SRCS))) $(OBJ_DIR)/main.o

CC := gcc

CFLAGS := -Wall -I$(INC_DIR)

# Bibliotecas
LIBS := -Llibs -lHardwareControl

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/registers.o: $(SRC_DIR)/registers.c
	gcc -c src/registers.c -o $(OBJ_DIR)/registers.o -Llibs -lhardwareControl -Iinclude

$(shell mkdir -p $(OBJ_DIR))

clean:
	$(RM) -r $(OBJ_DIR) $(TARGET)

run: $(TARGET)
	./$(TARGET)
