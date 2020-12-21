#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<string.h>
/*
void bubblesort(int a[],int n)
{
     for(int round=1;round<n;round++)
          for(int i=0;i<n-round;i++)
     {
          if(a[i]>a[i+1])
          {
               int temp;
               temp=a[i];
               a[i]=a[i+1];
               a[i+1]=temp;
          }
     }

}
*/
void bubblesort(int a[],int n)
{
     for(int round=0;round<n-1;round++)
     {
         int flag=0;
          for(int i=0;i<n-1-round;i++)
          {
          if(a[i]>a[i+1])
              {
              flag=1;
               int temp;
               temp=a[i];
               a[i]=a[i+1];
               a[i+1]=temp;
              }
          }
          if(flag==0)
          {
                printf("minimum no. of round to swap : %d\n",round);
               return;
          }
     }

}
int main()
{
     int n;
     printf("enter size of array to swap\n");
     scanf("%d",&n);
     int a[n];
     for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
     bubblesort(a,n);
     printf("after swaping no. are :\n");
     for(int i=0;i<n;i++)
        printf("%d ",a[i]);

        return 0;
}

