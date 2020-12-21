#include<stdio.h>
#include<string.h>
void upper_to_lower()
{
 char s[100];
     int i;
     gets(s);
     for(i=0;i<strlen(s);i++)
     {
          if( s[i]>=65 && s[i]<=90)
          {
               s[i]+=32;
          }
     }
     printf("after doing lower case\n");
     puts(s);

}
void lower_to_upper()
{
      char s[100];
     int i;
     gets(s);
     for(i=0;i<strlen(s);i++)
     {
          if( s[i]>=97 && s[i]<=122)
          {
               s[i]-=32;
          }
     }
     printf("after doing upper\n");
     puts(s);
}
int main()
{
    upper_to_lower() ;
    lower_to_upper();
}
