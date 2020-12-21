#include<stdio.h>
#include<stdlib.h>

struct node
{
     struct node *lchild;
     int data;
     struct node *rchild;
};

struct node *root=NULL;

struct queue
{
     int front;
     int rear;
     int size;
     struct node **Q;
};

struct queue q;

int isempty(struct queue q)
{
     return q.front==q.rear;
}

void create(struct queue *q,int size)
{
     q->size=size;
     q->front=q->rear=0;
     q->Q=(struct node **)malloc(q->size*sizeof(struct node*));
}
void enqueue(struct queue *q,struct node *r)
{
     if((q->rear+1)%q->size==q->front)
          printf("overflow !! queue become full\n");
     else
         {
          q->rear=(q->rear+1)%q->size;
          q->Q[q->rear]=r;
         }
}

struct node* dequeue(struct queue *q)
{
     struct node* x=NULL;
     if(q->front==q->rear)
     {
          printf("queue is empty");
     }
     else
          {
            q->front=(q->front+1)%q->size;
            x=q->Q[q->front];
          }
     return x;
}

void createtree()
{
     struct node *p,*t;
     int x;
     struct queue q;
     create(&q,100);
     printf("enter root value\n");
     scanf("%d",&x);

     root=(struct node*)malloc(sizeof(struct node*));
     root->data=x;
     root->lchild=root->rchild=NULL;
     enqueue(&q,root);

     while(!isempty(q))
     {
          p=dequeue(&q);

          printf("enter left child of %d :",p->data);
          int v;
          scanf("%d",&v);
          if(v!=-1)
          {
               t=(struct node*)malloc(sizeof(struct node*));
               t->data=v;
               t->lchild=t->rchild=NULL;
               p->lchild=t;
               enqueue(&q,t);
          }

          printf("enter right child of %d :",p->data);
          int u;
          scanf("%d",&u);
          if(u!=-1)
          {
               t=(struct node*)malloc(sizeof(struct node*));
               t->data=u;
               t->lchild=t->rchild=NULL;
               p->rchild=t;
               enqueue(&q,t);
          }

     }
}

void preorder(struct node *p)
{
     if(p)
     {
          printf("%d ",p->data);
          preorder(p->lchild);
          preorder(p->rchild);
     }

}
void inorder(struct node *p)
{
     if(p)
     {
          inorder(p->lchild);
          printf("%d ",p->data);

          inorder(p->rchild);
     }

}
void postorder(struct node *p)
{
     if(p)
     {

          postorder(p->lchild);
          postorder(p->rchild);
          printf("%d ",p->data);
     }
}
void level_order(struct node *root)
{
    struct queue q;
    create(&q,100);
    printf("%d ",root->data);
    enqueue(&q,root);

    while(isempty(q))
    {
         root=dequeue(&q);
         if(root->lchild)
         {
              printf("%d ",root->lchild->data);
              enqueue(&q,root->lchild);
         }

        if(root->rchild)
         {
              printf("%d ",root->rchild->data);
              enqueue(&q,root->rchild);
         }
    }
}

int main()
{
createtree();
printf("\npreorder traversal :");
preorder(root);
printf("\nInorder traversal :");
inorder(root);
printf("\npostorder traversal :");
postorder(root);
printf("\nLevel-torder traversal :");
level_order(root);

}
