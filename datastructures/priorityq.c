#include<stdio.h>
#include<stdlib.h>

int pq[10][10],front[5],rear[5],max,i,n,m,item,ch;
void insert()
{
                printf("Enter the priority number of the item: ");
                scanf("%d",&n);
                if(n>max)
                {        printf("Invalid Priority");return;    }
                n--;
                if((front[n]==0&&rear[n]==max-1)||(front[n]==(rear[n]+1)))
                {
                         printf("Overflow\n");
                         return;
                }
                else if(rear[n]==-1&&front[n]==-1)
                     rear[n]=front[n]=0;
                else if(rear[n]==max-1)
                	      rear[n]=0;
                else rear[n]=rear[n]+1;
                m=rear[n];
                printf("Enter the element to be inserted\n");
                scanf("%d",&item);
                pq[n][m]=item;
}
void delete()
{
                int f=0;
                for(i=0;i<max;i++)
                       if(front[i]!=-1)
                       {    n=i;f=1;break;   }
                if(f==0)
                {
                         printf("Underflow");
                         return;
                }
                item=pq[n][front[n]];
		        if (front[n]==rear[n])
			         front[n]=rear[n]=-1;
                else if(front[n]==max-1)
                        front[n]=0;
                else front[n]=front[n]+1;
                printf("The deleted item is %d\n",item);
}
void display()
{
                printf("The elements in the priority queue are:\n");
                for(i=0;i<max;i++)
                {
                     if(front[i]==-1) printf("Empty Queue");
                     else if(front[i]<=rear[i])
 			              for(m=front[i];m<=rear[i];m++)
                                   printf("%d ",pq[i][m]);
                     else
                     {
                	 for(m=front[i];m<max;m++)
                		printf("%d ",pq[i][m]);
                	 for(n=0;n<=rear[i];n++)
                		printf("%d ",pq[i][n]);
                     }
                     printf("\n");
                }
}

int main()
{
	printf("\nEnter the maximum no:");
        scanf("%d",&max);

    for(i=0;i<max;i++)
    {  front[i]=rear[i]=-1;  }
while(1)
{
        printf("\n\n\tMenu\n1-Insert\n2-Delete\n3-Display\n4-Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:insert();
                break;
        case 2:delete();
                break;
        case 3:display();
                break;
        case 4:exit(1);
        default:printf("Invalid entry\n");
        }
}
}
