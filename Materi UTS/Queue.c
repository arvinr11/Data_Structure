#include<stdio.h>
#include<stdlib.h>

struct data{
    int value;

    struct data *next, *prev;
}*head = NULL, *curr, *tail;

void push(int y){
    curr = (struct data *)malloc(sizeof(struct data));
    curr->value = y;
    curr->next = curr->prev = NULL;

    if(head == NULL){
        head = tail = curr;
    }else{
        tail->next = curr;
        curr->prev = tail;
        tail = curr;
    }

    tail->next = NULL;
}

void pop(int z){
    if(head->value == z){
        curr = head;
        head = head->next;
        free(curr);
        if(head != NULL) head->prev = NULL;
    }else if(tail->value == z){
        curr = tail;
        tail = tail->prev;
        free(curr);
        if(tail != NULL) tail->next = NULL;
    }else{
        curr = head;
        while(curr->value != z && curr != NULL){
            curr = curr->next;
        }

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        free(curr);
    }
}

void print(){
    curr = head;
    if(curr == NULL){
        return;
    }else{
        while(curr != NULL){
            printf("%d -> ", curr->value);
            curr = curr->next;
        }
    }
}

int main(){
    int x;
    do{
        scanf("%d", &x);

        switch(x){
            case 1:{
                int y;
                scanf("%d", &y);
                push(y);
                break;
            }

            case 2:{
                int z;
                scanf("%d", &z);
                pop(z);
                break;
            }

            case 3:
                print();
                break;

            case 4:
                break;
        }
    }while(x != 4);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct data {
	int priority;
	char name[100];
    struct data *next;
};

struct data *create_node(int priority, char name[100]){
	struct data *node = (struct data*)malloc(sizeof(struct data));
	node->next = NULL;
	node->priority = priority;
	strcpy(node->name, name);

	return node;
}

void print_queue(struct data *head){
	struct data *temp = head;
	while(temp != NULL){
		printf("%d: %s -> ", temp->priority, temp->name);
		temp = temp->next;
	}

}

struct data *push(struct data *head, int priority, char name[100]){
	struct data *node = create_node(priority, name);
	struct data *temp = head;

	while(temp->next->priority <= priority){
	temp = temp->next;
	if(temp->next == NULL)
	break;

	}
	node->next = temp->next;
	temp->next = node;
	return head;
}

struct data *pop(struct data *head){
	struct data *temp = head;
	head = head->next;
	free(temp);

	return head;
}


int main(){
	struct data *head = create_node(1,"alpha");

	struct data *new_node = create_node(2, "beta");
	head->next = new_node;

	struct data *new_node2 = create_node(3, "omega");
	new_node->next = new_node2;
	print_queue(head);

	head = push(head, 2, "delta");
	printf("\n");
	print_queue(head);


	head = pop(head);
	printf("\n");
	print_queue(head);
	return 0;
}


//tugas 1.stack implementation linked list
// 2.konversi infix ke prefix dan posfix
//3. single dan double linked list push mid dan pop middle/search

