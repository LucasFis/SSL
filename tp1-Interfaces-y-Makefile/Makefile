CFLAGS = -Wno-implicit-function-declaration

start: Conversion.o TablasDeConversion.o
	gcc $(CFLAGS) Conversion.o TablasDeConversion.o -o TablasDeConversion
	del TablasDeConversion.o Conversion.o
	cls
	.\TablasDeConversion.exe
	del TablasDeConversion.exe

start_test: Conversion.o ConversionTest.o
	gcc $(CFLAGS) Conversion.o ConversionTest.o -o ConversionTest
	del ConversionTest.o Conversion.o
	cls
	.\ConversionTest.exe
	del ConversionTest.exe

all: Conversion.o ConversionTest.o
	gcc $(CFLAGS) Conversion.o ConversionTest.o -o ConversionTest

Conversion.o: Conversion.c Conversion.h
	gcc $(CFLAGS) -c Conversion.c

ConversionTest.o: ConversionTest.c Conversion.h
	gcc $(CFLAGS) -c ConversionTest.c

TablasDeConversion.o: TablasDeConversion.c Conversion.h
	gcc $(CFLAGS) -c TablasDeConversion.c

clean:
	del ConversionTest.o Conversion.o TablasDeConversion.o 