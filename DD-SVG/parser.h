#ifndef __PARSER_H__
#define __PARSER_H__

#include <stdbool.h>

typedef enum {
    RECTANGULO,
    CIRCULO, 
    ELIPSE
} TipoFigura;
typedef struct {
    int int_pos_x;
    bool has_pos_x;
    int int_pos_y;
    bool has_pos_y;
    int int_width;
    bool has_width;
    int int_height;
    bool has_height;
    char str_fill[10];
    bool has_fill;
}t_prop_rect;

typedef struct {
    int int_pos_xc;
    bool has_pos_xc;
    int int_pos_yc;
    bool has_pos_yc;
    int int_rad;
    bool has_rad;
    char str_fill[10];
    bool has_fill;
}t_prop_circ;

typedef struct {
    int int_pos_xc;
    bool has_pos_xc;
    int int_pos_yc;
    bool has_pos_yc;
    int int_rad_x;
    bool has_rad_x;
    int int_rad_y;
    bool has_rad_y;
    char str_fill[10];
    bool has_fill;
}t_prop_elip;

union figura{
    t_prop_rect *prop_rect;
    t_prop_circ *prop_circ;
    t_prop_elip *prop_elip;
};

typedef struct{
    TipoFigura type;
    union figura* fig;
}t_prop;

void parsear();
void how_to_clear_content(void* contenido);

#endif 