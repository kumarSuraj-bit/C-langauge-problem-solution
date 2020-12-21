#include<stdio.h>
#include<string.h>
int main()
{
     //char s[]="tenet";
     char s[100];
     gets(s);
     int i,j,x=0;
     for(i=0,j=strlen(s)-1;i<strlen(s)/2;i++,j--)
     {
          if(s[i]!=s[j])
               x=1;
     }
     if(x==1)
          printf("not palindrom");
     else
          printf("palindrom");
}
