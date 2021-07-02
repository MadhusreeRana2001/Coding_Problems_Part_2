#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int i=0,j=0;

int matrix_Makeover(int[][20],int[][20],int,int); // to get the minimal no. of moves

int matrix_Makeover(int a[][20],int b[][20],int n,int m)
{
	int res=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			a[i][j]-=b[i][j];
	}
	for(i=1;i<n;i++)
	{
		for(j=1;j<m;j++)
			if(a[i][j]-a[i][0]-a[0][j]+a[0][0]!=0)
				return -1;
	}
	for(i=0;i<n;i++)
		res+=abs(a[i][0]);
	for(j=0;j<m;j++)
		res+=abs(a[0][j]-a[0][0]);
	return abs(res);
}

int main()
{
	int n=0,m=0;
	int a[20][20],b[20][20];
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			scanf("%d",&b[i][j]);
	}
	printf("%d",matrix_Makeover(a,b,n,m));
	return 0;
}
