CC=gcc

OBJ=src/main.o src/vfs.o src/helper.o

vfs: $(OBJ)
	$(CC) -o vfs $(OBJ)

src/main.o:
	$(CC) -c src/main.c

src/vfs.o:
	$(CC) -c src/vfs.c

src/helper.o:
	$(CC) -c src/helper.c

clean:
	rm *.o vfs