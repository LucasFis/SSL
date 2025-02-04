#include <stdlib.h>
#include<stdio.h>
#include "histograma.h"

typedef enum {
    OUT,
    IN
} t_state;

typedef struct {
    t_state nextState;
    void (*funct) (int*, t_data_set data);
} transition;

void wordLength (int* length, t_data_set data)
{
    (*length)++;
    return;
}

int isDelimiter (char c)
{
    return (c == '\n' || c ==' ' || c == '\t');
}

void finalizeWord (int* length, t_data_set data)
{
    if (*length > 0 && *length < data.max_length)
    {
        data.array[*length -1]++;
    }
    *length = 0;
}

transition table [2][2] = { { {OUT, NULL}, {IN, wordLength} }, { {OUT, finalizeWord}, {IN, wordLength} } };

void histograma_x(t_data_set data){
    t_state state = OUT;
    int c, ncp = 0;

    while((c = getchar()) != EOF){
        int inputType = isDelimiter(c) ? 0 : 1;
        transition t = table[state][inputType];

        if (t.funct != NULL) {
            t.funct(&ncp, data);
        }
        state = t.nextState;
    }

    if(state == IN){
        finalizeWord(&ncp, data);
    }
}