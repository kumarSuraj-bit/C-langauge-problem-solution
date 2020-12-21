
#include<stdio.h>
#include<stdlib.h>

struct queue
{
     int front;
     int rear;
     int capacity;
     int *array;
};

void enqueue(struct queue *q,int data)
{
     if((q->rear+1)%q->capacity==q->front)
          printf("overflow !! queue become full\n");
     else{
               q->rear=(q->rear+1)%q->capacity;
         // q->rear=(q->rear+1)%q->capacity;
          q->array[q->rear]=data;

     }
}
int dequeue(struct queue *q)
{
     int x=-1;
     if(q->front==q->rear)
     {
          printf("queue is empty");
     }
     else
          {
               q->front=(q->front+1)%q->capacity;
           // q->front=(q->front+1)%q->capacity;
            x=q->array[q->front];
     }
     return x;

}

void display(struct queue *q)
{
     int i=q->front+1;
     do
     {
          printf("%d ",q->array[i]);
          i=(i+1)%q->capacity;

     }while(i!=(q->rear+1)%q->capacity);
     printf("\n");
}

int main()
{
struct queue q;
printf("enter size of queue\n");
scanf("%d",&q.capacity);
q.array=(struct queue*)malloc(q.capacity*sizeof(int));
q.front=q.rear=0;
while(1)
{
      printf("1.for push data\n2.for pop data\n3.display\n4.exit\n");
     printf("enter choice\n");
     int ch;
     scanf("%d",&ch);
     switch(ch)
     {
     case 1:
          {int d;
          printf("enter data to be pushed\n");
          scanf("%d",&d);
          enqueue(&q,d);
          break;
          }
     case 2:
           printf(" %d is poped\n",dequeue(&q));
           break;
     case 3:
          display(&q);
          break;
     case 4:
          exit(0);
     default:
          printf("please ! enter valid choice\n");
     }
}
}
