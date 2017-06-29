/*
	 @author -- Shiv kumar
	 Github -- theShivaa
		Stack Implementation using C programming language 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10
int top=-1;
int stack[SIZE]; 
void push(int item)
{
	if(top==SIZE-1)
	{
		printf("Overflow ! Stack is already full..\n");
		return;
	}
	stack[++top]=item;
}

int pop()
{
	if(top==-1)
	{
		printf("Underflow ! Stack is already Empty..\n");
		return -9999;
	}
	return stack[top--];
}

int main()
{
	printf("Enter \n1. To Push an element to stack\n2.To pop an element from stack\n3. To show the stack\n4.Exit!\n");
	int choice;
	scanf("%d",&choice);
	while(choice!=4)
	{
		int i;
		switch(choice)
		{
			case 1:
				{
					printf("Enter the element to be inserted :\n");
					int a;
					scanf("%d",&a);
					push(a);
					break;
				}
			case 2:
				{
					i=pop();
					if(i==-9999)
						break;
					else
						printf("Poped element is : %d \n",pop());
					break;
				}
			case 3:
			{
				
				printf("Stack is : ");
				if(top==-1)
					printf("Empty.\n");
				else
				{
					for(i=0;i<=top;i++)
					{
						printf("%d ",stack[i]);
					}
				}
				break;
			}
			default :
			{
				printf("OOPS !! Please Enter correct alternative\n");
			}
		}
		printf("\nEnter \n1. To Push an element to stack\n2.To pop an element from stack\n3. To show the stack\n4.Exit!\n");
			scanf("%d",&choice);
	}

}

