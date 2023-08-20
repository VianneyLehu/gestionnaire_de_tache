opt = -c -Wall -Wextra -std=c11



main.exe: gestionnaire.o main.o 

	gcc -o main.exe gestionnaire.o main.o


main.o: main.c gestionnaire.h 

	gcc ${opt} main.c

gestionnaire.o: gestionnaire.c gestionnaire.h

	gcc ${opt} gestionnaire.c


clean:

	rm *.o
	rm *.exe
