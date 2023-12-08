CC = gcc
SRC = src/*.c
LIBS = -lpthread -lm
EXE = Zephyr
VER = 1.0.0

WFLAGS = -std=gnu11 -Wall -Wextra -Wshadow
RFLAGS = -DNDEBUG -O3 $(WFLAGS) -flto -static

POPCNTFLAGS = -DUSE_POPCNT -msse3 -mpopcnt
PEXTFLAGS   = $(POPCNTFLAGS) -DUSE_PEXT -mbmi2

popcnt:
	$(CC) $(CFLAGS) $(SRC) $(LIBS) $(POPCNTFLAGS) -o $(EXE)

nopopcnt:
	$(CC) $(CFLAGS) $(SRC) $(LIBS) -o $(EXE)

pext:
	$(CC) $(CFLAGS) $(SRC) $(LIBS) $(PEXTFLAGS) -o $(EXE)

release:
	mkdir ../dist
	$(CC) $(RFLAGS) $(SRC) $(LIBS) -o ../dist/$(EXE)$(VER)-x64-nopopcnt.exe
	$(CC) $(RFLAGS) $(SRC) $(LIBS) $(POPCNTFLAGS) -o ../dist/$(EXE)$(VER)-x64-popcnt.exe
	$(CC) $(RFLAGS) $(SRC) $(LIBS) $(PEXTFLAGS) -o ../dist/$(EXE)$(VER)-x64-pext.exe
