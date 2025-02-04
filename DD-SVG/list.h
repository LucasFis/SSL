#ifndef __LIST_H__
#define __LIST_H__


struct s_nodo{
    void* content;
    struct s_nodo* next;
};

struct t_list{
    struct s_nodo* head;
    int elements_count;
};

struct t_list* new_list(void);
void list_add_element(void* element, struct t_list* list);
void* list_get_element(struct t_list* list, unsigned short index);
void* list_delete_element(struct t_list* list,void* element);
void clear_list(struct t_list* lista, void how_to(void*));
#endif