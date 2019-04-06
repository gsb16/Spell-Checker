# Gabriel de Souza Barreto - GRR 20166812

ortografia: ortografia.o
	gcc ortografia.o -o ortografia -Wall

ortografia.o: ortografia.c
	gcc -c ortografia.c -Wall

clean:
	-rm *.o

purge: clean
	-rm ortografia
