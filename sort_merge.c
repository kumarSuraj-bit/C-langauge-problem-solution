#include<stdio.h>
void mergepass(int a[],int n,int l,int b[])
{
     int j,lb;
     int q,s,r;
     q=n/(2*l);
     s=2*l*q;
     r=n-s;

}
void merge_sort(int a[],int n)
{
int l=1,b[n];//size of sub array
while(l<n)
{
     mergepass(a,n,l,b);
     mergepass(b,n,2*l,a);
     l=4*l;
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
    merge_sort(a,n);
     for(int i=0;i<n;i++)
          printf("%d ",a[i]);
}
