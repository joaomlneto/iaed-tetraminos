# Nome do executavel (ver enunciado)
COMPILER = gcc
COMPILER_OPTIONS = -ansi -pedantic -Wall
EXE = "proj3"

all: $(EXE)

clean:
	rm *.o

wipe: clean
	rm $(EXE)

$(EXE): main.o functions.o gamearea.o heightmap.o line.o t_hash.o t_location.o position.o tetromino.o
	$(COMPILER) -o $(EXE) main.o functions.o gamearea.o heightmap.o line.o t_hash.o t_location.o position.o tetromino.o -lm

main.o: main.c main.h
	$(COMPILER) $(COMPILER_OPTIONS) -c main.c

functions.o: functions.c functions.h
	$(COMPILER) $(COMPILER_OPTIONS) -c functions.c

gamearea.o: gamearea.c gamearea.h
	$(COMPILER) $(COMPILER_OPTIONS) -c gamearea.c

heightmap.o: heightmap.c heightmap.h
	$(COMPILER) $(COMPILER_OPTIONS) -c heightmap.c

line.o: line.c line.h
	$(COMPILER) $(COMPILER_OPTIONS) -c line.c

t_hash.o: t_hash.c t_hash.h
	$(COMPILER) $(COMPILER_OPTIONS) -c t_hash.c

t_location.o: t_location.c t_location.h
	$(COMPILER) $(COMPILER_OPTIONS) -c t_location.c

position.o: position.c position.h
	$(COMPILER) $(COMPILER_OPTIONS) -c position.c

tetromino.o: tetromino.c tetromino.h
	$(COMPILER) $(COMPILER_OPTIONS) -c tetromino.c
