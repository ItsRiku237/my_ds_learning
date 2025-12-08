#include<stdio.h>
#include<stdlib.h>

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

void postorder(struct node* root){
    if(root == NULL)return ;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main(){
    struct node* root = NULL;
    printf("Create a Binary Tree : \n");
    root = create_tree();

    printf("\nPostorder traversal : ");
    postorder(root);
    return 0;
}
