#include<stdio.h>
#include<stdlib.h>

int cirq[15],front=0,rear=0,max,i,ch,item;

void display()
{
                printf("The elements in the circular queue are: ");
                if(front==0) printf("Empty Queue");
		        else if(front<=rear)
 			    for(i=front;i<=rear;i++)
                		printf("%d ",cirq[i]);
                else if(front!=0)
                {
                	for(i=front;i<=max;i++)
                		printf("%d ",cirq[i]);
                	for(i=1;i<=rear;i++)
                		printf("%d ",cirq[i]);
                }
}
void insert()
{
                if((front==1&&rear==max)||(front==(rear+1)))
                {   printf("Overflow\n");  return;   }
                else if(rear==0&&front==0)
                     rear=front=1;
                else if(rear==max)
                	      rear=1;
                else rear=rear+1;
                printf("Enter the element to be inserted\n");
                scanf("%d",&item);
                cirq[rear]=item;
                display();
}
void delete()
{
                item=cirq[front];
		        if(front==0)
                {  	printf("Underflow\n"); return;           }
                else if (front==rear)
			         front=rear=0;
                else if(front==max)
                        front=1;
                else front=front+1;
                printf("The deleted item is %d\n",item);
                display();
}


int main()
{
	printf("\nEnter the maximum no:");
        scanf("%d",&max);
while(1)
{
        printf("\n\n\tMenu\n1-Insert\n2-Delete\n3-Display\n4-Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:insert();          break;
        case 2:delete();          break;
        case 3:display();         break;
        case 4:exit(1);
        default:printf("Invalid entry\n");
        }
}
}
