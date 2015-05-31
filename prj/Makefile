# #-----------------------------------
# # makefile for linux (gcc compiler)
# #-----------------------------------
CC         = $(shell which gcc)
CFLAGS     = -Wall -pedantic -O2
LDFLAGS    = -s
LIBS       =
INCLUDE    = -I ./include
SRC_DIR    = ./src
OBJ_DIR    = ./obj
BIN_DIR    = ./bin
SOURCES    = $(shell ls $(SRC_DIR)/*.c)
OBJS       = $(subst $(SRC_DIR),$(OBJ_DIR), $(SOURCES:.c=.o))
TARGET     = $(BIN_DIR)/czt_test
DEPENDS    = $(OBJS:.o=.d)
ASSEMBLIES = $(OBJS:.o=.s)
LISTS      = $(OBJS:.o=.lst)

# コンパイルを実行する
build: create_file $(TARGET)

$(TARGET): $(OBJS) $(LIBS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS) -lm

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

$(OBJ_DIR)%.s : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -S -fverbose-asm -o $@ $<

$(OBJ_DIR)%.lst : $(OBJ_DIR)%.s
	$(CC) -Wa,-a=$@ -c -o NUL $<

# 実行ファイルなどを削除する
clean:
	$(RM) $(OBJS) $(TARGET) $(DEPENDS) $(ASSEMBLIES) $(LISTS)
	$(RM) -r $(BIN_DIR) $(OBJ_DIR)
clear: clean
delete: clean

create_file:
	@if [ ! -d $(BIN_DIR) ]; \
	then echo "mkdir -p $(BIN_DIR)"; mkdir -p $(BIN_DIR); \
	fi
	@if [ ! -d $(OBJ_DIR) ]; \
	then echo "mkdir -p $(OBJ_DIR)"; mkdir -p $(OBJ_DIR); \
	fi

-include $(DEPENDS)

rebuild: clean build

# プログラムを実行する
run: build
	$(TARGET)

# 一時的に実行環境を整える
test: run clean

.PHONY: build clean
