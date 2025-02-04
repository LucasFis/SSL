#include<stdlib.h>
#include "list.h"
#include <stdbool.h>

struct t_list* new_list(){
    struct t_list* new_list = (struct t_list*) malloc(sizeof(struct t_list));
    if (new_list != NULL) {
        new_list->head = NULL;
        new_list->elements_count = 0;
    }
    return new_list;
}

void list_add_element(void* element, struct t_list* list){
    struct s_nodo* data = list -> head;
    bool head_is_null = true;
    int index=0;
    for(int i=0; i < list -> elements_count && data != NULL ; i++){
        head_is_null = false;
        data = data -> next;
        index++;
    }
    if(data!=NULL)
        return;

    data = (struct s_nodo*)malloc(sizeof(struct s_nodo));

    data -> content = element;
    data -> next = NULL;

    if(head_is_null)
        list -> head = data;
    else{
        struct s_nodo* aux = list ->head;
        for(int i = 0; i < index - 1; i++)
            aux = aux -> next;
        aux -> next = data;
    }
    list -> elements_count++;
}

void* list_get_element(struct t_list* list, unsigned short index){
    struct s_nodo* data = list -> head; 
    for(int i=0 ; i < index && data -> next != NULL; i++){
        data = data -> next;
    }
    return data -> content;
}

void* list_delete_element(struct t_list* list, void* element){
    struct s_nodo* fst_aux = list ->head;
    struct s_nodo* snd_aux = NULL;
    bool is_there = false;

    while(fst_aux -> next != NULL && !(is_there = fst_aux -> next -> content == element))
        fst_aux = fst_aux -> next;
    
    if(is_there){
        void* node_content = fst_aux -> next -> content;
        snd_aux = fst_aux -> next -> next;
        fst_aux -> next = snd_aux;
        list ->elements_count--;
        return node_content;
    }
    else return NULL;
}

void clear_list(struct t_list* lista, void how_to(void*)){
    struct s_nodo* data = lista -> head;
    struct s_nodo* next_data = data -> next;
    while(data != NULL){

        how_to(data -> content);

        free(data);

        data = next_data;
        if(next_data != NULL)
            next_data = next_data -> next;
    }
}