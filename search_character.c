#include<stdio.h>
#include<string.h>
int main()
{
     char a[50],ch;
     int i,j=0;
     printf("enter a string\n");
     gets(a);
     printf("enter a character , which you want to find in given string\n");
     scanf("%c",&ch);
     for(i=0;i<strlen(a);i++)
     {
          if(a[i]==ch)
              {
                   printf("desired character is : %c ",a[i]);
                   j=1;
                   break;

              }

     }
     if(j==0)
          printf("character not exist in given string");
}
