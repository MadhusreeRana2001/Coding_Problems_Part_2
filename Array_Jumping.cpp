#include<stdio.h>
#include<stdlib.h>

int count(int n, int a[]);  // to count the minimum no. of jumps across the array

int count(int n, int a[])
{
	int i=0,cnt=0,rem=0;
	while(i<n)
	{
		if(a[i]==0)
			return -1;
		else
		{
			rem=n-(i+1);
			cnt+=1;
			if(a[i]<=rem)
				i+=a[i];
			else
				return cnt;
		}
	}
}

int main()
{
	int i=0,n=0;
	int *a;
	scanf("%d",&n);
	a=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\n \n%d",count(n,a));
	return 0;
}
