CC = gcc

run: TablasDeConversion
	@./TablasDeConversion

test: ConversionTest
	@./ConversionTest
all: TablasDeConversion ConversionTest clean

TablasDeConversion: Conversion.o TablasDeConversion.o
	$(CC) Conversion.o TablasDeConversion.o -o $@
	

ConversionTest: Conversion.o ConversionTest.o
	$(CC) Conversion.o ConversionTest.o -o $@
	
ConversionTest.o: ConversionTest.c Conversion.h
	$(CC) -c ConversionTest.c
Conversion.o: Conversion.c Conversion.h
	$(CC) -c Conversion.c

TablasDeConversion.o: TablasDeConversion.c Conversion.h
	$(CC) -c TablasDeConversion.c

clean: 
#	windows
	@del -f *.o
#	unix
#   rm -f *.o 
.PHONY: all clean run test 