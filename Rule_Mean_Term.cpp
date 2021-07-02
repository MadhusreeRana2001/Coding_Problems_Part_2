#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int to_Decimal(int []);  // to convert binary to decimal
void rule_Mean_Term(int, int, int[]); // to compute the rule-mean-term array 

int to_Decimal(int temp[])
{
	int i=0,sum=0;
	for(i=2;i>=0;i--)
	{
		if(temp[i]==0)
			continue;
		else
			sum+=pow(2,2-i);
	}
	return sum;
}

void rule_Mean_Term(int n, int P, int a[])
{
	int i=0,j=0,first=0,last=0;
	int temp[3],*R;
	R=(int*)malloc(sizeof(int)*n);
	if(P)
	{
		first=a[n-1];
		last=a[0];
	}
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			temp[0]=first;
			temp[1]=a[i];
			temp[2]=a[i+1];
		}
		else if(i==n-1)
		{
			temp[0]=a[i-1];
			temp[1]=a[i];
			temp[2]=last;
		}
		else
		{
			temp[0]=a[i-1];
			temp[1]=a[i];
			temp[2]=a[i+1];
		}
		R[i]=to_Decimal(temp);
	}
	for(i=0;i<n;i++)
		printf("%d ",R[i]);
}

int main()
{
	int i=0,n=0,P=0;
	int *a;
	scanf("%d %d",&n,&P);
	a=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	rule_Mean_Term(n,P,a);
	return 0;
}
