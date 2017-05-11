#include <stdio.h>
#include <stdlib.h>

typedef char data_t;

typedef struct node {
  data_t data;
  struct node *next;
} node;

#define CHECK_ALLOC(ptr)						\
    if (!ptr) {								\
        printf("Error allocating memory for %s in  %s: %d line", #ptr, __func__, __LINE__-1); \
        exit(2);								\
    }

void list_print(node* n){
    if (!n)
        printf("Empty list!\n");

    else {
        node* tmp = n;
        printf("[ ");
        while (tmp) {
            printf("%c ", tmp->data);
            tmp = tmp->next;
        }
        printf("]\n");
    }
}

node* list_create(data_t data){
    node* first = (node*)malloc(sizeof(node));
    CHECK_ALLOC(first);
    first->data = data;
    first->next = NULL;
    return first;
}


void list_free(node** head){
    node* current = *head;
    while (current != NULL) {
        node* tmp = current;
        current = current->next;
        free(tmp);
    }
    *head = NULL;
}

node* list_push(node** list, data_t new_elem){
    node* new_node = (node*)malloc(sizeof(node));
    CHECK_ALLOC(new_node);
    new_node->data = new_elem;
    new_node->next = *list;

    return new_node;
}

void list_append(node** list, data_t new_elem){
    node* new_node = (node*)malloc(sizeof(node));
    CHECK_ALLOC(new_node);
    new_node->data = new_elem;
    new_node->next = NULL;

    if (*list == NULL){
        *list = new_node;
    }

    else {
        node* current = *list;
        while (current->next)
            current = current->next;
        current->next = new_node;
    }
}

void list_reverse(node** list) {
    if (!*list)
        printf("Can't reverse a null list.\n\n") ;

    else if (!(*list)->next) {
        return;
    }

    else {
        node* prev_node = NULL;
        node* next_node;
        node* tmp = *list;

        while (tmp->next) {
            next_node = tmp->next;
	        tmp->next = prev_node;
    	    prev_node = tmp;
	        tmp = next_node;
        }

        tmp->next = prev_node;
        *list = tmp;
    }
}

node* find_next_pos(node** list, char new_elem) {
    node* iter = *list;

    if (iter == NULL || iter->data >= new_elem)
        return iter;

    while (iter->next && iter->next->data < new_elem) {
        iter = iter->next;
    }

    return iter;
}

void list_insert(node** list, data_t new_elem) {
    node* new_node = (node*)malloc(sizeof(node));
    CHECK_ALLOC(new_node);

    node* found = find_next_pos(list, new_elem);

    new_node->data = new_elem;

    if (found == NULL) {
        new_node->next = *list;
        *list = new_node;
    }

    else {
        new_node->next = found->next;
        found->next = new_node;
   }
}



int main() {
    node* head = list_create('a');
    head = list_push(&head, 'c');
    head = list_push(&head, 'v');
    head = list_push(&head, 'f');
    head = list_push(&head, 't');

    list_append(&head, 'h');
    list_append(&head, 'l');
    list_append(&head, 'o');
    list_append(&head, 'r');
    list_append(&head, 'w');

    list_print(head);

    list_reverse(&head);
    list_print(head);

    puts("And now the sorted list:");
    node* sorted = list_create('a');
    list_insert(&sorted, 'c');
    list_insert(&sorted, 'v');
    list_insert(&sorted, 'f');
    list_insert(&sorted, 't');
    list_insert(&sorted, 'h');
    list_insert(&sorted, 'l');
    list_insert(&sorted, 'o');
    list_insert(&sorted, 'r');
    list_append(&sorted, 'w');
    list_print(sorted);

    list_free(&head);
    list_free(&sorted);
    return 0;
}
