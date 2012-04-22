CC := gcc
OS := MAC
CFLAGS := -D$(OS) -Iinclude
OBJETOS := main.o include/my_function.o include/zanahoria.o include/memoria.o
FUENTES := main.c include/my_function.c include/zanahoria.c include/memoria.c

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

clean:
	rm -f *.o zanahoria include/*.o

start:
	clear && ./zanahoria

push:
	git push origin master && git push bitorigin master