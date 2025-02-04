GCC=gcc

start: main.o scanner.o parser.o list.o svgoutput.o semantic.o manejadorErrores.o
	$(GCC) main.o scanner.o parser.o list.o svgoutput.o semantic.o manejadorErrores.o -o main.exe

main.o: main.c
	$(GCC) -c main.c -o main.o

scanner.o: scanner.c scanner.h
	$(GCC) -c scanner.c -o scanner.o

parser.o: parser.c parser.h
	$(GCC) -c parser.c -o parser.o

list.o: list.c list.h
	$(GCC) -c list.c -o list.o

svgoutput.o: svgoutput.c svgoutput.h
	$(GCC) -c svgoutput.c -o svgoutput.o

semantic.o: semantic.c semantic.h
	$(GCC) -c semantic.c -o semantic.o

manejadorErrores.o: manejadorErrores.c manejadorErrores.h
	$(GCC) -c manejadorErrores.c -o manejadorErrores.o

test_w: start
	main.exe < test.txt
#windows

test_l: start
	./main.exe < test.txt
#Linux

clean_w: 
	del *.o *.exe
#windows

clean_l:
	rm -f *.o *.exe
#linux

.PHONY: test_w test_l clean_w clean_l start