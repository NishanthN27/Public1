#define no_of_stack 3
#define max 12
#include<stdio.h>
#include<stdlib.h>
void push(int s[],int top[],int boun[],int i)
{
	int elem;
	printf("Enter Element\n");
	scanf("%d",&elem);
	if(top[i]==boun[i+1])
	{
		printf("Overflow\n");
		return;
	}
	top[i]=top[i]+1;
	s[top[i]]=elem;
}
void pop(int s[],int top[],int boun[],int i)
{
	int elem;
	if(top[i]==boun[i])
	{
		printf("Underflow\n");
		return;
	}
	elem=s[top[i]];
	printf("Element popped is %d",elem);
	top[i]=top[i]-1;
}
void display(int s[],int top[],int boun[],int i)
{
	for(i=0;i<no_of_stack;i++)
	{
		printf("Elements of stack %d \n",i);
		if(top[i]==boun[i])
		{
			printf("Underflow\n");
			continue;
		}
		for(int j=boun[i]+1;j<=top[i];j++)
			printf("%d \n",s[j]);
	}
}
int main()
{
	int s[max],top[10],boun[10],ch,i;
	for(i=0;i<no_of_stack;i++)
	{
		top[i]=(max/no_of_stack*i)-1;
		boun[i]=top[i];
	}
	printf("Enter 1. Push\nEnter 2. Pop\nEnter 3. Display\nEnter 4. Exit\n");
	for(;;)
	{
		printf("Enter Choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter stack no\n");
			       scanf("%d",&i);
			       push(s,top,boun,i);
			       break;
			case 2:printf("Enter stack no\n");
			       scanf("%d",&i);
			       pop(s,top,boun,i);
			       break;
			case 3:display(s,top,boun,i);
			       break;
			default:exit(0);
		}
	}
}