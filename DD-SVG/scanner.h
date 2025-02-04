#ifndef __SCANNER_H__ 
#define __SCANNER_H__ 

typedef enum {
    TOKEN_RECTANGLE = 'R',
    TOKEN_CIRCLE = 'C',
    TOKEN_ELLIPSE = 'E',
    TOKEN_HEIGHT = 'h',
    TOKEN_WIDTH = 'w',
    TOKEN_X_POSITION = 'x',
    TOKEN_XCENTER_POSITION = 500,
    TOKEN_Y_POSITION = 'y',
    TOKEN_YCENTER_POSITION = 501,
    TOKEN_RADIUS = 'r',
    TOKEN_X_RADIUS = 502,
    TOKEN_Y_RADIUS = 503,
    TOKEN_FILL = 'f',
    TOKEN_COLOUR,
    TOKEN_END_FIGURE= ';',
    TOKEN_START = '{',
    TOKEN_END = '}',
    TOKEN_NUMBER,
    TOKEN_EOF,
    TOKEN_ERROR,
    TOKEN_STRING
} TokenType;

typedef struct{
    TokenType type;
    char val[100];
} Token;

Token get_next_token();
int get_number_line();
int get_number_column();

static unsigned int numero_de_linea = 1;
static unsigned int numero_de_columna = 1;
#endif