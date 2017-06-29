/* 
	 @author -- shiv kumar
	 Github -- theShivaa
	 Stack program using linked list

*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}node;

void push(node **head,int data)
{
	node *tmp=(node *)malloc(sizeof(node));
	if((*head)==NULL)
	{
		tmp->data=data;
		tmp->next=NULL;
		(*head)=tmp;
	}
	
	tmp->data=data;
	tmp->next=(*head);
	(*head)=tmp;
	printf("\n%d is pushed into stack\n",tmp->data);
}

int pop(node **head)
{
	if((*head)==NULL)
	{
		printf("Underflow ! stack is already Empty.\n");
		return -9999;
	}
	int res=0;
	node *tmp=(*head);
	if((*head)->next==NULL)
	{
		res=(*head)->data;
		free(*head);
		(*head)->next=NULL;
	}
	
	(*head)=(*head)->next;
	res=tmp->data;
	free(tmp);
	return res;
	
}



int main()
{
	node *head=NULL;
	printf("Enter \n1. To Push an element to stack\n2.To pop an element from stack\n3.Exit!\n");
	int choice;
	scanf("%d",&choice);
	while(choice!=3)
	{
		int i;
		switch(choice)
		{
			case 1:
				{
					printf("Enter the element to be inserted :\n");
					int a;
					scanf("%d",&a);
					push(&head,a);
					break;
				}
			case 2:
				{
					i=pop(&head);
					if(i==-9999)
						break;
					else
						printf("Poped element is : %d \n",i);
					break;
				}
			
			default :
			{
				printf("OOPS !! Please Enter correct alternative\n");
			}
		}
		printf("\nEnter \n1. To Push an element to stack\n2.To pop an element from stack\n3.Exit!\n");
			scanf("%d",&choice);
	}

}


