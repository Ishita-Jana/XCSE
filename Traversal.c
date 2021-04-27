#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};


struct node* newNode(int data)
{
	struct node* Node
		= (struct node*)malloc(sizeof(struct node));
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}

/*  postorder traversal */
void Postorder(struct node* node)
{
	if (node == NULL)
		return;

	
	Postorder(node->left);	
	Postorder(node->right);
	printf("%d ", node->data);
}

/*  inorder traversal */
void Inorder(struct node* node)
{
	if (node == NULL)
		return;

	
	Inorder(node->left);
	printf("%d ", node->data);
	Inorder(node->right);
}

/*  preorder traversal */
void Preorder(struct node* node)
{
	if (node == NULL)
		return;

	
	printf("%d ", node->data);
	Preorder(node->left);
	Preorder(node->right);
}


int main()
{
	struct node* root = newNode(30);
	root->left = newNode(20);
	root->right = newNode(10);
	root->left->left = newNode(32);
	root->left->right = newNode(50);

	printf("\nPreorder traversal of binary tree is \n");
	Preorder(root);

	printf("\nInorder traversal of binary tree is \n");
	Inorder(root);

	printf("\nPostorder traversal of binary tree is \n");
	Postorder(root);

	getchar();
	return 0;
}

