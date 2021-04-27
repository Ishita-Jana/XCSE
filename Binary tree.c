#include<stdio.h>
 
 struct node
{
	int data;
	struct node *left;
	struct node *right;
} node;
 
node *create()
{
	node *p;
	int x;
	printf("Enter data(-1 for no data):");
	scanf("%d",&x);
	
	if(x==-1)
		return NULL;
	
	p=(node*)malloc(sizeof(node));
	p->data=x;
	
	printf("Enter left child of %d:\n",x);
	p->left=create();
 
	printf("Enter right child of %d:\n",x);
	p->right=create();
	
	return p;
}


 //preorder traversal
 
void preorder(node *t)		//address of root node is passed in t
{
	if(t!=NULL)
	{
		printf("\n%d",t->data);		
		preorder(t->left);		
		preorder(t->right);		
	}
}
 
int main()
{	
	node *root;
	root=create();
	printf("\nThe preorder traversal of tree is:\n");
	preorder(root);
	
	return 0;
}
