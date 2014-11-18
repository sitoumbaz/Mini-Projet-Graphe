CC=gcc

CFLAGS=-c -Wall

OBJ=obj/

all: executable

executable:	main.o lliste.o lgraphe.o utilitaire.o menu.o 
	$(CC) -o bin/executable $(OBJ)main.o $(OBJ)lliste.o $(OBJ)lgraphe.o $(OBJ)utilitaire.o $(OBJ)menu.o

main.o: src/main.c
	$(CC) $(CFLAGS) src/main.c -o $(OBJ)main.o 

lliste.o: src/lliste.c
	$(CC) $(CFLAGS) src/lliste.c -o $(OBJ)lliste.o 

lgraphe.o: src/lgraphe.c
	$(CC) $(CFLAGS) src/lgraphe.c -o $(OBJ)lgraphe.o 
	
utilitaire.o: src/utilitaire.c
	$(CC) $(CFLAGS) src/utilitaire.c -o $(OBJ)utilitaire.o 

menu.o: src/menu.c
	$(CC) $(CFLAGS) src/menu.c -o $(OBJ)menu.o 
	
# creation de la bibliotheque avec .c et .h
library:
	$(CC) $(CFLAGS) src/lgraphe.c -o $(OBJ)lgraphe.o
	ar -q lib/liblgraphe.a $(OBJ)lgraphe.o

	$(CC) $(CFLAGS) src/lliste.c -o $(OBJ)lliste.o
	ar -q lib/liblliste.a $(OBJ)lliste.o
	
cleanlib:
	rm -rf lib/*.a	
clean:
	rm -rf *.o bin/executable $(OBJ)*.o
	
