#include<stdio.h>
#include<stdlib.h>

int item,dq[15],left=0,right=0,max,item,i,ch,flag=0;

void display()
{
  printf("The elements in the dequeue are: ");
   if(left==0) printf("Empty DeQueue");
   else if(left<=right)
     for(i=left;i<=right;i++)
        printf("%d ",dq[i]);
   else if(left!=0)
   {
     for(i=left;i<=max;i++)
        printf("%d ",dq[i]);
     for(i=1;i<=right;i++)
        printf("%d ",dq[i]);
   }
}
void inr()
{
  if((left==1&&right==max)||(left==(right+1)))
  {   printf("Overflow\n");  return;         }
  if(right==0&&left==0)
  	right=left=1;
  else if(right==max)
    right=1;
  else right=right+1;
  printf("Enter the element to be inserted\n");
  scanf("%d",&item);
  dq[right]=item;
  display();
}
void inl()
{
  if((left==1&&right==max)||(left==(right+1)))
   {   printf("Overflow\n");  return;     }
   if(right==0&&left==0)
           right=left=1;
   else if(left==1)
   	left=max;
		else	left=left-1;
  printf("Enter the element to be inserted\n");
  scanf("%d",&item);
  dq[left]=item;
  display();
}
void dell()
{
  item=dq[left];
	if(left==0)
  	{ printf("Underflow\n");   return;   }
  else if (left==right)
    left=right=0;
  else if(left==max)
    left=1;
  else left=left+1;
  printf("The deleted item is %d\n",item);
  display();
}
void delr()
{
  item=dq[right];
  if(left==0)
  {  printf("Underflow\n");   return;   }
  else if (left==right)
    left=right=0;
  else if(right==1)
    right=max;
  else right=right-1;
  printf("The deleted item is %d\n",item);
  display();
}


int main()
{
  printf("\nEnter the maximum no:");
    scanf("%d",&max);
while(1)
{
        printf("\n\n\tMenu\n1-Input Restricted Queue\n2-Output Restricted Queue\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        if(ch==1)
        {
        while(1)
        {
		 flag=0;
                 printf("\n\n\tMenu\n1-Insert Right\n2-Delete Left\n3-Delete right\n4-Display\n5-Exit\n6-Return\n");
                 printf("Enter your choice: ");
                 scanf("%d",&ch);
                 switch(ch)
                  {
                  case 1:inr();             break;
                  case 2:dell();            break;
                  case 3:delr();            break;
                  case 4:display();         break;
                  case 5:exit(0);
                  case 6:flag=1;
	              default:printf("Invalid entry\n");
		          }
		if(flag==1)		       break;
        }
        }
        else if(ch==2)
        {
        while(1)
        {
		 flag=0;
                 printf("\n\n\tMenu\n1-Insert Right\n2-Insert Left\n3-Delete left\n4-Display\n5-Exit\n6-Return\n");
                 printf("Enter your choice: ");
                 scanf("%d",&ch);
                 switch(ch)
                 {
                  case 1:inr();        break;
                  case 2:inl();        break;
                  case 3:dell();       break;
                  case 4:display();    break;
                  case 5:exit(0);
		          case 6:flag=1;
                  default:printf("Invalid entry\n");
                  }
		if(flag==1)            	break;
        }
        }
        else   printf("Invalid Entry");
}
}
