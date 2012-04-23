CC := gcc
OS := MAC
CFLAGS := -D$(OS) -Iinclude -lm
OBJETOS := main.o include/my_function.o include/zanahoria.o include/memoria.o include/colores.o include/printascii.o
FUENTES := main.c include/my_function.c include/zanahoria.c include/memoria.c include/colores.c include/printascii.c

.PHONY: clean start push

zanahoria: $(OBJETOS)
	$(CC) $(CFLAGS) $(OBJETOS) -o zanahoria

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

my_function.o: my_function.c
	$(CC) $(CFLAGS) -c my_function.c

zanahoria.o: zanahoria.c
	$(CC) $(CFLAGS) -c zanahoria.c

memoria.o: memoria.c
	$(CC) $(CFLAGS) -c memoria.c

colores.o: colores.c
	$(CC) $(CFLGAS) -c colores.c

printascii.o: printascii.c
	$(CC) $(CFLAGS) -c printascii.c

clean:
	rm -f *.o zanahoria include/*.o

start:
	clear && ./zanahoria

push:
	git push origin master && git push bitorigin master