/* 
Note : The array can be sorted in any method, but here, I've sorted using merge sort
in order to keep the time complexity as minimum as possible, since, the number of 
shirts can be maximum 100.
*/ 

#include<stdio.h>
#include<stdlib.h>

void merge_Sort(int [], int, int); // for dividing the array into small sub-arrays
void merge(int [], int, int, int); // for sorting and merging the sub-arrays
int count(int [],int,int); // to count the minimum number of shirts to buy

void merge_Sort(int a[],int beg,int end)
{
	int mid=0;
	if(beg<end)
	{
		mid=(beg+end)/2;
		merge_Sort(a,beg,mid);
		merge_Sort(a,mid+1,end);
		merge(a,beg,mid,end);
	}
}

void merge(int a[],int beg,int mid,int end)
{
	int i=beg,j=mid+1,index=beg,k=beg;
	int *temp;
	temp=(int*)malloc(sizeof(int)*(end+1));
	while(i<=mid && j<=end) // for sorting the sub-arrays
	{
		if(a[i]<a[j]) // if the elements of the left sub-array are smaller
		{
			temp[index]=a[i];
			i++;
		}
		else // if the elements of the right sub-array are smaller
		{
			temp[index]=a[j];
			j++;
		}
		index++;
	}
	if(i>mid) // if there are elements left to be merged from the right sub-array
	{
		while(j<=end)
		{
			temp[index]=a[j];
			index++;
			j++;
		}
	}
	else // if there are elements left to be merged from the left sub-array
	{
		while(i<=mid)
		{
			temp[index]=a[i];
			index++;
			i++;
		}
	}
	for(k=beg;k<index;k++)
		a[k]=temp[k];
}

int count(int a[],int n,int budget)
{
	int i=0,min=0,sum=0;
	if((a[0]>budget) || (n>=100 || budget>=100000))
		min=0;
	else
	{
		for(i=0;i<n;i++)
		{
			sum+=a[i];
			if(sum<=budget)
				min++;
			else
				break;	
		}
	}
	return min;
}

int main()
{
	int i=0,j=0,cases=0,n=0,budget=0;
	int *a,*output;
	scanf("%d",&cases);
	output=(int*)malloc(sizeof(int)*cases);
	while(j<cases)
	{
		scanf("%d %d",&n,&budget);
		a=(int*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		merge_Sort(a,0,n-1);
		output[j]=count(a,n,budget);
		j++;
	}
	for(i=1;i<=cases;i++)
		printf("Case #%d: %d \n",i,output[i-1]);
	return 0;
}
