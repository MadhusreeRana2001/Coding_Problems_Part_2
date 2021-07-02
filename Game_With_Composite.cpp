#include<stdio.h>

int max_Composite(int);  // to calculate the maximum no. of composite nos. possible

int max_Composite(int n)
{
	int rem=0,d=0,m=0;
	if(n<4 || n==5 || n==7 || n==11) // such nos. cannot be split into composite nos.
		return -1;
	else
	{
		rem=n%4;  // since 4 is the smallest composite no.
		if(rem==0)
			return n/4;
		else
		{
			if(rem==1)
			{
				m=n-9;
				d=m/4;
				return d+1;  // adding a 9 will make upto the original no.
			}
			else if(rem==2)
			{
				m=n-6;
				d=m/4;
				return d+1; // adding a 6 will make upto the original no.
			}
			else if(rem==3)
			{
				m=n-15;
				d=m/4;
				return d+2;  // since 15 can further be broken into 9+6, hence add 2
			}
		}	
	}
}

int main()
{
	int n=0;
	scanf("%d",&n);
	printf("%d",max_Composite(n));
	return 0;
}
