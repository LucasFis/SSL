#include "scanner.h"
#include "parser.h"
#include "list.h"
#include "semantic.h"
#include "manejadorErrores.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

Token token;
struct t_list* representacion_intermedia;


bool match(TokenType tipo_a_verificar, TokenType tipo_confirmacion);
t_prop* parsearRectangulo();
t_prop* parsearCirculo();
t_prop* parsearElipse();
void agregar_atributo_rectangulo(TokenType tipo, t_prop* prop_rect);
void agregar_atributo_circulo(TokenType tipo, t_prop* prop_circ);
void agregar_atributo_elipse(TokenType tipo, t_prop* prop_elip);
bool condicion_de_fin(TokenType type);

void parsear(){
    representacion_intermedia = new_list();

    token = get_next_token();

    if(!match(token.type, TOKEN_START))
        manejar_error_sintactico(NO_START,get_number_line(),get_number_column());

    token = get_next_token();
    
    while(!match(token.type,TOKEN_END) && !match(token.type,TOKEN_EOF)){

        switch (token.type){
            case TOKEN_RECTANGLE:

                list_add_element(parsearRectangulo(),representacion_intermedia);

                break; 
            case TOKEN_CIRCLE:

                list_add_element(parsearCirculo(),representacion_intermedia);

                break;
            case TOKEN_ELLIPSE:

                list_add_element(parsearElipse(),representacion_intermedia);
                
                break; 
            default:
                manejar_error_sintactico(NO_FIGURA,get_number_line(),get_number_column());
                return;
        }

        token = get_next_token();
    }
    
    if(!match(token.type,TOKEN_END))
        manejar_error_sintactico(NO_END,get_number_line(),get_number_column());

    token = get_next_token(); //Comprueba que no se detecte ningun token despues del fin
    if(!match(token.type,TOKEN_EOF)){
            manejar_error_sintactico(POST_END,get_number_line(),get_number_column());
            token = get_next_token();
    }

    //TERMINA EL COMPILADOR
}

bool match(TokenType tipo_a_verificar, TokenType tipo_confirmacion){

    return tipo_a_verificar == tipo_confirmacion;
}

t_prop* parsearRectangulo(){
    token = get_next_token();

    t_prop* rect = malloc(sizeof(t_prop));
    rect -> fig = malloc(sizeof(union figura));
    rect -> fig -> prop_rect = calloc(1,sizeof(t_prop_rect));
    rect -> type = RECTANGULO;

    while(!match(token.type,TOKEN_END_FIGURE) && !condicion_de_fin(token.type)){

        if(match(token.type, TOKEN_X_POSITION) || match(token.type, TOKEN_Y_POSITION) || match(token.type, TOKEN_WIDTH) || match(token.type, TOKEN_HEIGHT) || match(token.type, TOKEN_FILL)){
            
            agregar_atributo_rectangulo(token.type, rect);

            token = get_next_token();
        }
        else manejar_error_sintactico(ATRIBUTO_INVALIDO,get_number_line(),get_number_column()); //Llamar manejador de error
    }
    if(!match(token.type, TOKEN_END_FIGURE))
        manejar_error_sintactico(NO_END_FIGURA, get_number_line(),get_number_column());

    //rellenarRectDefault(); o WarningDeAtributos();
    return rect;
}

t_prop* parsearCirculo(){
    token = get_next_token();

    t_prop* circ = malloc(sizeof(t_prop));
    circ -> fig = malloc(sizeof(union figura));
    circ -> fig -> prop_circ = calloc(1,sizeof(t_prop_circ));
    circ -> type = CIRCULO;

    while(!match(token.type,TOKEN_END_FIGURE) && !condicion_de_fin(token.type)){

        if(match(token.type, TOKEN_XCENTER_POSITION) || match(token.type, TOKEN_YCENTER_POSITION) || match(token.type, TOKEN_RADIUS) || match(token.type, TOKEN_FILL)){

            agregar_atributo_circulo(token.type, circ);

            token = get_next_token();
        }
        else manejar_error_sintactico(ATRIBUTO_INVALIDO,get_number_line(),get_number_column());
    }
    if(!match(token.type, TOKEN_END_FIGURE))
        manejar_error_sintactico(NO_END_FIGURA, get_number_line(),get_number_column());

    return circ;
}

