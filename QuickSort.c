#include<stdio.h>
#include<stdlib.h>
#include "Stack.h"

void display(int *a, int n)			// Function to display array.
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d\t", a[i]);
	printf("\n");
}

void finput(int *a, int n)			// Function to take inputs from the file Number.txt and store them in array.
{
	int i;
	FILE *fp = fopen("Number.txt", "r");	// File pointer
	for(i = 0; i < n; i++)
		fscanf(fp, "%d", a + i);	
}

void input(int *a, int n)			// Function for console input and store them in array.
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("Enter a No. = ");
		scanf("%d", a + i);
	}
}

void quicksort(int *a, int n)			// QuickSort implementation using interative technique.
{
	Stack stack[10];			
	int small, big, top = -1, t, begin, end;
	
	begin = 0, end = n - 1;

	while(begin < end || pop(stack, &top, &begin, &end))	// Loop terminates only when begin index has crossed end index AND stack is empty.
	{
		
		printf("\nBegin = %d End = %d Stack Top = %d \n", begin, end, top); // Debugging
		display(a, n);							    // Display the state of array at each iteration.
		small = begin + 1;						    // The first element pointed by begin is taken as pivot.
		while(small <= end && a[small] < a[begin])			    // Elements smaller than pivot starts from begin + 1 onwards.
			small++;						    // We keep on increasing small until we get a bigger element than pivot.
		big = small--;							    // Loop stops if we get bigger element than pivot and we set big to that index and correct small to the previous index.
		
		while(big <= end)						    // We iterate from newly pointed big index to the end.
		{
			if(a[big] < a[begin])
			{							    // if we get a smaller number than pivot then we swap it with the 1st big element.
				t = a[big];					    // After swapping we increase small var. by 1 and big var. by 1
				a[big] = a[small + 1];
				a[small++ + 1] = t;
			}
			big++;
		}
		t = a[begin];	a[begin] = a[small];	a[small] = t;		    // we swap the pivot with the pivot with the last small element.
		
		if(small + 1 < end)
			push(stack, &top, 10, small + 1, end);			    // if a subarray of bigger elements than pivot exists then push that subarray limits in stack.
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
