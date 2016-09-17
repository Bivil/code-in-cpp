#include<stdio.h>
#include<stdlib.h>

int num,ch,val,i,flag;

struct node
{
        struct node *prev;
        int data;
        struct node *next;
};
struct node *start=NULL,*ptr;
void deleteend();
void deletebeg();
void display();
void create_ll()
{
        printf("Enter the Value for First Node: ");
        scanf("%d",&num);
        struct node *firstnode;
        firstnode=(struct node*)malloc(sizeof(struct node));
        firstnode->data=num;
        firstnode->next=NULL;
        firstnode->prev=NULL;
        start=firstnode;
        display();
}


void deletespec()
{
	int f=0;
	printf("Enter the node to be deleted: ");
        scanf("%d",&val);
        ptr=start;
        while(ptr->data!=val && ptr->next!=NULL)
                ptr=ptr->next;
        if(ptr->data==val)
        {
          if(ptr->next==NULL)
          { f=1;  deleteend(); }
	  else if(ptr->prev==NULL){ f=1; deletebeg(); }
          else
          {
		ptr->prev->next=ptr->next;
		ptr->next->prev=ptr->prev;
		free(ptr);
	  }
	}
	else
         printf("No node with such value.\n");
	if(f==0)
         display();
}

void deletebeg()
{
	if(start==NULL) 	display();
        else if(start->next==NULL)
	{
		ptr=start;
		printf("The deleted value is %d\n",ptr->data);
		start=NULL;
		free(ptr);
                display();
	}
	else
        {
                ptr=start;
                start=start->next;
		start->prev=NULL;
                printf("The deleted value is %d\n",ptr->data);
                free(ptr);
                display();
        }
}
void deleteend()
{
	if(start==NULL)  display();
        else if(start->next==NULL)
        {
                ptr=start;
                printf("The deleted value is %d\n",ptr->data);
                start=NULL;
                free(ptr);
                display();
        }
	else
        {
                ptr=start;
		while(ptr->next!=NULL)
              	ptr=ptr->next;
		printf("The deleted value is %d\n",ptr->data);
		ptr->prev->next=NULL;
		free(ptr);
		display();
	}
}



void insertbeg()
{
        printf("Enter the Value for new Node: ");
        scanf("%d",&num);
        struct node *newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
        newnode->next=start;
        newnode->prev=NULL;
        start->prev=newnode;
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
              newnode->prev=ptr;
        }
     display();
}

void insertaft()
{
        int f=0;
        printf("Enter the value  after which the newnode is to be inserted: ");
        scanf("%d",&val);
        ptr=start;
        while(ptr->data!=val && ptr->next!=NULL)
                ptr=ptr->next;
        if(ptr->data==val)
        {
	  if(ptr->next==NULL)
	  { f=1;  insertend();  }
	  else
	  {
          printf("Enter the Value for new Node: ");
          scanf("%d",&num);
          struct node *newnode;
          newnode=(struct node*)malloc(sizeof(struct node));
          newnode->data=num;
          newnode->next=ptr->next;
	  ptr->next->prev=newnode;
          newnode->prev=ptr;
	  ptr->next=newnode;
	  }
      }
      else
         printf("No node with such value.\n");
      if(f==0)   display();
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
        for(i=1;i<val;i++)
        {
                if(ptr->next==NULL && i!=val)
                {
                        printf("Total Number of Nodes is less. Try again with a lower value.\n");
                        flag=1;break;
                }
		ptr=ptr->next;
        }
        if(flag==0)
        {
	if(ptr->next==NULL) insertend();
	else
	{
        printf("Enter the Value for new Node:2 ");
    	scanf("%d",&num);
    	struct node *newnode;
    	newnode=(struct node*)malloc(sizeof(struct node));
    	newnode->data=num;
        newnode->next=ptr->next;
	ptr->next->prev=newnode;
	newnode->prev=ptr;
	ptr->next=newnode;
	}
        }
        display();
    }
}

void insertbef()
{
        printf("Enter the value before which the newnode is to be inserted: ");
        scanf("%d",&val);
        ptr=start;
        while(ptr->data!=val && ptr->next!=NULL)
                ptr=ptr->next;
        if(ptr->data==val)
        {
	      if(ptr->prev==NULL)    insertbeg();
	      else
	      {
              printf("Enter the Value for new Node: ");
              scanf("%d",&num);
              struct node *newnode;
              newnode=(struct node*)malloc(sizeof(struct node));
              newnode->data=num;
              newnode->next=ptr;
	      ptr->prev->next=newnode;
	      newnode->prev=ptr->prev;
	      ptr->prev=newnode;
	      }
    }
    else
        printf("No node with the given value.\n");
    display();
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
    if(val==0)   {       insertend();return; }
    else if(val==i+1) {       insertbeg();return; }
    else if(val>i)
         printf("Total Number of Nodes is less. Try again with a lower value.");
    else
    {
        for(i=1;i<=val;i++)
        {       ptr=ptr->prev;   }
        printf("Enter the Value for new Node: ");
        scanf("%d",&num);
        struct node *newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=num;
        newnode->next=ptr->next;
	newnode->prev=ptr;
	ptr->next=newnode;
        newnode->next->prev=newnode;
     }
     display();
}

void display()
{
        if(start==NULL) printf("\t\t\t\t\tUnderflow");
    else
    {
                printf("\t\t\t\t\tThe Doubly Linked List is: ");
                ptr=start;
                printf("\n\n\t\t\t\t\t%d\n",ptr->data);
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
                        printf("\t\t\t\t\t%d\n",ptr->data);
                }
        }
}



int main()
{

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
                     {
                    flag=0;
                    printf("\n\n1-Delete Beginning\n2-Delete End\n3-Delete a specific Node");
                    printf("\n4-Back\n5-Exit\nEnter your choice: ");
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
            case 5:exit(0);break;



	}
}
}
