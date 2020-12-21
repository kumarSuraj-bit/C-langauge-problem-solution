#include<stdio.h>

 void selection(int a[],int n)
  {
    int k,i,j,loc,min;
     for(i=0;i<n-1;i++)
     {
        loc=i;
        min=a[i];
         for(j=i+1;j<n;j++)
            {
              if(a[j]<min)
               {
                    loc=j;
                    min=a[j];
               }
            }
          k=a[i];
          a[i]=a[loc];
          a[loc]=k;

     }

}

int main()
{
    int n;
    printf("enter size of array\n");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
          scanf("%d",&a[i]);
    printf("after sorting elements\n");
    selection(a,n);
     for(int i=0;i<n;i++)
          printf("%d ",a[i]);
}
