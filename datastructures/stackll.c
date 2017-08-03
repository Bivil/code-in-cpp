#include<stdio.h>
#include<stdlib.h>

int num,ch,val;

struct node
{
        int data;
        struct node *next;
};
struct node *top=NULL,*ptr,*preptr;

void display()
{
        if(top==NULL) printf("Underflow");
        else
        {
                printf("The StacK is: ");
                ptr=top;
                printf("\n%d\n",ptr->data);
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
                        printf("%d\n",ptr->data);
                }
        }
}

void pop()
{
        if(top==NULL) printf("Underflow");
        else
        {
                ptr=top;
                top=top->next;
		printf("The deleted value is %d\n",ptr->data);
                free(ptr);
                display();
        }
}

void push()
{
        printf("Enter the Value for new Node: ");
        scanf("%d",&num);
        struct node *newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=num;
        newnode->next=top;
        top=newnode;
        display();
}

void peep()
{
	printf("The top Value is:%d",top->data);
}

int main()
{
	while(1)
	{
                printf("\n\n\tMenu\n1-Push\n2-Pop\n3-Display\n4-Exit\n");
                printf("Enter your choice: ");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1:push();
                               break;
                        case 2:pop();
                               break;
                        case 3:display();
                               break;
			case 4:exit(0);
			default:printf("Invalid Entry");
		}
	}
}
