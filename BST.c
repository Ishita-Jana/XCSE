#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int key;
    struct node *left, *right;
};
 

struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
//inorder traversal

void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}
 
/* insert function*/

struct node* insert(struct node* node, int key)
{
    
    if (node == NULL)
        return newNode(key);
 
    
    if (key < node->key)
        node->left = insert(node->left, key);
        
    else if (key > node->key)
        node->right = insert(node->right, key);
 
    
    return node;
}
 

int main()
{
	int n,i;
   
       
    printf("Enter the number of nodes");
    scanf("%d",&n);
    int arr[n];
    
    printf("Enter the values");
    
    scanf("%d",&arr[0]);
    struct node* root = NULL;
    root = insert(root, arr[0]);
    
    for(i=1;i<n;i++){
    	scanf("%d",&arr[i]);
    	insert(root,arr[i]);
	}
    
    
    printf("\nThe values in inorder traversal are:\n");
    
    inorder(root);
 
    return 0;
}
