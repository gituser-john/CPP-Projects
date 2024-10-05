#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node* head=NULL;
void ins_head(int newinfo)
{
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=newinfo;
	new->next=head;
	head=new;
}
void ins_end(int newinfo)
{
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=newinfo;
	new->next=NULL;
	struct node* ptr=head;
	if(ptr==NULL)
	{
		head=new;
	}
	else
	{
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=new;
	}
}
void ins_btw(int key,int newinfo)
{
	struct node* ptr=head;
	while(ptr!=NULL&&ptr->data!=key)
	{
		ptr=ptr->next;
	}
	if(ptr!=NULL)
	{
		struct node* new=(struct node*)malloc(sizeof(struct node));
		new->data=newinfo;
		new->next=ptr->next;
		ptr->next=new;
	}
	else
	{
		printf("Key not found\n");
	}
}
void dis()
{
	struct node* ptr=head;
	if(ptr==NULL)
	{
		printf("Empty list\n");
	}
	else
	{
		while(ptr!=NULL)
		{
			printf("%d   ",ptr->data);
			ptr=ptr->next;
		}
		printf("\n");
	}
}
void del_head()
{
	struct node* ptr=head;
	if(ptr==NULL)
	{
		printf("Empty list\n");
	}
	else
	{
		head=ptr->next;
		free(ptr);
	}
}
void del_end()
{
	struct node* ptr=head;
	if(ptr==NULL)
	{
		printf("Empty list\n");
	}
	else if(ptr->next==NULL)
	{
		free(ptr);
		head=NULL;
	}
	else
	{
		struct node* prep;
		while(ptr->next!=NULL)
		{
			prep=ptr;
			ptr=ptr->next;
		}
		prep->next=NULL;
		free(ptr);
	}
}
void del_btw(int key)
{
	struct node* ptr=head;
	if(ptr==NULL)
	{
		printf("Empty list\n");
	}
	else
	{
		struct node* prep;
		while(ptr->next!=NULL)
		{
			if(ptr->data==key)
			{
				if(ptr->next==NULL)
				{
					printf("No element to delete\n");
				}
				else
				{
					prep=ptr->next;
					ptr->next=prep->next;
					free(prep);
					break;
				}
			}
			ptr=ptr->next;
		}
	}
}
void main()
{
	char ch;
	do
	{
		printf("Linked List Operations\n1.Display\n2.Ins_Head\n3.Ins_End\n4.Ins_Btw\n5.Del_Head\n6.Del_End\n7.Del_Btw\n");
		int op,n,k;
		printf("Enter option number : ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				dis();
				break;
			case 2:
				printf("Enter element : ");
				scanf("%d",&n);
				ins_head(n);
				break;
			case 3:
				printf("Enter element : ");
				scanf("%d",&n);
				ins_end(n);
				break;
			case 4:
				printf("Enter element : ");
				scanf("%d",&n);
				printf("Enter key : ");
				scanf("%d",&k);
				ins_btw(k,n);
				break;
			case 5:
				del_head();
				break;
			case 6:
				del_end();
				break;
			case 7:
				printf("Enter key : ");
				scanf("%d",&k);
				del_btw(k);
				break;
			default:
				printf("Invalid option\n");
				break;
		}
		printf("Do you want to continue (y/n) ? : ");
		scanf(" %c",&ch);
	}
	while(ch=='y');
}
