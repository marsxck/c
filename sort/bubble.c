#include<stdio.h>
void bubble(int arr[],int nLength)
{
	int flag=0;
	for(int i=0;i<nLength-1;i++)
	{
		flag=0;
		for(int j=0;j<nLength-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				arr[j]=arr[j]^arr[j+1];
				arr[j+1]=arr[j]^arr[j+1];
				arr[j]=arr[j]^arr[j+1];
				flag=j+1;
			}
		}
		if(flag==0) return;
		i=nLength-flag-1;
	}
}
void main()
{
	int arr[]={1,2,5,4,3,3,3};
	bubble(arr,7);
	for(int i=0;i<7;i++)
	{
		printf("%d\t",arr[i]);
	}
}
