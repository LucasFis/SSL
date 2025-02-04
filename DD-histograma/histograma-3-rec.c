#include <stdio.h>
#include <stdlib.h>
#include "histograma.h"
int ncp, c;

void estado_out(int c, int array_ncp[]);
void estado_in(int c, int array_ncp[]);

void histograma_3(t_data_set data){
    ncp = 0;
    estado_out(c = getchar(), data.array);
}

void estado_out(int c, int array_ncp[]){

    switch(c){
    case '\n':
    case ' ':
    case '\t':
        estado_out(c = getchar(), array_ncp);
        break;
    case EOF:
        return;
    default:
        ++ncp;
        estado_in(c = getchar(), array_ncp);
    }
}

void estado_in(int c, int array_ncp[]){
    switch(c){
    case '\n':
    case ' ':
    case '\t':
        if(ncp >=15)
            ++array_ncp[15];
        else ++array_ncp[ncp-1];
        ncp = 0;
        estado_out(c = getchar(), array_ncp);
        break;
    case EOF:
        if(ncp >=15)
            ++array_ncp[14];
        else ++array_ncp[ncp-1];
        return;
    default:
        ++ncp;
        estado_in(c = getchar(), array_ncp);
    }
}