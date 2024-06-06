CC:=gcc
objects:=error.o sections.o main.o
output:=main

main:$(objects)
	$(CC) $(objects) -o main
	
main.o:main.c libs.h
	$(CC) -c main.c -o main.o	

error.o:error.c error.h
	$(CC) -c error.c -o error.o
	
sections.o:sections.c sections.h
	$(CC) -c sections.c -o sections.o

clean:
	rm -f $(objects) $(output)



