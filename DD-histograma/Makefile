CC = gcc
CFLAGS = 

start: main.o Graficador.o histograma1.o histograma2.o histograma3.o histogramax.o
	$(CC) main.o Graficador.o histograma1.o histograma2.o histograma3.o histogramax.o -o main
	
test: test.o histograma1.o histograma2.o histograma3.o histogramax.o
	$(CC) test.o histograma1.o histograma2.o histograma3.o histogramax.o -o $@
	@.\test.exe < Graficador.h

graficador.o: Graficador.c Graficador.h
	$(CC) -c Graficador.c -o $@

main.o: main.c 
	$(CC) -c main.c -o $@

test.o: Test.c 
	$(CC) -c Test.c -o $@
histograma1.o: histograma-1-enum-switch.c histograma.h
	$(CC) -c histograma-1-enum-switch.c -o $@

histograma2.o: histograma-2-goto.c histograma.h
	$(CC) -c histograma-2-goto.c -o $@

histograma3.o: histograma-3-rec.c histograma.h
	$(CC) -c histograma-3-rec.c -o $@

histogramax.o: histograma-x.c histograma.h
	$(CC) -c histograma-x.c -o $@
clean:
	@del -f *.o *.exe

.PHONY: test clean start