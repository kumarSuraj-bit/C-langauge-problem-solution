#include<stdio.h>
void insertion_sort(int a[],int n)
{
     int i,j,temp;
     for(i=1;i<n;i++)
     {
          temp=a[i];
          for(j=i-1;j>=0 && temp<a[j];j--)
          {
               a[j+1]=a[j];
          }
          a[j+1]=temp;

     }
}
int main()
{
    int n;
    printf("enter size of array\n");
    scanf("%d",&n);
    int a[n];
    printf("enter elements in array :\n");
    for(int i=0;i<n;i++)
      scanf("%d",&a[i]);
    printf("after sorting elements are :\n");
    insertion_sort(a,n);
     for(int i=0;i<n;i++)
          printf("%d ",a[i]);
}

