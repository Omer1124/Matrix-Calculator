calculator : mainmat.o mymat.o check_input.o
	gcc -ansi -Wall -pedantic mainmat.o mymat.o check_input.o -o calculator
mainmat.o : mainmat.c mymat.h input.h
	gcc -c -ansi -Wall -pedantic mainmat.c -o mainmat.o
mymat.o : mymat.c mymat.h
	gcc -c -ansi -Wall -pedantic mymat.c -o mymat.o
check_input.o : check_input.c input.h
	gcc -c -ansi -Wall -pedantic check_input.c -o check_input.o

