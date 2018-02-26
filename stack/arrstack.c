#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10
#define OK 1
#define ERROR -1
typedef int STATU;
typedef struct node{
	int arr[SIZE];
	int top1;
	int top2;
	int nCount1;
	int nCount2;
}stack,*stackptr;
void CreatStack(stackptr* p)
{
	*p=(stackptr)malloc(sizeof(stack));
	memset(*p,0,sizeof(stack));
	(*p)->top1=-1;
	(*p)->top2=SIZE;
	(*p)->nCount1=0;
	(*p)->nCount2=0;
}
void ShowCount(stackptr p)
{
	printf("%d\t%d\t\n",p->nCount1,p->nCount2);
}
int push(stackptr pstack,int e,int s)
{
	if(pstack->top1+1==pstack->top2) return ERROR;
	if(s==1)
	{
		pstack->arr[++pstack->top1]=e;
		pstack->nCount1++;
	}
	else if(s==2)
	{
		pstack->arr[--pstack->top2]=e;
		pstack->nCount2++;
	}
	return OK;
}
int pop(stackptr pstack,int s)
{
	int reval;
	if(s==1)
	{
		if(pstack->top1==-1) return ERROR;
		reval=pstack->arr[pstack->top1--];
		pstack->nCount1--;
		return reval;
	}
	else if(s==3)
	{	
		if(pstack->top2==SIZE) return ERROR;
		reval=pstack->arr[pstack->top2++];
		pstack->nCount2--;
		return reval;
	}
}
void showarr(stackptr p)
{
	for(int i=0;i<SIZE;i++)
	{
		printf("%d\t",p->arr[i]);
	}
}
int main()
{
	stackptr p;
	CreatStack(&p);
	push(p,1,1);
	push(p,1,2);
	printf("%d\n",pop(p,1));
	ShowCount(p);
	showarr(p);
	
}
