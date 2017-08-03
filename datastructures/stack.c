#include<stdio.h>
#include<stdlib.h>

int stack[10],top=0,max,item,ch,i;

void display()
{
              printf("The elements in the stack are: ");
              if(top==0)
                        printf("Empty Stack");
              for(i=1;i<=top;i++)
                        printf("%d ",stack[i]);
}
void push()
{
       if(top==max)
           printf("Overflow\n");
      else
      {
               top++;
               printf("Enter the element\n");
               scanf("%d",&item);
               stack[top]=item;
      }
      display();
}
void pop()
{
        if(top==0)
               printf("Underflow\n");
        else
        {
             item=stack[top];
             top--;
             printf("The deleted element is %d\n",item);
        }
        display();
}

void check_is_empty()
{
     if(top==0)
               printf("The stack is empty\n");
     else
               printf("The stack is not empty\n");
}
void Check_is_full()
{
        if(top==max)
             printf("The stack is full\n");
        else
             printf("The stack is not full\n");
}
void peep()
{
    if(top!=0)
    {
          item=stack[top];
          printf("The top element is %d\n",item);
    }
    else
          printf("No elements found in the stack\n");
}


int main()
{
        printf("\nEnter the maximum no: ");
        scanf("%d",&max);
        while(1)
        {
                printf("\n\n\tMenu\n1-Push\n2-Pop\n3-Display\n4-Check is empty\n5-Check is full\n6-Peep\n7-Exit\n");
                printf("Enter your choice\n");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1:push();              break;
                        case 2:pop();               break;
                        case 3:display();           break;
                        case 4:check_is_empty();    break;
                        case 5:Check_is_full();     break;
                        case 7:exit(1);
                        case 6:peep();              break;
                        default:printf("Invalid entry\n");
                }
        }
}
