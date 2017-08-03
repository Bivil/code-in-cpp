#include<stdio.h>
#include<stdlib.h>

int q[10],front=0,rear=0,m,item,i;
    void display()
   {
        printf("The elements in the queue are\n");
        if(front==0)  printf("Empty Queue");
        else
              for(i=front;i<=rear;i++)
                           printf("%d ",q[i]);
   }
   void insert()
   {
        if(rear==m)
               printf("Overflow\n");
        else
        {
               if(front==0) rear=front=1;
               else  rear++;
               printf("Enter the element to be inserted\n");
               scanf("%d",&item);
               q[rear]=item;
        }
        display();
   }
   void delete()
   {
         item=q[front];
         if(front==0)
         {      printf("Underflow\n");return;   }
         if(front==rear)      front=rear=0;
         else   front++;
         printf("The deleted item is %d\n",item);
         display();
   }


int main()
{
        int ch;
        printf("\nEnter the maximum no:");
        scanf("%d",&m);
        while(1)
        {
                printf("\n\tMenu\n1-insert\n2-delete\n3-display\n4-exit\n");
                printf("Enter your choice: ");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1:insert();        break;
                        case 2:delete();        break;
                        case 3:display();       break;
                        case 4:exit(1);
               			default:printf("invalid entry\n");
                }
        }
}
