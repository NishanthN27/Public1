#include<stdio.h>
#include<stdlib.h>
#define mz 3
void insert_cq(int cq[mz], int *rear,int *count)
{
	int elem;
	if(*count==mz)
	{
		printf("overflow\n");
		return;
	}
	printf("enter element:\n");
	scanf("%d",&elem);
	*rear=(*rear+1)%mz;
	cq[*rear]=elem;
	(*count)++;
}
void delete_cq(int cq[mz],int *front, int *count)
{
	int elem;
	if(*count==0)
	{
		printf("underflow\n");
		return;
	}
	elem=cq[*front];
	*front=((*front)+1)%mz;
	(*count)--;
	printf("%d is deleted",elem);
}
void display(int cq[mz],int front,int count)
{
	int i;
	if(count==0)
	{
		printf("no elements present in cq\n");
		return;
	}
	for(i=0;i<count;i++)
	{
		printf("%d \t",cq[front+i]);
	}
}
int main()
{
	int cq[mz],front=0,rear=mz-1,count=0,ch;
	while(1)
	{
		printf("\n1:insert\n2:delete\n3:display\n4:exit\nenter choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert_cq(cq,&rear,&count);
			break;
			case 2:delete_cq(cq,&front,&count);
			break;
			case 3:display(cq,front,count);
			break;
			default:exit(0);
		}
	}
}
	
