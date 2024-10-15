SRC = src
INCLUDE = include

BUILD = build

OBJS = $(BUILD)/being.o
OBJS += $(BUILD)/hero.o
OBJS += $(BUILD)/main.o

SDL_FLAGS = $(shell pkg-config sdl3 --cflags --libs)
SDL_FLAGS += -lSDL3_image

CFLAGS = -I./$(INCLUDE)

main: $(OBJS)
	clang -g $(OBJS) -o $@ $(SDL_FLAGS)

$(BUILD)/main.o: main.c
	clang -g -c main.c -o $@ $(CFLAGS)

$(BUILD)/%.o: $(SRC)/%.c $(INCLUDE)/%.h $(BUILD)
	clang -g -c $< -o $@ $(CFLAGS)

$(BUILD):
	mkdir $(BUILD)

clean:
	rm -r main build/

run:
	./main

