#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct data{
    int value;

    struct data *left, *right, *parent;
}*root = NULL;

struct data *push(struct data *curr, int x, struct data *parent){
    if(curr == NULL){
        curr = (struct data *)malloc(sizeof(struct data));
        curr->value = x;
        curr->left = curr->right = NULL;
        curr->parent = parent;
    }else{
        if(curr->value > x) curr->left = push(curr->left, x, curr);
        else if(curr->value < x) curr->right = push(curr->right, x, curr);
    }
    return curr;
}

struct data *search(struct data *curr, int x){
    if(curr == NULL) printf("Tidak ada\n");
    else if(curr->value > x) return search(curr->left, x);
    else if(curr->value < x) return search(curr->right, x);
    return curr;
}

struct data *pop(struct data *curr, int x){
    if(curr == NULL){
        return NULL;
    }else if(x < curr->value) curr->left = pop(curr->left, x);
    else if(x > curr->value) curr->right = pop(curr->right, x);
    else{
        if(curr->left == NULL && curr->right == NULL){
            free(curr);
            return NULL;
        }else if(curr->left != NULL && curr->right != NULL){
            struct data *temp = curr->left;
            while(temp->right != NULL){
                temp = temp->right;
            }
            curr->value = temp->value;
            curr->left = pop(curr->left, temp->value);
        }else{
            struct data *temp = NULL;
            if(curr->left != NULL){
                temp = curr->left;
                temp->parent = curr->parent;
                *curr = *temp;
                free(temp);
            }else{
                temp = curr->right;
                temp->parent = curr->parent;
                *curr = *temp;
                free(temp);
            }
        }
    }

    return curr;
}

void preOrder(struct data *curr){
    if(curr == NULL){

    }else{
        printf("%d --> ", curr->value);
        if(curr->left != NULL) preOrder(curr->left);
        if(curr->right != NULL) preOrder(curr->right);
    }
}

void inOrder(struct data *curr){
    if(curr == NULL){

    }else{
        if(curr->left != NULL) inOrder(curr->left);
        printf("%d --> ", curr->value);
        if(curr->right != NULL) inOrder(curr->right);
    }
}

void postOrder(struct data *curr){
    if(curr == NULL){

    }else{
        if(curr->left != NULL) postOrder(curr->left);
        if(curr->right != NULL) postOrder(curr->right);
        printf("%d --> ", curr->value);
    }
}

struct data *popAll(struct data *curr){
    if(curr != NULL){
        if(curr->left != NULL) popAll(curr->left);
        if(curr->right != NULL) popAll(curr->right);
        free(curr);
        return NULL;
    }else{
        return NULL;
    }
}

int main(){
    int choice, x;
    do{
        printf("1. Add data\n");
        printf("2. Search data\n");
        printf("3. Delete data\n");
        printf("4. Print\n");
        printf("5. Exit\n");
        printf("Choice = ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Value = ");
                scanf("%d", &x);

                root = push(root, x, NULL);
                break;
            case 2:
                printf("Value = ");
                scanf("%d", &x);

                struct data *temp = search(root, x);
                if(temp != NULL){
                    printf("Value = %d\n", temp->value);
                    if(temp->left != NULL) printf("Left child = %d\n", temp->left->value);
                    if(temp->right != NULL) printf("Right child = %d\n", temp->right->value);
                    if(temp->parent != NULL){
                        if(temp->parent->left == temp) printf("Left child of = %d\n", temp->parent->value);
                        if(temp->parent->right == temp) printf("Right child of = %d\n", temp->parent->value);
                    }
                }else{
                    printf("Tidak ada data\n");
                }
                break;
            case 3:
                printf("Value = ");
                scanf("%d", &x);

                root = pop(root, x);
                break;
            case 4:
                printf("preOrder = ");
                preOrder(root);
                printf("\n");
                printf("inOrder = ");
                inOrder(root);
                printf("\n");
                printf("postOrder = ");
                postOrder(root);
                printf("\n");
                break;
            case 5:
                break;
        }
    }while(choice != 5);
    root = popAll(root);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int tablesize = 10;
struct hashnode{
	char key[100];
	int value;
};

int convertstringtoint(char *key){
	int ascii = 0;
	int i;
	for (i = 0; i < strlen(key); i++){
		ascii += key[i];
	}
	return ascii;
}

int hashfunctiondivision(int keyint){
	return keyint % tablesize;
}

void insert(char *key, int value, struct hashnode *hashtable[]){
	struct hashnode *new_node = (struct hashnode*)malloc(sizeof(struct hashnode));
	strcpy(new_node->key, key);
	new_node->value = value;

	int keyint = convertstringtoint(key);
	int index = hashfunctiondivision(keyint);

	while(hashtable[index] != NULL){
		index++;
	}
	hashtable[index] = new_node;

}

void show(struct hashnode *hashtable[]){
	int i;
	for(i = 0; i < tablesize; i++){
		printf("[%d]", i);
		if (hashtable[i] != NULL){
			printf("key: %s, value: %d\n", hashtable[i]->key, hashtable[i]->value);
		}else{
			printf("NULL\n");
		}
	}
}

void retrieve(char *key, struct hashnode *hashtable[]){
	int keyint = convertstringtoint(key);
	int index = hashfunctiondivision(keyint);
	printf("%d ", index);

	if(hashtable[index] == NULL){
	printf("\n %s is not found", key);
	}else{
		while (hashtable[index] != NULL){
			if(strcmp(hashtable[index]->key, key) == 0){
				printf("%s is found. value is %d", hashtable[index]->key, hashtable[index]->value);
				break;
			}
			index++
		;}
	}
}

int main(){
	struct hashnode *hashtable[tablesize];
	int i;
	for(i = 0; i < tablesize; i++){
		hashtable[i] = NULL;
	}
	insert("Arif", 10, hashtable);
	insert("Budi", 11, hashtable);
	insert("Citra", 12, hashtable);
	insert("Dwi", 13, hashtable);
	insert("Fajar", 14, hashtable);
	insert("Eka", 15, hashtable);
	insert("Indah", 16, hashtable);
	insert("Kurniawan", 17, hashtable);
	show(hashtable);

	retrieve("Dwi", hashtable);
	return 0;
}

