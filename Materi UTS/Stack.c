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
    } else{
        tail->next = curr;
        curr->prev = tail;
        tail = curr;
    }

    tail->next = NULL;
}

void pop(){
    if(head == NULL){
        printf("KOSONG\n");
    }
    else if(head == tail){
        curr = head;
        head = tail = NULL;
        free(curr);
    }
    else{
        curr = tail;
        tail = tail->prev;
        free(curr);
        if(tail != NULL){
            tail ->next = NULL;
        }else{
            head = tail = NULL;
        }
    }
}

void print(){
    curr = head;
    while(curr != NULL){
        printf("%d -> ", curr->value);
        curr = curr->next;
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
                pop();
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

// Array

//#include<stdio.h>
//#define MAX 4
//
//int top = -1;
//int stack_array[MAX];
//
//void push(int data)
//{
//    if(top == MAX - 1){
//        printf("Stack is full\n\n");
//	return ;
//    }
//
//    top = top + 1;
//    stack_array[top] = data;
//}
//
//void print_stack()
//{
//	if(top == -1){
//        printf("Stack is empty\n");
//
//        return;
//	}
//
//	for(int i = top; i >= 0; i--){
//        printf("%d\n", stack_array[i]);
//	}
//}
//
//void pop()
//{
//    if(top == -1){
//        printf("Stack is empty\n");
//
//        return;
//	}
//
//    printf("Element to be deleted : %d\n", stack_array[top]);
//
//	top = top - 1;
//}
//
//void peek()
//{
//    if(top == -1){
//        printf("Stack is empty\n");
//
//        return;
//	}
//
//	printf("\nElement at the top of stack : %d\n", stack_array[top]);
//
//	top = top - 1;
//}
//
//int main()
//{
//    printf("Before Delete\n");
//
//	push(1);
//	push(2);
//	push(3);
//	push(4);
//	push(5); //failed, stack full
//
//	print_stack();
//
//    printf("\nAfter Delete\n");
//
//    pop();
//
//    print_stack();
//
//    peek();
//
//    print_stack();
//
//	return 0;
//}
//
