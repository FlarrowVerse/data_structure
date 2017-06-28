#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

void traverse(node *head)
{
	node *t=head;
	while(t)
	{
		printf("%d ",t->data);
		t=t->next;
	}
}
node *search(node *head,int d)
{
	if(head==NULL)
	{
		return NULL;
	}
	node *p=head;
	while(p)
	{
		if(p->data==d)
			break;
		p=p->next;
	}
	return p;
}

void insertb(node **head,int d)
{
	node *tmp=(node *)malloc(sizeof(node));
	if(head==NULL)
	{
		tmp->data=d;
		tmp->next=NULL;
		(*head)=tmp;
	}
	tmp->data=d;
	tmp->next=(*head);
	(*head)=tmp;

}

void inserten(node **head,int d)
{
	node *tmp=(node *)malloc(sizeof(node));
	tmp->data=d;
	if((*head)==NULL)
	{
		tmp->next=NULL;
		(*head)=tmp;
		
	}
	node *p=(*head);
	while(p->next)
	{
		p=p->next;
	}
	p->next=tmp;
	tmp->next=NULL;
	
}

void insertp(int d,int p,node *head)
{
	node *t=search(head,p);
	if(t==NULL)
	{
		printf("Given data is not present.\n");
		return;
	}
	node *tmp=(node *)malloc(sizeof(node));
	tmp->data=d;
	tmp->next=t->next;
	t->next=tmp;
}

void deleteb(node **head)
{
	node *t=(*head);
	if(t==NULL)
	{
		printf("Linked list is already Empty");
		return;
	}
	(*head)=t->next;
}

void deleten(node **head)
{
	if((*head)==NULL)
	{
		printf("UnderFlow");
		return;
	}
		
	node *t=(*head);
	if(!((*head)->next))
	{
		free(*head);
		(*head)=NULL;
		return;
		
	}
	while(t->next->next)
	{
		t=t->next;
	}
	t->next=NULL;
}

void deletep(node *head,int d)
{
	node *p=search(head,d);
	if(p==NULL)
	{
		printf("Element doesn't exist in Linked List\n");
		return;
	}
	p->next=p->next->next;
}

int main()
{
	node *head=NULL;
	int n;
	printf("\nEnter \n1. To Insert an element to Linked List\n2.To Delete an element from linked list \n");
			
	scanf("%d",&n);
	int m;
	while(1)
	{
		switch(n)
		{
			case 1:
				{
					printf("Enter \n1. To insert in begining \n2. To Insert at end \n3. To Insert at given position\n");
				
					scanf("%d",&m);
					switch(m)
					{
						case 1: 
							{
								int d;
								printf("Enter the data to be inserted :\n");
								scanf("%d",&d);
								insertb(&head,d);
								traverse(head);
								break;
							}
						case 2:
							{
								int d;
								printf("Enter the data to be inserted :\n");
								scanf("%d",&d);
								inserten(&head,d);
								traverse(head);
								break;
							}
						case 3:
							{
								int d,p;
								printf("Enter the data and element after which data is to be inserted :\n");
								scanf("%d%d",&d,&p);
								insertp(d,p,head);
								traverse(head);
								break;
							}
						}
						break;
				}
			case 2:
				{
					printf("Enter \n1. To delete in begining \n2. To delete at end \n3. To delete at given position\n");
					scanf("%d",&m);
					switch(m)
					{
						case 1: 
							{
								deleteb(&head);
								traverse(head);
								break;
							}
						case 2:
							{
								deleten(&head);
								traverse(head);
								break;
							}
						case 3:
							{
								int p;
								printf("Enter element after which data is to be deleted :\n");
								scanf("%d",&p);
								deletep(head,p);
								traverse(head);
								break;
							}
						}
					break;
				}
			}
			printf("\nEnter \n1. To Insert an element to Linked List\n2.To Delete an element from linked list \n");
			scanf("%d",&n);
		
	}
}






