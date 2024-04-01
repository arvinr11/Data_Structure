#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data{
    int value;

    struct data *left, *right, *parent;
}*root = NULL;

struct data *push(struct data *curr, int x, struct data *parent){
    if(curr == NULL){
        curr = (struct data *)malloc(sizeof(struct data));
        curr->value = x;
        curr->parent = parent;
        curr->left = curr->right = NULL;
    }else{
        if(curr->value > x) curr->left = push(curr->left, x, curr);
        else if(curr->value < x) curr->right = push(curr->right, x, curr);
    }

    return curr;
}

 struct data *pop(struct data *curr, int y){
     if(curr == NULL) return NULL;
     else if(y < curr->value) curr->left = pop(curr->left, y);
     else if(y > curr->value) curr->right = pop(curr->right, y);
     else{
         //leaf
         //one child
         if(curr->left == NULL || curr->right == NULL){
             struct data *temp = NULL;

             if(curr->left != NULL) temp = curr->left;
             else if(curr->right != NULL) temp = curr->right;

             //leaf
             if(temp == NULL){
                 temp = curr;
                 curr = NULL;
                 free(temp);
             }
             //one child
             else{
                 temp->parent = curr->parent;
                 *curr = *temp;
                 free(temp);
             }

         }
         //two child
         else if(curr->left != NULL && curr->right != NULL){
             //yang menggantikan adalah predecessor
             struct data *temp = curr->left;
             while(temp->right != NULL) temp = temp->right;

             //copy semua data dari temp ke curr
             curr->value = temp->value;

             //hapus yang predecessor
             curr->left = pop(curr->left, temp->value);
         }
     }
     return curr;
 }

void preOrder(struct data *curr){
    if(curr == NULL) return;
    else{
        printf("%d --> ", curr->value);
        if(curr->left != NULL) preOrder(curr->left);
        if(curr->right != NULL) preOrder(curr->right);
    }
}

void inOrder(struct data *curr){
    if(curr == NULL) return;
    else{
        if(curr->left != NULL) inOrder(curr->left);
        printf("%d --> ", curr->value);
        if(curr->right != NULL) inOrder(curr->right);
    }
}

void postOrder(struct data *curr){
    if(curr == NULL) return;
    else{
        if(curr->left != NULL) postOrder(curr->left);
        if(curr->right != NULL) postOrder(curr->right);
        printf("%d --> ", curr->value);
    }
}

struct data *popAll(struct data *curr){
    if(curr == NULL) return NULL;
    else{
        curr->left = popAll(curr->left);
        curr->right = popAll(curr->right);
        free(curr);
    }
    return NULL;
}

struct data *search(struct data *curr, int z){
    if(curr == NULL) printf("Tidak ada");
    else if(curr->value > z) return search(curr->left, z);
    else if(curr->value < z) return search(curr->right, z);
    return curr;
}

int main(){
    int choice;
    do{
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                int x;
                scanf("%d", &x);
                root = push(root, x, NULL);
                break;
            }
            case 2:{
                int y;
                scanf("%d", &y);
                root = pop(root, y);
                break;
            }
            case 3:
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
            case 4:{
                int z;
                scanf("%d", &z);
                struct data *temp = search(root, z);

                if(temp != NULL){
                    printf("%d\n", temp->value);
                    if(temp->left != NULL) printf("Left child : %d\n", temp->left->value);
                    if(temp->right != NULL) printf("Right child : %d\n", temp->right->value);
                    if(temp->parent != NULL){
                        if(temp->parent->left == temp) printf("Left child of : %d\n", temp->parent->value);
                        else if(temp->parent->right == temp) printf("Right child of : %d\n", temp->parent->value);
                    }
                }
                break;
            }
            case 5:
                break;
        }
    }while(choice != 5);

    popAll(root);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int data;
	struct node *right_child;
	struct node *left_child;
};

struct node *create_node(int data){
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->left_child = NULL;
	new_node->right_child = NULL;

	return new_node;
}

struct node *insertion(struct node *root, int data){
	if(root == NULL){
		return create_node(data);
	}
	else if(data < root->data){
		root->left_child = insertion(root->left_child, data);
	} else {
		root->right_child = insertion(root->right_child, data);
	}
	return root;
}

//inorder traversal
void inorder_traversal(struct node *root){
	if(root != NULL){
		inorder_traversal(root->left_child);//traversing left child
		printf(" %d ", root->data);
		inorder_traversal(root->right_child);//traversing right child
	}
}

struct node *searching(struct node *root, int data){
	if (root == NULL || data == root->data){
		return root;
	}
	else if(data > root->data){
		//traversing right child
		return searching(root->right_child, data);
	}else{
		//traversing left child
		return searching(root->left_child, data);
	}
}

struct node *deletion(struct node *root, int data){
	//searching node to be deleted
	if (root == NULL){
		return NULL;
	}
	if(data < root->data){
		root->left_child = deletion(root->left_child, data);
	}
	else if (data > root->data){
		root->right_child = deletion(root->right_child, data);
	}else{
		//case 1, no child node
		if (root->left_child == NULL && root->right_child == NULL){
			free(root);
			return NULL;
		}
		// case 2, one child node
		else if (root->left_child == NULL || root->right_child == NULL){
			struct node *temp;
			if (root->left_child == NULL){
				temp = root->right_child;
			}
			else {
				temp = root->left_child;
			}
			free(root);
			return temp;
		}
	}
	return root;
}

int main(){
	struct node *root;

	root = create_node(20);
	insertion(root, 5);
	insertion(root, 30);
	insertion(root, 1);
	insertion(root, 15);
	insertion(root, 9);
	insertion(root, 7);
	insertion(root, 12);
	insertion(root, 25);
	insertion(root, 40);
	insertion(root, 45);
	insertion(root, 42);
//	printf("  %d    \n", root->data);
//	printf(" %d ", root->left_child->data);
//	printf(" %d ", root->right_child->data);

	inorder_traversal(root);
	printf("\n\n");

//	struct node *temp = NULL;
//	temp = searching(root, 42);
//	if(temp != NULL)
//	printf("%d", temp->data);
//	else
//	printf("not found");


//deletion
root = deletion(root, 1);
root = deletion(root, 45);
inorder_traversal(root);


	return 0;
}
