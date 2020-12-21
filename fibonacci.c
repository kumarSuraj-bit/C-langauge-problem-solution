#include<stdio.h>
#include<conio.h>
int fibonacci(int n)
{
     if(n==0 || n==1)
          return n;
     else
          return fibonacci(n-1) + fibonacci(n-2);

}
int main()
{
     int n;
     printf("enter the  number upto  which you want to print fibonacci series \n");
     scanf("%d",&n);
     printf("fibonacci series : \n");
     for(int i=0;i<n;i++)
          printf("%d ",fibonacci(i));


}