t_prop* parsearElipse(){
    token = get_next_token();
    
    t_prop* elip = malloc(sizeof(t_prop));
    elip -> fig = malloc(sizeof(union figura));
    elip -> fig -> prop_elip = calloc(1,sizeof(t_prop_elip));
    elip -> type = ELIPSE;

    while(!match(token.type,TOKEN_END_FIGURE) && !condicion_de_fin(token.type)){

        if(match(token.type, TOKEN_XCENTER_POSITION) || match(token.type, TOKEN_YCENTER_POSITION) || match(token.type, TOKEN_X_RADIUS) || match(token.type, TOKEN_Y_RADIUS) || match(token.type, TOKEN_FILL)){

            agregar_atributo_elipse(token.type, elip);

            token = get_next_token();
        }
        else manejar_error_sintactico(ATRIBUTO_INVALIDO,get_number_line(),get_number_column()); //Llamar manejador de error
    }
    if(!match(token.type, TOKEN_END_FIGURE))
        manejar_error_sintactico(NO_END_FIGURA, get_number_line(),get_number_column());

    return elip;
}

void agregar_atributo_rectangulo(TokenType tipo, t_prop* prop){

    token = get_next_token();
    
    switch(tipo){
        case TOKEN_X_POSITION:

            if(!match(token.type, TOKEN_NUMBER))
                manejar_error_sintactico(NO_NUMBER,get_number_line(),get_number_column()); //Llamar manejador de errores
            
            else if(verificar_semantica_rectangulo(prop -> fig -> prop_rect, POSICION_X))//Pregunto si la propiedad se completo previamente
                manejar_error_semantico(ATRIBUTO_REPETIDO,get_number_line(),get_number_column());//Llamar manejador de errores
            else{
                prop -> fig -> prop_rect -> int_pos_x = atoi(token.val);
                prop -> fig -> prop_rect -> has_pos_x = true;
            }
            break;

        case TOKEN_Y_POSITION:

            if(!match(token.type, TOKEN_NUMBER))
                manejar_error_sintactico(NO_NUMBER,get_number_line(),get_number_column()); //Llamar manejador de errores
            
            else if(verificar_semantica_rectangulo(prop -> fig -> prop_rect, POSICION_Y))//Pregunto si la propiedad se completo previamente
                manejar_error_semantico(ATRIBUTO_REPETIDO,get_number_line(), get_number_column()); //Llamar manejador de errores
            else{
                prop -> fig -> prop_rect -> int_pos_y = atoi(token.val);
                prop -> fig -> prop_rect -> has_pos_y = true;
            }
            break;

        case TOKEN_HEIGHT:

            if(!match(token.type, TOKEN_NUMBER))
                manejar_error_sintactico(NO_NUMBER,get_number_line(),get_number_column()); //Llamar manejador de errores
            
            else if(verificar_semantica_rectangulo(prop -> fig -> prop_rect, ALTURA))//Pregunto si la propiedad se completo previamente
                manejar_error_semantico(ATRIBUTO_REPETIDO,get_number_line(),get_number_column()); //Llamar manejador de errores
            else{
                prop -> fig -> prop_rect -> int_height = atoi(token.val);
                prop -> fig -> prop_rect -> has_height = true;
            }
            break;

        case TOKEN_WIDTH:

            if(!match(token.type, TOKEN_NUMBER))
                manejar_error_sintactico(NO_NUMBER,get_number_line(),get_number_column()); //Llamar manejador de errores
            
            else if(verificar_semantica_rectangulo(prop -> fig -> prop_rect, ANCHO))//Pregunto si la propiedad se completo previamente
                manejar_error_semantico(ATRIBUTO_REPETIDO,get_number_line(),get_number_column()); //Llamar manejador de errores
            else
                prop -> fig -> prop_rect -> int_width = atoi(token.val);
                prop -> fig -> prop_rect -> has_width = true;
            break;

        case TOKEN_FILL:

            if(!match(token.type, TOKEN_COLOUR))
                manejar_error_sintactico(NO_COLOUR,get_number_line(),get_number_column()); //Llamar manejador de errores
            
            else if(verificar_semantica_rectangulo(prop -> fig -> prop_rect, RELLENO_COLOR))//Pregunto si la propiedad se completo previamente
                manejar_error_semantico(ATRIBUTO_REPETIDO,get_number_line(),get_number_column()); //Llamar manejador de errores

            else{
                strcpy(prop -> fig -> prop_rect -> str_fill, token.val);
                prop -> fig -> prop_rect -> has_fill = true;
            }
            break;
    }
}

