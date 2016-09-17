#include<stdio.h>
int num,ch,val,i;

struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL,*ptr,*preptr;

void display();
void create_ll()
{
	printf("Enter the Value for First Node: ");
	scanf("%d",&num);
	struct node *firstnode;
	firstnode=(struct node*)malloc(sizeof(struct node));
	firstnode->data=num;
	firstnode->next=NULL;
	start=firstnode;
	display();
}


void insertbeg()
{
	printf("Enter the Value for new Node: ");
        scanf("%d",&num);
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
        newnode->next=start;
	start=newnode;
	display();
}

void insertend()
{
    printf("Enter the Value for new Node: ");
    scanf("%d",&num);
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
	newnode->next=NULL;
	ptr=start;
	if(ptr==NULL)      start=newnode;
	else
	{
	    while(ptr->next!=NULL)
              ptr=ptr->next;
              ptr->next=newnode;
     }
     display();
}

void insertaft_n()
{
     int flag=0;
	printf("Enter  the number of nodes after which Insertion should take place: ");
	scanf("%d",&val);
	if(val==0)       insertbeg();
	else
	{
    ptr=start;
	for(i=1;i<=val;i++)
	{	preptr=ptr;ptr=ptr->next;
		if(preptr->next==NULL && i!=val)
		{
			printf("Total Number of Nodes is less. Try again with a lower value.\n");
			flag=1;break;
		}
	}
	if(flag==0)
	{
	printf("Enter the Value for new Node: ");
    scanf("%d",&num);
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
	newnode->next=ptr;
	preptr->next=newnode;
    }
	display();
    }
}

void insertbef_n()
{
     int flag=0;
    printf("Enter  the number of nodes before which Insertion should take place: ");
    scanf("%d",&val);
    ptr=start;i=0;
	while(ptr->next!=NULL)
	{
		i++;ptr=ptr->next;
	}
    val=i-val+1;
    if(val==0) {       insertbeg();return; }
    else if(val<0)
         printf("Total Number of Nodes is less. Try again with a lower value.");
    else
    {
	    ptr=start;
        for(i=1;i<=val;i++)
	    {       preptr=ptr;ptr=ptr->next;	}
    	printf("Enter the Value for new Node: ");
        scanf("%d",&num);
        struct node *newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=num;
     	newnode->next=ptr;
	    preptr->next=newnode;
     }
     display();
}

void insertbef()
{
	printf("Enter the value before which the newnode is to be inserted: ");
	scanf("%d",&val);
	ptr=start;
	while(ptr->data!=val && ptr->next!=NULL)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	if(ptr->data==val)
	{
              printf("Enter the Value for new Node: ");
              scanf("%d",&num);
              struct node *newnode;
              newnode=(struct node*)malloc(sizeof(struct node));
              newnode->data=num;
              newnode->next=ptr;
              if(ptr==start)
		              start=newnode;
              else
		             preptr->next=newnode;
    }
    else
        printf("No node with the given value.\n");
    display();
}

void insertaft()
{
	printf("Enter the value  after which the newnode is to be inserted: ");
    scanf("%d",&val);
	preptr=start;
	ptr=start->next;
	while(preptr->data!=val && preptr->next!=NULL)
	{
		preptr=ptr;
		ptr=ptr->next;
	}

	if(preptr->data==val)
	{
          printf("Enter the Value for new Node: ");
          scanf("%d",&num);
          struct node *newnode;
          newnode=(struct node*)malloc(sizeof(struct node));
          newnode->data=num;
          preptr->next=newnode;
	      newnode->next=ptr;
    }
    else
         printf("No node with such value.\n");
	display();
}
void deletebeg()
{
	if(start==NULL)	printf("Underflow");
	else
	{
		ptr=start;
		start=start->next;
		printf("The deleted value is %d\n",ptr->data);
		free(ptr);
		display();
	}
}

void deleteend()
{
	preptr=NULL;
        if(start==NULL) printf("Underflow");
        else
        {
		ptr=start;
		if(ptr->next==NULL)
                        deletebeg();
		else
		{
			while(ptr->next!=NULL)
			{
				preptr=ptr;
				ptr=ptr->next;
			}
		preptr->next=NULL;
		printf("The deleted value is %d\n",ptr->data);
		free(ptr);
		display();
		}
	}
}


void deletespec()
{
        if(start==NULL) printf("Underflow");
        else
        {
		printf("Enter the value which is to be deleted: ");
        	scanf("%d",&val);
		ptr=start;
		if(ptr->data==val)
			deletebeg();
		else
		{
			while(ptr->data!=val)
			{
				preptr=ptr;
				ptr=ptr->next;
			}
			if(ptr->data==val)
			{
                   preptr->next=ptr->next;
			       printf("The deleted value is %d\n",ptr->data);
			       free(ptr);
            }
            else
                  printf("No such node found.\n");
			display();

		}
	}
}

void display()
{
	if(start==NULL) printf("\t\t\t\t\tUnderflow");
    else
    {
		printf("\t\t\t\t\tThe Linked List is: ");
		ptr=start;
		printf("\n\n\t\t\t\t\t%d\n",ptr->data);
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
			printf("\t\t\t\t\t%d\n",ptr->data);
		}
	}
}

main()
{
      int flag;
while(1)
{
    printf("\n\n***MENU***\n1-Create\n2-Insert\n3-Delete\n4-Display\n5-Exit");
	printf("\nEnter your choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
             case 1:create_ll();break;
             case 2:while(1)
                    {
                    flag=0;
                    printf("\n\n1-Insert Beginning\n2-Insert Before a specific node\n3-Insert after a specific node");
                    printf("\n4-Insert At End\n5-Insert after a specific no. of node\n6-Insert before a specific no. of nodes\n7-Back");
	                printf("\n8-Exit\nEnter your choice: ");
                    scanf("%d",&ch);
                    switch(ch)
	                {
                          case 1:insertbeg();break;
	                      case 2:insertbef();break;
	                      case 3:insertaft();break;
	                      case 4:insertend();break;
	                      case 5:insertaft_n();break;
	                      case 6:insertbef_n();break;
	                      case 7:flag=1;break;
	                      case 8:exit(0);
                   }
                   if(flag==1)           break;
                   }break;
             case 3:while(1)
                   {        flag=0;
                            printf("\n1-Delete Beg\n2-Delete end\n3-Delete spec\n4-Back\n5-Exit");
                            printf("\nEnter your choice: ");
                            scanf("%d",&ch);
                            switch(ch)
                            {
                                       case 1:deletebeg();break;
	                                   case 2:deleteend();break;
	                                   case 3:deletespec();break;
	                                   case 4:flag=1;break;
	                                   case 5:exit(0);
                            }
	                        if(flag==1)           break;
                   }break;
	     case 4:display();break;
             case 5:exit(0);
       }
   }
}
