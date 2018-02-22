#include<stdio.h>
int QuickSort(int arr[],int head,int tail)
{
    int std=arr[head];
    while(head<tail)
    {
	while(head<tail)
	{
    	    if(arr[tail]<std)
	    {
	        arr[head]=arr[tail];
		head++;
		break;
	    }
	    tail--;
	}
	while(head<tail)
	{
	    if(arr[head]>std)
	    {
	        arr[tail]=arr[head];
		tail--;
		break;
	    }
	    head++;
	}
    }
    arr[head]=std;
    return head;
}
void Sort(int arr[],int head,int tail)
{
    if(arr==NULL) return;
    if(head>tail) return;
    int std=QuickSort(arr,head,tail);
    QuickSort(arr,head,std-1);
    QuickSort(arr,std+1,tail);
}
int main()
{
    int arr[]={2,3,4,1};
    Sort(arr,0,3);
    for(int i=0;i<4;i++)
    {
        printf("%d\t",arr[i]);
    }

}
