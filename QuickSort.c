#include<stdio.h>
#include<stdlib.h>
#include "Stack.h"

void display(int *a, int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d\t", a[i]);
	printf("\n");
}

void finput(int *a, int n)
{
	int i;
	FILE *fp = fopen("Number.txt", "r");
	for(i = 0; i < n; i++)
		fscanf(fp, "%d", a + i);	
}

void input(int *a, int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("Enter a No. = ");
		scanf("%d", a + i);
	}
}

void quicksort(int *a, int n)
{
	Stack stack[10];
	int small, big, top = -1, t, begin, end;
	
	begin = 0, end = n - 1;

	while(begin < end || pop(stack, &top, &begin, &end))
	{
		
		printf("\nBegin = %d End = %d Stack Top = %d \n", begin, end, top);
		display(a, n);
		small = begin + 1;
		while(small <= end && a[small] < a[begin])
			small++;
		big = small--;
		
		while(big <= end)
		{
			if(a[big] < a[begin])
			{
				t = a[big];
				a[big] = a[small + 1];
				a[small++ + 1] = t;
			}
			big++;
		}
		t = a[begin];	a[begin] = a[small];	a[small] = t;
		
		if(small + 1 < end)
			push(stack, &top, 10, small + 1, end);
		end = small - 1;
	}
}

int main()
{
	int *a, n;

	printf("Enter the Size of Array = ");
	scanf("%d", &n);

	a = (int*) malloc(n * sizeof(int));

	printf("Enter the Elements \n");
	finput(a, n);

	printf("ORIGINAL ARRAY: \n");
	display(a, n);
	
	printf("\nDURING QUICK SORT\n");
	quicksort(a, n);
	
	printf("SORTED ARRAY: \n");
	display(a, n);

	return 1;
}