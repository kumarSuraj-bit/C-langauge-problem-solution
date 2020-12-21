#include<stdio.h>
#include<string.h>
int main()
{
     char s[1000];
     int i,c=0;
     gets(s);


     if(strlen(s)<26)
          printf("not pangram");
     else
     {
          int freq[26]={0},sum=0;
          for(i=0;i<strlen(s);i++)
          {
               if(s[i]>=97 && s[i]<=122 )
               {
                    freq[(s[i]-97)]=1;
               }
               else if( s[i]>=65 && s[i]<=90)
               {
                    freq[(s[i]-65)]=1;
               }
          }
          for(i=0;i<26;i++)
               sum+=freq[i];

          if(sum-26==0)
               printf("pangram");
          else
               printf("not pangram");
     }
}
