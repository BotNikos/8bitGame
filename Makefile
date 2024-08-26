main: main.c
	clang -g main.c -o main -lSDL2 -lSDL2_image

run: main
	./main
