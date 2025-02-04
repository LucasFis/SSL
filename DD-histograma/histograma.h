#ifndef _HISTOGRAMA_H_
#define _HISTOGRAMA_H_

struct data_set{
    int max_length;
    int* array;
};

typedef struct data_set t_data_set;

void histograma_1(t_data_set data);
void histograma_2(t_data_set data);
void histograma_3(t_data_set data);
void histograma_x(t_data_set data);

#endif