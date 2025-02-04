#include <stdio.h>
#include <stdlib.h>
#include "histograma.h"

typedef enum {
    OUT, 
    IN
}t_state;

void histograma_1(t_data_set data){

    int c, ncp = 0;
    t_state state = OUT;

    while((c = getchar())){
        switch(state){
            case OUT:
                switch(c){
                case '\n':
                case ' ':
                case '\t':
                    break;
                case EOF:
                    return;
                default:
                    ++ncp;
                    state = IN;
            }
            break;

        default:
                switch(c){
                case ' ':
                case '\n':
                case '\t':
                    if(ncp >=15)
                        ++data.array[15];
                    else ++data.array[ncp-1];
                    ncp = 0;
                    state = OUT;
                    break;
                case EOF:// es para guardar la palabra que estaba leyendo antes del eof.
                    if(ncp >=15)
                        ++data.array[14];
                    else ++data.array[ncp-1];
                    return;
                default:
                    ++ncp;
            }
        }
    }
}