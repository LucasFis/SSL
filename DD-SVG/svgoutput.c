#include "parser.h"
#include "list.h"
#include "svgoutput.h"
#include <stdio.h>

extern struct t_list* representacion_intermedia;

void output_rectangulo(t_prop_rect* rectangulo);
void output_circulo(t_prop_circ* circulo);
void output_elipse(t_prop_elip* elipse);
void output_pos_x(int posicion_x);
void output_pos_y(int posicion_y);
void output_width(int width);
void output_height(int height);
void output_radio_y(int radio_y);
void output_radio_x(int radio_x);
void output_fin_de_linea();
void output_xc(int pos_xc);
void output_yc(int pos_yc);
void output_radio(int radio);
void output_fill(char* color);
void output_inicio();
void output_fin();


void output_svg(){

    output_inicio();

    struct s_nodo* data = representacion_intermedia -> head;

    for(; data != NULL; data = data -> next){
        
        switch( ((t_prop*) data -> content) -> type){
        case RECTANGULO:
            output_rectangulo(((t_prop*) data -> content) -> fig -> prop_rect );
            break;

        case CIRCULO:
            output_circulo(((t_prop*) data -> content) -> fig -> prop_circ);
            break;

        case ELIPSE:
            output_elipse(((t_prop*) data -> content) -> fig -> prop_elip);
            break;

        }
    }

    output_fin();
    clear_list(representacion_intermedia, &how_to_clear_content);
}

void output_rectangulo(t_prop_rect* rectangulo){
    printf("\t<rect ");

    if (rectangulo -> has_pos_x)
    {
        output_pos_x(rectangulo -> int_pos_x);
    }
    
    if(rectangulo -> has_pos_y){
        output_pos_y(rectangulo -> int_pos_y);
    }
    
    if(rectangulo -> has_width){
        output_width(rectangulo -> int_width);
    }

    if(rectangulo -> has_height){
        output_height(rectangulo -> int_height);
    }

    if(rectangulo -> has_fill){
        output_fill(rectangulo -> str_fill);
    }
    
    output_fin_de_linea();
}

void output_circulo(t_prop_circ* circulo){
    printf("\t<circle ");

    if (circulo -> has_pos_xc)
    {
        output_xc(circulo -> int_pos_xc);
    }
    
    if(circulo -> has_pos_yc){
        output_yc(circulo -> int_pos_yc);
    }
    
    if(circulo -> has_rad){
        output_radio(circulo -> int_rad);
    }

    if(circulo -> has_fill){
        output_fill(circulo -> str_fill);
    }

    output_fin_de_linea();
    
}

void output_elipse(t_prop_elip* elipse){
    printf("\t<ellipse ");

    if (elipse -> has_pos_xc)
    {
        output_xc(elipse -> int_pos_xc);
    }
    
    if(elipse -> has_pos_yc){
        output_yc(elipse -> int_pos_yc);
    }
    
    if(elipse -> has_rad_x){
        output_radio_x(elipse -> int_rad_x);
    }
    
    if(elipse -> has_rad_y){
        output_radio_y(elipse -> int_rad_y);
    }

    if(elipse -> has_fill){
        output_fill(elipse -> str_fill);
    }

    output_fin_de_linea();
}

void output_pos_x(int posicion_x){
    printf("x=\"%d\" ", posicion_x);
}

void output_pos_y(int posicion_y){
    printf("y=\"%d\" ", posicion_y);
}

void output_width(int width){
    printf("width=\"%d\" ", width);
}

void output_height(int height){
    printf("height=\"%d\" ", height);
}

void output_radio_y(int radio_y){
    printf("ry=\"%d\" ", radio_y);
}

void output_radio_x(int radio_x){
    printf("rx=\"%d\" ", radio_x);
}

void output_fin_de_linea(){
    printf("/>\n");
}

void output_xc(int pos_xc){
    printf("cx=\"%d\" ", pos_xc);
}

void output_yc(int pos_yc){
    printf("cy=\"%d\" ", pos_yc);
}

void output_radio(int radio){
    printf("r=\"%d\" ", radio);
}

void output_fill(char color[10]){
    printf("fill=\"%s\" ", color);
}

void output_inicio(){
    printf("<svg>\n");
}

void output_fin(){
    printf("</svg>\n");
}