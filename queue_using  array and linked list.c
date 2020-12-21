#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 20
/*Implementation of queue using Array and Linked List*/
struct Node
{
   int data;
   struct Node *next;
}*lead = NULL,*back = NULL;
/*For linked list  */
void insert(int);
void delete();
void show();
/*For Array */
void enQueue(int);
void deQueue();
void display();

int queue[SIZE], front = -1, rear = -1;

void main()
{
   int value, choice,option;
   printf("\nImplementation of Queue Datastructure\n 1. Using Array\n 2. Using Linked List\n\n Please Enter your option : ");
   scanf("%d",&option);

   while(1)
   {
      if(option==1)
          {
      printf("\n\n**** THROUGH ARRAY ****\n");
      printf("1. Insertion\n2. Deletion\n3. Display\n4. Exit");
      printf("\nEnter your choice: ");
      scanf("%d",&choice);
   switch(choice){
	 case 1: printf("Enter the value to be insert: ");
		 scanf("%d",&value);
		 enQueue(value);
		 break;
	 case 2: deQueue();
		 break;
	 case 3: display();
		 break;
	 case 4:  exit(0);
	 default: printf("\nWrong selection!!! Try again!!!");
      }
   }
      else if(option==2)
     {
      printf("\n***** THROUGH LINKED LIST *****\n");
      printf("1. Insert\n2. Delete\n3. Display\n4. Exit");
      printf("\nEnter your choice: ");
      scanf("%d",&choice);
   switch(choice)
      {
	 case 1: printf("Enter the value to be insert: ");
		 scanf("%d", &value);
		 insert(value);
		 break;
	 case 2: delete(); break;
	 case 3: show(); break;
      case 4: exit(0);
	   default: printf("\nWrong selection!!! Please try again!!!\n");
      }
   }

   else
   {
       printf("Please choose valid a option!!!");
   }

}
}
void enQueue(int value){
   if(rear == SIZE-1)
      printf("\nQueue is Full!!! Insertion is not possible!!!");
   else{
      if(front == -1)
	 front = 0;
      rear++;
      queue[rear] = value;
      printf("\nInsertion success!!!");
   }
}
void deQueue(){
  if(front == - 1 || front > rear)
      printf("\nQueue is Empty!!! Deletion is not possible!!!");
  if(front == rear)
	 front = rear = -1;
   else{
      printf("\nDeleted : %d", queue[front]);
      front++;}
}
void display(){
   if(rear == -1)
      printf("\nQueue is Empty!!!");
   else{
      int i;
      printf("\nQueue elements are:\n");
      for(i=front; i<=rear; i++)
	  printf("%d ",queue[i]);
   }
}

void insert(int value)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   newNode -> next = NULL;
   if(lead == NULL)
      lead = back = newNode;
   else{
      back -> next = newNode;
      back = newNode;
   }
   printf("\nInsertion is Success!!!\n");
}
void delete()
{
   if(lead == NULL)
      printf("\nQueue is Empty!!!\n");
   else{
      struct Node *temp = lead;
      lead = lead -> next;
      printf("\nDeleted element: %d\n", temp->data);
      free(temp);
   }
}
void show()
{
   if(lead == NULL)
      printf("\nQueue is Empty!!!\n");
   else{
      struct Node *temp = lead;
      while(temp->next != NULL){
	 printf("%d --> ",temp->data);
	 temp = temp -> next;
      }
      printf("%d --> NULL\n",temp->data);
   }
}
