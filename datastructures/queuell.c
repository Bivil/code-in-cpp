#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *next;
}*front=NULL,*rear=NULL,*ptr;

int num;
void display();
void insert()
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter the value to be inserted:\t");
        scanf("%d",&num);
        newnode->data=num;
        newnode->next=NULL;
        if(front==NULL&&rear==NULL)
        {
        front=newnode;
        rear=front;
        }
        else
        {
        rear->next=newnode;
        rear=newnode;
        }
	display();
}


void delete()
{
	if(front==NULL)
        {
        printf("\nUNDERFLOW\n");
        return;
        }
        else if(front==rear)
        {
        printf("Only one element in the stack");
        printf("\nThe deleted element is %d\n",front->data);
        front=NULL;
        rear=NULL;
        }
        else
        {
        printf("The deleted element is %d\n",front->data);
        front=front->next;
        }
	display();
}


void display()
{
	if(front==NULL)
        	printf("\nQUEUE EMPTY\n");
        else
        {
        printf("The elements in the queue are:\t");
        ptr=front;
        while(ptr!=NULL)
        {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
        }
        }
}

int main()
{
int op,num;
while(1)
{
printf("\n\n\t1.Insertion\n\t2.Deletion\n\t3.Display\n\t4.Exit\n");
printf("Enter your choice: ");
scanf("%d",&op);
switch(op)
{
	case 1:insert();break;
	case 2:delete();break;
	case 3:display();break;
	case 4: exit(0);break;
}
}
}
