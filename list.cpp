#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    int data;
    struct node_t *next;
} node;

void add_node(struct node_t **head, const int data)
{
    struct node_t *new_one = (struct node_t *)malloc(sizeof(struct node_t));
    new_one->data = data;
    new_one->next = NULL;

    if (*head == NULL) {
        *head = new_one;
    } else {
        struct node_t *tmp = *head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new_one;
    }
}

void rm_node(struct node_t **head, const int data)
{
    struct node_t *tmp = *head;
    do {
        // if data is at first node
        if (tmp != NULL && tmp->data == data) {
            *head = tmp->next;
            free(tmp);
            break;
        }
        // search it
        struct node_t *prev = NULL;
        while (tmp != NULL && tmp->data != data) {
            prev = tmp;
            tmp = tmp->next;
        }
        // not found
        if (tmp == NULL) {
            break;
        }
        // found it
        prev->next = tmp->next;
        free(tmp);
    } while (0);
}

void print_list(struct node_t *head)
{
    while (head != NULL) {
        fprintf(stderr, "%d ", head->data);
        head = head->next;
    }
    fprintf(stderr, "\n");
}

int main(int argc, char *argv[])
{
    struct node_t *head = NULL;
    add_node(&head, 7);
    add_node(&head, 2);
    add_node(&head, 4);
    add_node(&head, 9);
    print_list(head);
    rm_node(&head, 2);
    rm_node(&head, 9);
    print_list(head);
    return 0;
}
