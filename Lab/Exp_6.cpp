using namespace std;
#include<iostream>
#include<string.h>
#include<ctype.h>
#include<math.h>
char postfix[50];
char stack_[50];
int top=-1;
int a=0;
int stack[50];
int l=0;
int top1=-1;
int preceed(char ch)
{
if (ch=='^')
return 3;
else if (ch=='*'||ch=='/')
return 2;
else if (ch=='+'||ch=='-')
return 1;
else
return 0;
}
void push(char n)
{
    top++;
    stack_[top]=n;
}
void insert_postfix(char s)
{
    postfix[a]=s;
    a++;
}
void pop()
{

    if(stack_[top]=='(')
    {

    }
    else
    insert_postfix(stack_[top]);
    top--;
}
void push1(int res)
{
 top1++;
 stack[top1]=res;
 // cout<<stack[top]<<" ";
}
int pop1()
{
 l=stack[top1];
 top1--;
  return l;
}
int main()
{
char infix[50];
int index;
cout<<"enter infix"<<endl;
cin>>infix;
index=strlen(infix);
infix[index]=')';
infix[index+1]='\0';
top = 0;
stack_[top]='(';
int i=0;
while (infix[i]!='\0')
{
    if(infix[i]=='(')
    {
        push(infix[i]);}
   else if (isalpha(infix[i])||isdigit(infix[i]))
   {

   insert_postfix(infix[i]);
   }
   else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='/'||infix[i]=='*'||infix[i]=='^')
   {
     if(preceed(infix[i])>preceed(stack_[top]))
     {

     push(infix[i]);
     }
     else if(preceed(infix[i])<=preceed(stack_[top]))
     {
         while(preceed(infix[i])<=preceed(stack_[top]))
         {
             pop();
         }
         push(infix[i]);
     }
   }
   else if(infix[i]==')')
   {
       while(stack_[top]!='(')
       {

           pop();
       }
       pop();
   }
   i++;
}
postfix[a]='\0';
cout<<"postfix expression:"<<postfix<<endl;
i=0;
int res;
while(postfix[i]!='\0')
   {
     if(isdigit(postfix[i]))
      {
        res=postfix[i]-48;
      }
     else
      {
         int a=pop1();
         int b=pop1();
           switch(postfix[i])
            {
              case '^':
               {
                   res=pow(b,a);
                   break;
               }
              case '*':
               {
                res=b*a;
                break; }
              case '/':
               {
                res=b/a;
                break;
               }
              case '+':
               {
                res=b+a;
                break;
               }
              case '-':
               {
                   res=b-a; break;
               }
            }
       }
      push1(res);
      i++;
   }
  cout<<"result: "<<stack[top1];

}
