#include <stdio.h>
#include"Graficador.h"
#include "histograma.h"

static const int MAX_ALTO = 40;
static const int MAX_ANCHO = 120;

static void aplicar_array_vertical(t_data_set data, char grafico_vertical[MAX_ANCHO][MAX_ALTO]);
static void aplicar_array_horizontal(t_data_set data, char grafico_horizontal[MAX_ALTO][MAX_ANCHO]);


static void aplicar_array_horizontal(t_data_set data, char grafico_horizontal[MAX_ALTO][MAX_ANCHO]){

    int val1 = 1;

    for (int j = 0; j < data.max_length; j++) {
        for (int i = 1; i <= data.array[j]*3 && i < MAX_ANCHO; i++) {
            grafico_horizontal[val1][i] = 176;  // '░'
        }
        val1 += 1;
    }
}

static void aplicar_array_vertical(t_data_set data, char grafico_vertical[MAX_ANCHO][MAX_ALTO]){
    int val1 = 1, val2 = 2;
    for (int j = 0; j < data.max_length; j++) {
        for (int i = 1; i <= data.array[j] && i < MAX_ALTO; i++) {
            grafico_vertical[val1][i] = 176;
            grafico_vertical[val2][i] = 176;
        }
        val1 += 3;
        val2 += 3;
        if (val1 >= MAX_ANCHO || val2 >= MAX_ANCHO) break; 
    }
    
}

void graficar(t_data_set data,short horizontal){
    if(horizontal){

        char grafico_horizontal[data.max_length + 1][MAX_ANCHO];
        for(int i = 0; i < data.max_length + 1; i++) 
            grafico_horizontal[i][0] = 186; // '║'
    
        for (int j = 0; j < MAX_ANCHO; j++) 
            grafico_horizontal[0][j] = 205; // '═'
    
        grafico_horizontal[0][0] = 200; 

        for (int i = 1; i < data.max_length + 1; i++) {
            for (int j = 1; j < MAX_ANCHO; j++) {
                grafico_horizontal[i][j] = ' ';
            }
        }

        aplicar_array_horizontal(data,grafico_horizontal);
        
        for (int i = data.max_length; i >= 0; i--) {
            if(i<16)
                printf("\n%3.0d", i); 
            else if(i==16)
                printf("\n16+"); 
            
            
            for (int j = 0; j < MAX_ANCHO; j++) {
                printf("%c", grafico_horizontal[i][j]);
            }
        }

        printf("\n  0   1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39");

    }else{

        char grafico_vertical[ (data.max_length + 1)*3 ][MAX_ALTO];
        for(int i=0; i < (data.max_length + 1)*3 ; i++)    //INICIALIZA LOS BORDES INFERIORES DEL GRAFICO
            grafico_vertical[i][0] = 205;
            
        for (int j = 0; j < MAX_ALTO; j++)  //INICIALIZA LOS BORDES SUPERIORES DEL GRAFICO
            grafico_vertical[0][j] = 186;
        
        for (int i = 1; i < (data.max_length + 1)*3 ; i++)
            for(int j = 1; j < MAX_ALTO; j++)
                grafico_vertical[i][j] = ' ';

        grafico_vertical[0][0] = 200; //ESQUINA INFERIOR IZQUIERDA


        aplicar_array_vertical(data,grafico_vertical); //APLICA LOS VALORES DEL ARRAY (obvio)

        for(int j = MAX_ALTO - 1; j >= 0; j--){ //IMPRIME EL GRAFICO EN PANTALLA
            printf("\n%2.0d",j); //%2.0d son los numeros de la fila (indica el numero de palabras con esa cantidad de letras) 
            for(int i = 0; i < (data.max_length + 1)*3 ; i++)
                printf("%c",grafico_vertical[i][j]);
        }
        
        printf("\n0   1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16+"); //VALORES INFERIORES EN EL GRAFICO (indica los numeros de letras)
        }
}

void graficar_svg(t_data_set data, short eleccion){//eleccion = 1 vertical, sino horizontal
    FILE* svg_vertical;
    int width = 1100, height = 1100, x = 30, barHeight;
    int altura_inicial = 1000;
    const int unidad_escala = 40;
    int barWidth = 40;

    svg_vertical = fopen("histograma.svg", "w");

    fprintf(svg_vertical, "<svg width=\"%d\" height=\"%d\">\n", width, height);

    if(eleccion == 1){
        for(int i=0; i <= 1000/40; i++)
            fprintf(svg_vertical, "<text x=10 y=\"%d\" font-family=\"Arial\" font-size=12 text-anchor=\"middle\">%d</text>\n",altura_inicial - i*unidad_escala,i);
        
        
        fprintf(svg_vertical,"<rect x=\"20\" y=\"0\" width=\"5\" height=\"1000\" fill=\"black\"></rect>\n");
        for(int i = 0; i < data.max_length; i++){
            barHeight = data.array [i] * unidad_escala;
            fprintf(svg_vertical, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"black\" />\n", x, altura_inicial - barHeight, barWidth, barHeight);
            fprintf(svg_vertical, "<text x=\"%d\" y=\"%d\" font-family=\"Arial\" font-size=12 text-anchor=\"middle\">%d</text>\n", x + 10, altura_inicial+20, i + 1);
            x += 50;
        }
    }
    else{
        barHeight = 40;
        for(int i = 0; i <= 1000/40; i++)
            fprintf(svg_vertical, "<text x=\"%d\" y=1020 font-family=\"Arial\" font-size=12 text-anchor=\"middle\">%d</text>\n", unidad_escala + i * unidad_escala + 5, i);

        fprintf(svg_vertical,"<rect x=20 y=1000 width=1000 height=5 fill=\"black\"></rect>\n");

        for(int i = 0; i < data.max_length; i++){
            barWidth = data.array [i] * unidad_escala;
            fprintf(svg_vertical, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"black\" />\n",  50, altura_inicial - unidad_escala, barWidth, 30);
            fprintf(svg_vertical, "<text x=\"%d\" y=\"%d\" font-family=\"Arial\" font-size=12 text-anchor=\"middle\">%d</text>\n", x, altura_inicial - unidad_escala + 20, i + 1);
            altura_inicial = altura_inicial - unidad_escala - 10;
        }
    }
    fprintf(svg_vertical,"</svg>\n");
}