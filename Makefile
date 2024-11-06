CC = clang

SRC = src
BUILD = build
INCLUDE = include

OBJS = $(BUILD)/being.o
OBJS += $(BUILD)/hero.o
OBJS += $(BUILD)/main.o

SDL_FLAGS = -L/usr/local/lib -Wl,-rpath,/usr/local/lib -Wl,--enable-new-dtags -lSDL3
SDL_FLAGS += -lSDL3_image

CFLAGS = -I./$(INCLUDE)

main: $(BUILD) $(OBJS)
	$(CC) -g $(OBJS) -o $@ $(SDL_FLAGS)

$(BUILD)/main.o: main.c
	$(CC) -g -c main.c -o $@ $(CFLAGS)

$(BUILD)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	$(CC) -g -c $< -o $@ $(CFLAGS)

$(BUILD):
	mkdir $(BUILD)

clean:
	rm -r main build/

run:
	./main

