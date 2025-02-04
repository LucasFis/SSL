#ifndef __MANEJADORERRORES_H__
#define __MANEJADORERRORES_H__

typedef enum {
    NO_START,
    ATRIBUTO_INVALIDO,
    NO_FIGURA,
    NO_NUMBER,
    NO_COLOUR,
    NO_END_FIGURA,
    NO_END,
    POST_END
} t_sintactic_error;

typedef enum {
    ATRIBUTO_REPETIDO
} t_semantic_error;

void manejar_error_sintactico(t_sintactic_error errorSint, int n_line, int n_column);
void manejar_error_lexico(int n_line, int n_column);
void manejar_error_semantico(t_semantic_error type, int n_line, int n_column);

#endif 