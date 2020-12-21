#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
  int top;
  int size;
  char *s;
};

int isempty(struct stack *a)
{
     if(a->top== -1)
          return 1;
     else
          return 0;
}

int isfull(struct stack *a)
{
  if(a->top == a->size-1)
     return 1;
  else
     return 0;
}

void push(struct stack *a,char item)
{
   if(!isfull(a))
   {   a->top++;
        a->s[a->top]=item;
   }

}
void pop(struct stack *a)
 {
      char item;
      if(!isempty(a))
      {
        item=a->s[a->top];
        a->top--;
        //return(item) ;
      }
     // return(-1);
 }

 char* isbalanced(char *exp)
 {
      struct stack *a;
     a=(struct stack*) malloc(sizeof(struct stack));
     a->size=strlen(exp);
     a->top=-1;
     a->s=malloc(sizeof(char)*a->size);

   for(int i=0;i<strlen(exp);i++)
     {
         if(exp[i]=='[' || exp[i]=='{' || exp[i]=='(')
               {
                    push(a,exp[i]);
               }
          else
          {
              if(exp[i]==')')
                    {
                    if(isempty(a))
                         return "NO";
                    if(a->s[a->top]=='(')
                         pop(a);
                    else
                         return "NO";
                    }
               else if(exp[i]=='}')
                    {
                     if(isempty(a))
                         return "NO";
                    if(a->s[a->top]=='{')
                         pop(a);
                    else
                         return "NO";
                    }
               else if(exp[i]==']')
                    {
                    if(isempty(a))
                         return "NO";
                    if(a->s[a->top]=='[')
                         pop(a);
                    else
                         return "NO";
                    }
               }


     }
    return isempty(a)?"YES":"NO";
 }
int main()
{
     int q;
     scanf("%d",&q);
     while(q--)
     {
     char exp[100];
     printf("enter expression to check balanced or not\n");
     scanf("%s",exp);
     printf("%s\n",isbalanced(exp));
     }
}
