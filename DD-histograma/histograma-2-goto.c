#include<stdio.h>
#include<stdlib.h>
#include"histograma.h"

void histograma_2(t_data_set data){
    int ncp = 0;
    goto Out;
    In:
    switch(getchar()){
        case '\n':
        case ' ':
        case '\t':
            if(ncp>=15)
                ++data.array[15];
            else ++data.array[ncp-1];
            ncp = 0;
            goto Out;

        case EOF:
            if(ncp>=15)
                ++data.array[15];
            else ++data.array[ncp-1];
            goto End;

        default:
            ++ncp;
            goto In;
    }

    Out:
    switch(getchar()){
        case ' ':
        case '\n':
        case '\t':
            goto Out;
        case EOF:
            goto End;
        default:
            ++ncp;
            goto In;
    }

    End:    
        return;
}
