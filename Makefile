INCLUDE = include
LEVELS = levels
SRC = src
BUILD = build

CFLAGS = -L./$(BUILD)
CFLAGS += -lSDL2 -lSDL2_image -lgame
CFLAGS += -I $(INCLUDE) -I $(LEVELS)

OBJS = $(BUILD)/being.o
OBJS += $(BUILD)/map.o
OBJS += $(BUILD)/sdlHelper.o

main: main.c $(BUILD)/libgame.a $(INCLUDE)/game_globals.h
	clang -g main.c -o main $(CFLAGS) 

$(BUILD)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	clang -c -g $< -o $@ -I $(INCLUDE) -I $(LEVELS)

$(BUILD)/libgame.a: $(BUILD) $(OBJS)
	ar -rsc $@ $(OBJS)

$(BUILD):
	mkdir $(BUILD)

clean:
	rm -r build

run: main
	./main
