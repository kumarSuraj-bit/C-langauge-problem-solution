#include<stdio.h>
void quick(int a[],int n,int beg,int end,int *locptr)
{
     int left,right,temp;
     left=beg;
     right=end;
     *locptr=beg;
 step2:
     while(a[*locptr]<=a[right] && locptr!=right)
     {
          right--;
     }
     if(locptr==right)
          return;
     if(a[locptr]>a[right])
     {
          temp=a[locptr];
          a[locptr]=a[right];
          a[right]=temp;
          locptr=right;
          *locptr=right;
     }
     goto step3;
    step3:
     while(a[left]<=a[locptr]&&left!=locptr)
          left++;
     if(locptr==left)
          return;
     if(a[left]>a[locptr])
     {
          temp=a[left];
          a[left]=a[locptr];
          a[locptr]=temp;
          *locptr=left;
     }
     goto step2;
}
void quick_sort(int a[],int n)
{
     int beg,end,loc,top=-1;
     int lower[10],uper[10];
     if(n>1)
     {
          top++;
          lower[top]=0;
          uper[top]=n-1;

     }

     while(top!=-1)
     {
          beg=lower[top];
          end=uper[top];
          top--;
          quick(a,n,beg,end,&loc);
          if(beg<loc-1)
          {
               top++;
               lower[top]=beg;
               uper[top]=loc-1;

          }
          if(loc+1<end)
          {
               top++;
               lower[top]=loc+1;
               uper[top]=end;
          }
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
    quick_sort(a,n);
     for(int i=0;i<n;i++)
          printf("%d ",a[i]);
}
