#include <stdio.h>
#include <stdlib.h>

struct node  // => struct node untuk menyimpan data dan pointer ke node berikutnya
{
    int data;
    struct node* next;
};

struct node* top = NULL;  // => pointer global untuk menyimpan pointer ke stack

struct node* new_node(int data)  // => untuk membuat node baru
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;

    return node;
};

void push(int data)  // => untuk menambahkan elemen ke dalam stack
{
    struct node* node = new_node(data);
    node->next = top;
    top = node;
}

void print_stack()
{
    if(top == NULL){
        printf("Stack is empty\n");

        return;
    }

    struct node* temp = top;

    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int pop()  // => untuk menghapus elemen ke dalam stack
{
    if(top == NULL){
        printf("Stack underflow\n");

        return -1;
    }

    struct node* temp = top;
    top = top->next;
    int popped = temp->data;
    free(temp);

    printf("Element to be deleted : %d\n", popped);
}

int peek()  // => untuk melihat elemen teratas dari stack
{
    if(top == NULL){
        printf("stack underflow\n");

        return -1;
    }

    printf("Element at the top of stack : %d\n", top->data);
}

int main()
{
    // Stack Linked List

    printf("Before Delete\n");

    push(10);
    push(20);
    push(30);

    print_stack();

    printf("\nAfter Delete\n");

    pop();

    print_stack();

    printf("\nTop of Stack\n");

    peek();

    print_stack();

    return 0;
}
