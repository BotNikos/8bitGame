BIN=bin
LIB=lib

main: main.c $(BIN)/libgame.a $(BIN)/libsdlHelper.a
	clang -g main.c -o main -L./$(BIN) -lSDL2 -lSDL2_image -lgame -lsdlHelper

$(BIN)/libgame.a: $(BIN)/being.o $(BIN)/map.o
	ar -rsc $(BIN)/libgame.a $(BIN)/being.o $(BIN)/map.o

$(BIN)/being.o: $(LIB)/being.c bin
	clang -c -g $(LIB)/being.c -o $(BIN)/being.o

$(BIN)/map.o: $(LIB)/map.c bin
	clang -c -g $(LIB)/map.c -o $(BIN)/map.o

$(BIN)/libsdlHelper.a: $(BIN)/sdlHelper.o
	ar -rsc $(BIN)/libsdlHelper.a $(BIN)/sdlHelper.o

$(BIN)/sdlHelper.o: $(LIB)/sdlHelper.c bin
	clang -c -g $(LIB)/sdlHelper.c -o $(BIN)/sdlHelper.o

bin:
	mkdir $(BIN)

clean:
	rm -r bin 

run: main
	./main