void agregar_atributo_circulo(TokenType tipo, t_prop* prop){

    token = get_next_token();

    switch(tipo){
        case TOKEN_XCENTER_POSITION:

            if(!match(token.type, TOKEN_NUMBER))
                manejar_error_sintactico(NO_NUMBER,get_number_line(),get_number_column()); //Llamar manejador de errores
            
            else if(verificar_semantica_circulo(prop -> fig -> prop_circ, POSICION_XC))//Pregunto si la propiedad se completo previamente
                manejar_error_semantico(ATRIBUTO_REPETIDO,get_number_line(),get_number_column()); //Llamar manejador de errores

            else{
                prop -> fig -> prop_circ -> int_pos_xc = atoi(token.val);
                prop -> fig -> prop_circ -> has_pos_xc = true;
            }
            break;

        case TOKEN_YCENTER_POSITION:

            if(!match(token.type, TOKEN_NUMBER))
                manejar_error_sintactico(NO_NUMBER,get_number_line(),get_number_column()); //Llamar manejador de errores
            
            else if(verificar_semantica_circulo(prop -> fig -> prop_circ, POSICION_YC))//Pregunto si la propiedad se completo previamente
                manejar_error_semantico(ATRIBUTO_REPETIDO,get_number_line(),get_number_column()); //Llamar manejador de errores

            else{
                prop -> fig -> prop_circ -> int_pos_yc = atoi(token.val);
                prop -> fig -> prop_circ -> has_pos_yc = true;
            }
            break;

        case TOKEN_RADIUS:

            if(!match(token.type, TOKEN_NUMBER))
                manejar_error_sintactico(NO_NUMBER,get_number_line(),get_number_column()); //Llamar manejador de errores
            
            else if(verificar_semantica_circulo(prop -> fig -> prop_circ, RADIO))//Pregunto si la propiedad se completo previamente
                manejar_error_semantico(ATRIBUTO_REPETIDO,get_number_line(),get_number_column()); //Llamar manejador de errores

            else{
                prop -> fig -> prop_circ -> int_rad = atoi(token.val);
                prop -> fig -> prop_circ -> has_rad = true;
            }
            break;

        case TOKEN_FILL:

            if(!match(token.type, TOKEN_COLOUR))
                manejar_error_sintactico(NO_COLOUR, get_number_line(),get_number_column()); //Llamar manejador de errores
            
            else if(verificar_semantica_circulo(prop -> fig -> prop_circ, RELLENO_COLOR))//Pregunto si la propiedad se completo previamente
                manejar_error_semantico(ATRIBUTO_REPETIDO,get_number_line(),get_number_column()); //Llamar manejador de errores
                
            else
                strcpy(prop -> fig -> prop_circ -> str_fill, token.val);
                prop -> fig -> prop_circ -> has_fill = true;
            break;
    }
}

