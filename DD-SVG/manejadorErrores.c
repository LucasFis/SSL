#include "manejadorErrores.h"
#include <stdio.h>
#include <stdlib.h>

void manejar_error_sintactico(t_sintactic_error errorSint, int n_line, int n_column){
    switch (errorSint)
    {
    case NO_START:
        printf("\033[0;31m" "Error Sintactico en %d:%d, esperaba una etiqueta de inicio.\n" "\033[0m", n_line, n_column);
        break;
    case ATRIBUTO_INVALIDO:
        printf("\033[0;31m" "Error Sintactico en %d:%d, atributo invalido para esta figura.\n" "\033[0m", n_line, n_column);
        break;
    case NO_FIGURA:
        printf("\033[0;31m" "Error Sintactico en %d:%d, se esperaba una figura.\n" "\033[0m", n_line, n_column);
        break;
    case NO_NUMBER:
        printf("\033[0;31m" "Error Sintactico en %d:%d, esperaba un numero.\n" "\033[0m", n_line, n_column);
        break;
    case NO_COLOUR:
        printf("\033[0;31m" "Error Sintactico en %d:%d, esperaba un color.\n" "\033[0m", n_line, n_column);
        break;
    case NO_END_FIGURA:
        printf("\033[0;31m" "Error Sintactico en %d:%d, se esperaba el fin de una figura.\n" "\033[0m", n_line, n_column);
        break;
    case NO_END:
        printf("\033[0;31m" "Error Sintactico en %d:%d, esperaba una etiqueta de fin.\n" "\033[0m", n_line, n_column);
        break;
    case POST_END:
        printf("\033[0;31m" "Error Sintactico en %d:%d, no se permite agregar elementos despues de una etiqueta de fin.\n" "\033[0m", n_line, n_column);
        break;
    }
    exit(EXIT_SUCCESS);
}

void manejar_error_lexico(int n_line, int n_column){
    printf("\033[0;31m" "Error Lexico en %d:%d, lexema invalido.\n" "\033[0m", n_line, n_column);
    exit(EXIT_SUCCESS);
}

void manejar_error_semantico(t_semantic_error type, int n_line, int n_column){
    switch(type){
        case ATRIBUTO_REPETIDO:
        printf("\033[0;31m" "Error Semantico en %d:%d, no se permiten atributos repetidos.\n" "\033[0m", n_line, n_column);
        break;
    }
    exit(EXIT_SUCCESS);
}