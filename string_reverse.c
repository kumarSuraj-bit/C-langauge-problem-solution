#include<stdio.h>
#include<string.h>
void main()
{
    char s[20],t;
    int i,p;
    printf("enter string\n");
    gets(s);
    for(i=0;s[i]!=0;i++);
    p=i;

    printf("after reversing string\n");
    for(i=0;i<p/2;i++)
    {
        t=s[i];
        s[i]=s[p-i-1];
        s[p-i-1]=t;
     }
    puts(s);
}
