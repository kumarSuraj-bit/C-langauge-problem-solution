#include <stdio.h>
#include<stdlib.h>
struct Element
{
 int i;
 int j;
 int x;
};
struct Sparse
{
 int m;
 int n;
 int num;
 struct Element *ele;
};
void create(struct Sparse *s)
{
 int i;

 printf("Enter Dimensions :");
 scanf("%d%d",&s->m,&s->n);
 printf("Number of non-zero");
 scanf("%d",&s->num);

 s->ele=(struct Element *)malloc(s->num*sizeof(struct Element));
 printf("Enter position of row,column and non-zero Elements");
 for(i=0;i<s->num;i++)
   scanf("%d%d%d",&s->ele[i].i,&s->ele[i].j,&s->ele[i].x);

}
void display(struct Sparse s)
{
 int i,j,k=0;

 for(i=0;i<s.m;i++)
 {
     for(j=0;j<s.n;j++)
        {
           if(i==s.ele[k].i && j==s.ele[k].j)
                 printf("%d ",s.ele[k++].x);
           else
                 printf("0 ");
        }
 printf("\n");
 }
}

struct Sparse * add(struct Sparse *s1,struct Sparse *s2)
{
 struct Sparse *sum;
 int i,j,k;
 i=j=k=0;

 if(s1->n != s2->n && s1->m != s2->m)
 return NULL;
 sum=(struct Sparse *)malloc(sizeof(struct Sparse));
sum->ele=(struct Element *)malloc((s1->num+s2->num)*sizeof(struct Element));
 while(i<s1->num && j<s2->num)
 {
 if(s1->ele[i].i<s2->ele[j].i)
 sum->ele[k++]=s1->ele[i++];
 else if(s1->ele[i].i>s2->ele[j].i)
 sum->ele[k++]=s2->ele[j++];
 else
 {
   if(s1->ele[i].j<s2->ele[j].j)
        sum->ele[k++]=s1->ele[i++];
   else if(s1->ele[i].j>s2->ele[j].j)
        sum->ele[k++]=s2->ele[j++];
 else
 {
 sum->ele[k]=s1->ele[i];
 sum->ele[k++].x=s1->ele[i++].x+s2->ele[j++].x;
 }

 }
 }
 for(;i<s1->num;i++)
     sum->ele[k++]=s1->ele[i];
 for(;j<s2->num;j++)
     sum->ele[k++]=s2->ele[j];
 sum->m=s1->m;
 sum->n=s1->n;
 sum->num=k;


 return sum;
}

int main()
{

     printf("Enter\n1.To check whether the matrix is Sparse Matix or not\n2.Add to Sparse Matrix using 3-column representation(coordinate list)\n");
     printf("enter your choice\n");
     int ch;
     scanf("%d",&ch);
     int Total = 0;
     switch(ch)
     {
          case 1:
               {
               int i, j, rows, columns, a[10][10];

                 printf("\n Please Enter Number of Rows and Column :  ");
 	            scanf("%d %d", &i, &j);

 	            printf("\n Please Enter the Matrix Elements \n");
 	            for(rows = 0; rows < i; rows++)
  	              {
                    for(columns = 0;columns < j;columns++)
    	                     {
      		                scanf("%d", &a[rows][columns]);
                          }
  	              }

 	           for(rows = 0; rows < i; rows++)
  	            {
   		           for(columns = 0; columns < j; columns++)
    	                   {
    		                  if(a[rows][columns] == 0)
    		                        Total++;
                        }
  	            }
  	           if(Total > (rows * columns)/2)
  	               {
  		              printf("\n The Matrix that you entered is a Sparse Matrix ");
	               }
	           else
	               {
		             printf("\n The Matrix that you entered is Not a Sparse Matrix ");
                    }

	           break;
               }
          case 2:

          {
            struct Sparse s1,s2,*s3;
            printf("for 1st matrix\n");
            create(&s1);
            printf("for 2nd matrix\n");
             create(&s2);

            s3=add(&s1,&s2);

           printf("First Matrix\n");
              display(s1);
           printf("Second Matrix\n");
              display(s2);
           printf("Sum Matrix\n");
              display(*s3);

              break;
          }
          default:
               printf("enter valid choice");

     }
return 0;
}
