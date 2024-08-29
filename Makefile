BUILD=build
BIN=bin
LIB=lib

main: main.c $(BUILD)/libgame.a $(BUILD)/libsdlHelper.a
	clang -g main.c -o main -L./$(BUILD) -lSDL2 -lSDL2_image -lgame -lsdlHelper

$(BUILD)/libgame.a: $(BIN)/being.o build
	ar -rsc $(BUILD)/libgame.a $(BIN)/being.o

$(BIN)/being.o: $(LIB)/being.c bin
	clang -c $(LIB)/being.c -o $(BIN)/being.o

$(BUILD)/libsdlHelper.a: $(BIN)/sdlHelper.o build
	ar -rsc $(BUILD)/libsdlHelper.a $(BIN)/sdlHelper.o

$(BIN)/sdlHelper.o: $(LIB)/sdlHelper.c bin
	clang -c $(LIB)/sdlHelper.c -o $(BIN)/sdlHelper.o

bin:
	mkdir $(BIN)

build:
	mkdir $(BUILD)

run: main
	./main
