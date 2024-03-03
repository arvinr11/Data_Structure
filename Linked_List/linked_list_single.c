#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data
{
    int age;

    struct data *next;
};

struct data *create_node(int age)
{
    struct data *new_node = (struct data*)malloc(sizeof(struct data));

    new_node->next = NULL;
    new_node->age = age;

    return new_node;
}

struct data *push_head(struct data *head, int age)
{
    struct data *new_node = create_node(age);

    new_node->next = head;
    head = new_node;

    return head;
}

struct data *push_mid(struct data *head, int age, int posisi)
{
    struct data *new_node = create_node(age);

    struct data *temp = head;
    int count = 1;

    while(temp != NULL && count < posisi - 1){
        temp = temp->next;
        count++;
    }

    new_node->next = temp->next;
    temp->next = new_node;

    return head;
}

struct data *push_tail(struct data *head, int age)
{
    struct data *new_node = create_node(age);
    struct data *temp;
    temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = new_node;

    return head;
}

struct data *pop_head(struct data *head)
{
    struct data *temp;
    temp = head;
    head = head->next;
    free(temp);

    return head;
}

struct data *pop_search(struct data *head, int age)
{
    struct data *temp = head;
    struct data *prev = NULL;

    while(temp != NULL && temp->age != age){
        prev = temp;
        temp = temp->next;
    }

    if(temp != NULL){
        if(prev == NULL){
            head = head->next;
        } else{
            prev->next = temp->next;
        }

        free(temp);
    } else{
        printf("Element dengan umur %d tidak diketemui\n", age);
    }

    return head;
}

struct data *pop_tail(struct data *head)
{
    struct data *temp;
    struct data *curr;
    temp = head;
    curr = head;

    while(curr->next != NULL){
        temp = curr;
        curr = curr->next;
    }

    temp->next = NULL;
    free(curr);

    return head;
}

void print_linked_list(struct data *head)
{
    struct data *temp;
    temp = head;
    int count = 1;

    while(temp != NULL){
        printf("Data ke-%d = %d\n", count, temp->age);
        temp = temp->next;
        count++;
    }
}

int main()
{
    struct data *head = NULL;

    head = create_node(10);

    head = push_head(head, 40);
    head = push_mid(head, 30, 2);
    head = push_tail(head, 20);

    head = pop_head(head);
    head = pop_search(head, 50);
    head = pop_tail(head);

    print_linked_list(head);

    return 0;
}