void agregar_atributo_elipse(TokenType tipo, t_prop* prop){

    token = get_next_token();

    switch(tipo){
        case TOKEN_XCENTER_POSITION:

            if(!match(token.type, TOKEN_NUMBER))
                manejar_error_sintactico(NO_NUMBER,get_number_line(),get_number_column()); //Llamar manejador de errores
            
            else if(verificar_semantica_elipse(prop -> fig -> prop_elip, POSICION_XC))//Pregunto si la propiedad se completo previamente
                manejar_error_semantico(ATRIBUTO_REPETIDO,get_number_line(),get_number_column()); //Llamar manejador de errores
            else{
                prop -> fig -> prop_elip -> int_pos_xc = atoi(token.val);
                prop -> fig -> prop_elip -> has_pos_xc = true;
            }
            break;

        case TOKEN_YCENTER_POSITION:

            if(!match(token.type, TOKEN_NUMBER))
                manejar_error_sintactico(NO_NUMBER,get_number_line(),get_number_column()); //Llamar manejador de errores
            
            else if(verificar_semantica_elipse(prop -> fig -> prop_elip, POSICION_YC))//Pregunto si la propiedad se completo previamente
                manejar_error_semantico(ATRIBUTO_REPETIDO,get_number_line(),get_number_column()); //Llamar manejador de errores
            else{
                prop -> fig -> prop_elip -> int_pos_yc = atoi(token.val);
                prop -> fig -> prop_elip -> has_pos_yc = true;
            }
            break;

        case TOKEN_X_RADIUS:

            if(!match(token.type, TOKEN_NUMBER))
                manejar_error_sintactico(NO_NUMBER,get_number_line(),get_number_column()); //Llamar manejador de errores
            
            else if(verificar_semantica_elipse(prop -> fig -> prop_elip, RADIO_X))//Pregunto si la propiedad se completo previamente
                manejar_error_semantico(ATRIBUTO_REPETIDO,get_number_line(),get_number_column()); //Llamar manejador de errores
            else{
                prop -> fig -> prop_elip -> int_rad_x = atoi(token.val);
                prop -> fig -> prop_elip -> has_rad_x = true;
            }
            break;

        case TOKEN_Y_RADIUS:

            if(!match(token.type, TOKEN_NUMBER))
                manejar_error_sintactico(NO_NUMBER, get_number_line(),get_number_column()); //Llamar manejador de errores
            
            else if(verificar_semantica_elipse(prop -> fig -> prop_elip, RADIO_Y))//Pregunto si la propiedad se completo previamente
                manejar_error_semantico(ATRIBUTO_REPETIDO,get_number_line(),get_number_column()); //Llamar manejador de errores
            else{
                prop -> fig -> prop_elip -> int_rad_y = atoi(token.val);
                prop -> fig -> prop_elip -> has_rad_y = true;
            }
            break;

        case TOKEN_FILL:

            if(!match(token.type, TOKEN_COLOUR))
                manejar_error_sintactico(NO_COLOUR, get_number_line(),get_number_column()); //Llamar manejador de errores
            
            else if(verificar_semantica_elipse(prop -> fig -> prop_elip, RELLENO_COLOR))//Pregunto si la propiedad se completo previamente
                manejar_error_semantico(ATRIBUTO_REPETIDO,get_number_line(),get_number_column()); //Llamar manejador de errores
            else{
                strcpy(prop -> fig -> prop_elip -> str_fill, token.val);
                prop -> fig -> prop_elip -> has_fill = true;
            }
            break;
    }
}

bool condicion_de_fin(TokenType type){
    return match(type, TOKEN_RECTANGLE) || match(type, TOKEN_CIRCLE) || match(type, TOKEN_ELLIPSE) 
        || match(type,TOKEN_START) || match(type,TOKEN_END) || match(type,TOKEN_EOF) 
        || match(type,TOKEN_ERROR) || match(type,TOKEN_STRING);
}

void how_to_clear_content(void* contenido){ //Le dice a list.c como debe limpiar el contenido de la lista en clear_list(lista,how_to);
    TipoFigura	tipo;

    tipo = ((t_prop*) contenido) -> type;

    switch(tipo){
        case RECTANGULO:
            free(((t_prop*)contenido) -> fig -> prop_rect);
            free(((t_prop*)contenido) -> fig);
            free(contenido);
            break;
        case ELIPSE:
            free(((t_prop*)contenido) -> fig -> prop_elip);
            free(((t_prop*)contenido) -> fig);
            free(contenido);
            break;
        case CIRCULO:
            free(((t_prop*)contenido) -> fig -> prop_circ);
            free(((t_prop*)contenido) -> fig);
            free(contenido);
            break;
    }
}