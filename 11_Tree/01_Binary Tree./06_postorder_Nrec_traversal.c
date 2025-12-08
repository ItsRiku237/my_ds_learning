#include<stdio.h>
#include<stdlib.h>

/*Algorithm

Create two stacks: s1 and s2.

Push root to s1.

While s1 NOT empty:

Pop from s1 → call it node

Push node into s2

Push its left child (if exists) into s1

Push its right child (if exists) into s1

After loop → s2 contains nodes in reverse postorder
Pop all nodes from s2 and print.*/

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
    if(root == NULL)return;
    struct node* stack1[100];
    struct node* stack2[100];
    int top1 = -1;
    int top2 = -1;
    
    stack1[++top1] = root;
    while (top1 != -1)
    {
        struct node* temp = stack1[top1--]; 
        stack2[++top2] = temp;
        if(temp->left != NULL)stack1[++top1] = temp->left;
        if(temp->right != NULL)stack1[++top1] = temp->right;
    }
    while (top2 != -1)
    {
        printf("%d ",stack2[top2--] ->data);
    }
    
    
}

int main(){
    struct node* root = NULL;
    printf("Create a Binary Tree : \n");
    root = create_tree();

    printf("\nPostorder traversal : ");
    postorder_NonRecursive(root);
    return 0;
}
