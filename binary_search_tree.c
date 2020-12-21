#include<stdio.h>
#include<stdlib.h>

struct node
{
     int data;
     struct node *left;
     struct node *right;
}*root=NULL;

struct node* insert( struct node *root,int data )
{

	if(root == NULL)
          {

        struct node* p = (struct node*)malloc(sizeof(struct node));

        p->data = data;

        p->left = NULL;
        p->right = NULL;
        return node;

	    }
	else
          {

		struct node* cur;

		if(data < root->data)
          {
            cur = insert(root->left, data);
            root->left = cur;
		}
		else
		 {
            cur = insert(root->right, data);
            root->right = cur;
		}

		return root;
	}
}
int main()
{

     int data,t;
     scanf("%d",&t);
     while(t--)
     {
          scanf("%d",&data);
          insert(root,data);
     }
}
