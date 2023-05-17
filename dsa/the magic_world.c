/* Read input from STDIN. Print your output to STDOUT*/
#include<stdio.h>
int main(int argc, char *a[])
{
	int N, M;
	scanf("%d", &N);
	scanf("%d", &M);
	//printf("N: %d, M: %d\n", N, M);
	int arr[N];
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		//printf("%d, ", arr[i]);
	}
	//printf("\n");
	int queries[M];
	for(int i = 0; i < M; i++)
	{
		scanf("%d", &queries[i]);
		//printf("%d, ", queries[i]);
	}
#if(1)
	int cost = 0;
	for(int i = 0; i < M; i++)
	{
		int temp_q = queries[i];

		for(int j = 0; j < N; j++)
		{
			int temp = arr[j] - temp_q;
			if(temp < 0)
				temp = temp*-1;
			
			cost = cost + temp;
		}

		printf("%d ", cost);
		cost = 0;
	}
#endif
}