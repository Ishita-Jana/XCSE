#include<stdio.h>
#include<stdlib.h>


struct node
{
int data;
struct node *left, *right;
}*root;

 
struct node *newNode(int item)
{
struct node *temp = (struct node *)malloc(sizeof(struct node));
temp->data = item;
temp->left = temp->right = NULL;
return temp;
}

/* Function to find the minimum value node */
struct node * minValueNode(struct node* node)
{
struct node* current = node;
/* loop down to find the leftmost leaf */
while (current->left != NULL)
current = current->left;
return current;
}

/* Function to delete the given node */

struct node* delete_node(struct node* root, int data)
{
 if (root == NULL)
 return root;
 
 if (data < root->data)
 root->left = delete_node(root->left, data);
 
 else if (data > root->data)
 root->right = delete_node(root->right, data);
 
 else
 {
 // node with only one child or no child
 if (root->left == NULL)
 {
 struct node *temp = root->right;
 free(root);
 return temp;
 }
 else if (root->right == NULL)
 {
 struct node *temp = root->left;
 free(root);
 return temp;
 }
 // node with two children:
 struct node* temp = minValueNode(root->right);
 // Copy the inorder successor's content to this node
 root->data = temp->data;
 // Delete the inorder successor
 root->right = delete_node(root->right, temp->data);
 }
 return root;
}

// Function to do inorder traversal of BST

void inorder(struct node *root)
{
 if (root != NULL)
 {
 inorder(root->left); 
 printf("%d ", root->data);
 inorder(root->right);
 }
}

/* Function to insert a new node with given key in BST */
struct node* insert(struct node* node, int data)
{

if (node == NULL)
return newNode(data);

if (data < node->data)
node->left = insert(node->left, data);

else if (data > node->data)
node->right = insert(node->right, data);

return node;
}


int main()
{
int n;
root = NULL;
printf("\nEnter the number of nodes : ");
scanf("%d", &n);
int i;
int data;
printf("\nInput the nodes of the binary search tree : ");
if(n > 0)
{
scanf("%d", &data);
root = insert(root, data);
}
for(i = 1; i < n; i++)
{
scanf("%d", &data);
insert(root, data);
}
printf("\nInorder traversal of the BST : ");
inorder(root);
printf("\n");
int del_ele;
printf("\nEnter the node to be deleted : ");
scanf("%d", &del_ele);
delete_node(root, del_ele);
printf("\nInorder traversal after deletion : ");
inorder(root);
printf("\n");
return 0;
}
