#include <stdbool.h>
#include "parser.h"
#include "semantic.h"


bool verificar_semantica_rectangulo(t_prop_rect* rect, typeAtributo atributo){
    switch(atributo){
        case POSICION_X:
            return rect -> has_pos_x;
            break;
        case POSICION_Y:
            return rect -> has_pos_y;
            break;
        case ANCHO:
            return rect -> has_width;
            break;
        case ALTURA:
            return rect -> has_height;
            break;
        case RELLENO_COLOR: 
            return rect -> has_fill;
            break;
    }
}

bool verificar_semantica_circulo(t_prop_circ* circ, typeAtributo atributo){
    switch(atributo){
        case POSICION_XC:
            return circ -> has_pos_xc;
            break;
        case POSICION_YC:
            return circ -> has_pos_yc;
            break;
        case RADIO:
            return circ -> has_rad;
            break;
        case RELLENO_COLOR: 
            return circ -> has_fill;
            break;
    }
}

bool verificar_semantica_elipse(t_prop_elip* elip, typeAtributo atributo){
    switch(atributo){
        case POSICION_XC:
            return elip -> has_pos_xc;
            break;
        case POSICION_YC:
            return elip -> has_pos_yc;
            break;
        case RADIO_X:
            return elip -> has_rad_x;
            break;
        case RADIO_Y:
            return elip -> has_rad_y;
            break;
        case RELLENO_COLOR: 
            return elip -> has_fill;
            break;
    }
}