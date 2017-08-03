#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void eval();
void convert();
void push(char);
void pop();
int icp(char);
int isp();
int top,right,result;
char stack[50],e[50],expr[50],post[50];


int main()
{
int p;
while(1)
{
printf("\n\n\t1.Conversion\n\t2.Postfix evaluation\n\t3.Exit");
printf("\n\tEnter your choice: ");
scanf("%d",&p);
switch(p)
{
case 1:printf("\nINFIX TO POSTFIX CONVERSION:\n");
	 convert();
	 break;
case 2:printf("\nPOSTFIX EVALUATION:\n");
       printf("\nEnter the postfix expression:  ");
       scanf(" %[^\n]",expr);
       eval();
       break;
case 3:exit(0);
	break;
}
}
}

void convert()
{
int i,x,y;
top=0;right=0;
stack[top]='(';
printf("\nEnter the infix expression:  ");
scanf(" %[^\n]",e);
for(i=0;e[i]!='\0';i++);
e[i]='#';
e[i+1]='\0';
for(i=0;e[i]!='\0';i++)
{
switch(e[i])
{
case '(':push(e[i]);
        break;
case ')':while(stack[top]!='(')
	pop();
	top--;
	break;
case '#':
	while(stack[top]!='(')
        pop();
        top--;
	expr[right]='\0';
	break;
default:x=icp(e[i]);
	y=isp();
	if(x==5)
	{
	expr[right]=e[i];
	right++;
	}
	else if(x>y)
	push(e[i]);
	else
	{
	while(x<=y)
	{
	pop();
	y=isp();
	}
	push(e[i]);
	}
	break;
}
}
printf("postfix expression:\t");
for(i=0;expr[i]!='\0';i++)
printf("%c",expr[i]);
printf("\n");
eval();
}

void eval()
{
     int i,x,y;
     top=-1;right=0;
     for(i=0;expr[i]!='\0';i++);
     expr[i]='#';
     expr[i+1]='\0';
     for(i=0;expr[i]!='\0';i++)
     {
     switch(expr[i])
     {
                 case '+':
                          x=stack[top];
                          y=stack[top-1];
                          top=top-2;
                          result=y-48+x-48;
                          push(result+48);
                          break;
                 case '-':
                          x=stack[top];
                          y=stack[top-1];
                          top=top-2;
                          result=y-x;
                          push(result+48);
                          break;
                 case '*':
                          x=stack[top];
                          y=stack[top-1];
                          top=top-2;
                          result=(y-48)*(x-48);
                          push(result+48);
                          break;
                 case '/':
                          x=stack[top];
                          y=stack[top-1];
                          top=top-2;
                          result=(y-48)/(x-48);
                          push(result+48);
                          break;
                 case '^':
                          x=stack[top];
                          y=stack[top-1];
                          top=top-2;
                          result=pow(y-48,x-48);
                          push(result+48);
                          break;
                 case '#':
                          printf("\nThe result is : %d",stack[top]-48);
                          break;
                 default:
                         push(expr[i]);
                         break;

     }
     }
}


int icp(char x)
{
switch(x)
{
case '+':
case '-':return (1);
	break;
case '*':
case '/':return (2);
	break;
case '^':return (3);
	break;
case '(':return (4);
	break;
default:return (5);
	break;
}
}


int isp()
{
	switch(stack[top])
	{
	case '+':
	case '-':return (1);
	        break;
	case '*':
	case '/':return (2);
	        break;
	case '^':return (3);
	        break;
	case '(':return (0);
	        break;
	}
	return 0;
}


void push(char x)
{
int i;
top++;
stack[top]=x;
/* for(i=0;i<=top;i++)
printf("%c\t",stack[i]);
printf("\n"); */
}


void pop()
{
expr[right]=stack[top];
right++;
top--;
}
