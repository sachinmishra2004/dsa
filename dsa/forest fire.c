/* Read input from STDIN. Print your output to STDOUT*/
#include<stdio.h>
int main(int argc, char *a[])
{
    /*Input Values*/
	unsigned int N, X;
	scanf("%d", &N);
	scanf("%d", &X);
	unsigned int arr[N];

	for(int i = 0;i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	unsigned int count = 0; //Counter for counting the valid energy levels
	int dec = -1; //Decision Variable
	for(unsigned int j=0;j<N;j++)
	{
		unsigned int temp = arr[j];

		for(unsigned int k=0;k<N;k++)
		{
			if(temp <= arr[k])
			{
				count++;
			}
		}

		if(count == X)
		{
			dec =1;
			printf("%d", temp);
			break;
		}

		count = 0;
	}

	if(dec==-1)
	{
		printf("%d", dec);
	}

}