#ifndef __SEMANTIC_H__ 
#define __SEMANTIC_H_

typedef enum {
    POSICION_X,
    POSICION_Y, 
    POSICION_XC,
    POSICION_YC,
    ANCHO, 
    ALTURA,
    RADIO,
    RADIO_X,
    RADIO_Y,
    RELLENO_COLOR
} typeAtributo;

bool verificar_semantica_rectangulo(t_prop_rect* rect, typeAtributo atributo);
bool verificar_semantica_circulo(t_prop_circ* circ, typeAtributo atributo);
bool verificar_semantica_elipse(t_prop_elip* elip, typeAtributo atributo);

#endif