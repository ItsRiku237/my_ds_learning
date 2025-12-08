#include<stdio.h>
#include<stdlib.h>

/*Algorithm

Create an empty stack.

Set current = root.

Repeat until current == NULL AND stack is empty:

If current != NULL
→ Push current into stack
→ Move current = current->left

Else
→ Pop node from stack → print it
→ Move current = popped_node->right*/

struct node{
    struct node* left;
    int data;
    struct node* right;
};

struct node* create_node(int value){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node* create_tree(){
    int value;
    printf("Enter the node value (-1 for no node) : ");
    scanf("%d",&value);
    if(value==-1)return NULL;

    struct node* root = create_node(value);
    printf("Enter left child of %d : \n",value);
    root->left = create_tree();
    printf("Enter right child of %d : \n",value);
    root->right = create_tree();
    return root;
}

void postorder_NonRecursive(struct node* root){
    struct node* stack[100];
    int top = -1;
    struct node* curr = root;
    while (curr != NULL || top != -1)
    {
        while (curr != NULL)
        {
            stack[++top] = curr;
            curr = curr->left;
        }

        curr = stack[top--];
        printf("%d ",curr->data);
        curr = curr->right;
    }
}

int main(){
    struct node* root = NULL;
    printf("Create a Binary Tree : \n");
    root = create_tree();
    printf("\npostorder Non recursive traversal : ");
    postorder_NonRecursive(root);
    return 0;
}