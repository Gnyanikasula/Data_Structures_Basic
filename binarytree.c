#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *insert(struct node *tree,int val)
{
    struct node *ptr,*parent,*nodeptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    if(tree == NULL)
    {
        tree = ptr;
    }
    else{
        parent = NULL;
        nodeptr = tree;
        while(nodeptr != NULL)
        {
          parent = nodeptr; 
          if(val < nodeptr->data)
            nodeptr = nodeptr->left;
          else
            nodeptr = nodeptr->right;    
        }
        if(val < parent->data)
            parent->left = ptr;
        else
            parent->right = ptr;    
    }
    return tree;


}
void preorderTraversal(struct node *tree)
{
    if(tree != NULL)
    {
        printf("%d\t", tree->data);
        preorderTraversal(tree->left);
        preorderTraversal(tree->right);
    }
}
void inorderTraversal(struct node *tree)
{
    if(tree != NULL)
    {
        inorderTraversal(tree->left);
        printf("%d\t", tree->data);
        inorderTraversal(tree->right);
    }
}
void postorderTraversal(struct node *tree)
{
    if(tree != NULL)
    {
        postorderTraversal(tree->left);
        postorderTraversal(tree->right);
        printf("%d\t",tree->data);
    }
}
int main()
{
    int value,option;
    struct node *tree = NULL;
    do{
        printf("Enter 1. to insert element\n");
        printf("2. preoder\n");
        printf("3. inorder\n");
        printf("4. postorder\n");
        printf("Enter your option:");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                printf("Enter the value to be entered:");
                scanf("%d",&value);
                insert(tree,value);
                break;
            case 2:
                preorderTraversal(tree);
                break;
            case 3:
                inorderTraversal(tree);
                break;
            case 4:
                postorderTraversal(tree);     
                break;          
        }
    

    }while(option!=5);
    return 0;
}