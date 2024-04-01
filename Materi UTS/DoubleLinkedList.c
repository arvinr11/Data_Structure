#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data // => Struct untuk menyimpan usia dan pointer ke node sebelumnya dan sesudahnya dalam linked list
{
    int age;

    struct data *next;
    struct data *prev;
};

struct data *head = NULL; // => Pointer global untuk node pertama, tengah, dan terakhir dalam linked list
struct data *mid = NULL;
struct data *tail = NULL;

struct data *create_node(int age) // => untuk membuat node baru dengan usia yang diberikan
{
    struct data *new_node = (struct data*)malloc(sizeof(struct data));

    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->age = age;

    return new_node;
}

void print_linked_list(struct data *head) // => untuk mencetak semua nilai usia dalam linked list
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

void push_head(int age) // => untuk menambahkan node baru ke depan linked list
{
    struct data *new_node = create_node(age);

    new_node->next = head;
    head->prev = new_node;

    head = new_node;
}

void push_mid(int age) // => untuk menambahkan node baru pada posisi tengah linked list
{
   struct data *new_node = create_node(age);

    if(mid == NULL){
        mid = new_node;
        head = new_node;
        tail = new_node;
    } else{
        new_node->next = mid->next;
        new_node->prev = mid;

        if(mid->next != NULL){
            mid->next->prev = new_node;
        } else{
            tail = new_node;
        }

        mid->next = new_node;
        mid = new_node;
    }
}

void push_tail(int age) // => untuk menambahkan node baru ke ujung linked list
{
    struct data *new_node = create_node(age);

    new_node->prev = tail;
    tail->next = new_node;

    tail = new_node;
}

void pop_head() // => untuk menghapus node pertama dari linked list
{
    struct data *temp;
    temp = head;
    head = head->next;

    temp->next = NULL;
    head->prev = NULL;
    free(temp);
}

void pop_mid() // => untuk menghapus node tengah dari linked list
{
    if(mid == NULL){
        return;
    }

    struct data *temp = mid;

    if(mid->prev != NULL){
        mid->prev->next = mid->next;
    } else{
        head = mid->next;
    }

    if(mid->next != NULL){
        mid->next->prev = mid->prev;
    } else{
        tail = mid->prev;
    }

    mid = (head == NULL || head->next == NULL) ? NULL : head->next;

    free(temp);
}

void pop_tail() // => untuk menghapus node terakhir dari linked list
{
    struct data *temp;
    temp = tail;
    tail = tail->prev;

    temp->prev = NULL;
    tail->next = NULL;
    free(temp);
}

int main()
{
    head = create_node(2);
    mid = create_node(1);
    tail = create_node(3);

    head->next = tail;
    tail->prev = head;

    push_head(0);
    push_head(1);
    push_mid(5);
    push_tail(6);

    pop_head();
    pop_mid();
    pop_tail();

    print_linked_list(head);

    return 0;
}

