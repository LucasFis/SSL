#include "scanner.h"
#include "manejadorErrores.h"
#include<stdio.h>
#include<string.h>

int is_letter(char c){
    return (c>='A' && c<='Z') || (c>='a' && c<='z');
}

int is_digit(char c){
    return (c>='0' && c<='9');
}

Token create_token(TokenType type, char *val){
    Token t;
    t.type = type;
    int len = strlen(val);
    if ( len > 99 ) len = 99;
    strncpy(t.val, val, len);
    t.val[len] = '\0';
    return t;
}

int get_number_line(){
    return numero_de_linea;
}

int get_number_column(){
    return numero_de_columna;
}

Token get_next_token(){
    int ncp = 0;
    char character;
    char string[100] = {0}, string_val[100] = {0};
    Token token;
    while ((character = getchar())!=EOF){

        if (character == '\n'){
            numero_de_columna = 0;
            numero_de_linea++;
            continue;
        }

        numero_de_columna++;

        if (character == ' ' || character == '\t') {
            continue;
        }
        
        if(character == '"') {

            do {
                character = getchar();
                numero_de_columna++;
            } while (character != EOF && character != '"');

            if  (character == EOF)
                return create_token(TOKEN_EOF, "");
            else continue;
        }

        if (is_digit(character)) {
            string_val[ncp++] = character;

            while (is_digit((character = getchar()))) {
                numero_de_columna++;
                string_val[ncp++] = character;
            }

            ungetc(character, stdin);
            string_val[ncp] = '\0';

            return create_token(TOKEN_NUMBER, string_val);
        }

        if (is_letter(character)) {
            string[ncp++] = character;
            string[ncp] = '\0';

            if (strcmp(string, "f") == 0)
                return  create_token(TOKEN_FILL, string);
            

            while (is_letter(character = getchar())){
                numero_de_columna++;
                string[ncp++] = character;
            }

            ungetc(character, stdin);
            string[ncp] = '\0';
            
            if (strcmp(string, "xc") == 0) 
                return create_token(TOKEN_XCENTER_POSITION, string);
            else if (strcmp(string, "yc") == 0)
                return create_token(TOKEN_YCENTER_POSITION, string);
            else if (strcmp(string, "rx") == 0)
                return create_token(TOKEN_X_RADIUS, string);
            else if (strcmp(string, "ry") == 0)
                return create_token(TOKEN_Y_RADIUS, string);
            else if (strcmp(string, "Yellow") == 0)
                return create_token(TOKEN_COLOUR, string);
            else if (strcmp(string, "Blue") == 0)
                return create_token(TOKEN_COLOUR, string);
            else if (strcmp(string, "Red") == 0)
                return create_token(TOKEN_COLOUR, string);
            else if (strcmp(string, "Green") == 0)
                return create_token(TOKEN_COLOUR, string);
        }

        if(strlen(string) > 1 )
            manejar_error_lexico(get_number_line(), get_number_column());
        /* Se hace esta consulta debido que todos los Strings posibles pasados como lexemas validos fueron comparado en el if else de arriba.
           Lo que significa que, si hay un string mayor que uno y no fue retornado anteriormente, entonces no existe token valido para ese lexema.
        */
        switch (string[0]) {
            case 'R': return create_token(TOKEN_RECTANGLE,"R");
            case 'C': return create_token(TOKEN_CIRCLE,"C");
            case 'E': return create_token(TOKEN_ELLIPSE,"E");
            case 'h': return create_token(TOKEN_HEIGHT,"h");
            case 'w': return create_token(TOKEN_WIDTH,"w");
            case 'x': return create_token(TOKEN_X_POSITION,"x"); 
            case 'y': return create_token(TOKEN_Y_POSITION,"y");
            case 'r': return create_token(TOKEN_RADIUS,"r");
        }

        switch (character){
            case ';': return create_token(TOKEN_END_FIGURE, ";");
            case '{': return create_token(TOKEN_START, "{");
            case '}': return create_token(TOKEN_END, "}");
            default: 
                string[0]= character;
                string[1] = '\0';
                manejar_error_lexico(get_number_line(), get_number_column());
        }
    }
    return create_token(TOKEN_EOF, "");
}