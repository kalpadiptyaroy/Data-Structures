#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct Node {int x; struct Node *next;} Node;

int insert(Node **start, int x)
{
	Node *p = *start;
	if(*start == NULL)
	{
		*start = (Node *)malloc(sizeof(Node));
		if(*start == NULL)
			return 0;
		(*start)->x = x;
		(*start)->next = NULL;
	}
	else
	{
		while(p->next != NULL)
			p = p->next;
		p->next = (Node *)malloc(sizeof(Node));
		if(p->next == NULL)
			return 0;
		p->next->x = x;
		p->next->next = NULL;
	}
}

int delete(Node **start, int *x)
{
	Node *p = *start;
	if(*start == NULL)
		return 0;
	else if((*start)->next == NULL)
	{
		*x = (*start)->x;
		free(*start);
		*start = NULL;
		return 1;
	}
	else
	{
		while(p->next->next != NULL)
			p = p->next;
		*x = p->next->x;
		free(p->next);
		p->next = NULL;
		return 1;
	}
}

void display(Node *start)
{
	while(start != NULL)
	{
		printf("%d -> ", start->x);
		start = start->next;
	}
	printf("NULL\n");
}

int makeNewLink(Node *start)
{
	Node *p = start, *q;
	char c = '\0';
	printf("\nEnter 'Y' to Point to that Node : ");
	while(p != NULL)
	{
		printf("\nNode : %d", p->x);
		printf("\nEnter choice = ");
		fflush(stdin);
		scanf("%c", &c);
		if(c == 'Y' || c == 'y')
		{
			q = p;
			break;
		}
		p = p->next; 
	}
	while(p != NULL && p->next != NULL)
		p = p->next;
	if(p != NULL)
	{
		p->next = q;
		return 1;
	}
	else
		return 0;
}

void check(Node *start)
{
	Node *q, *k; int cQ = 0, cK = 0;
	if(start == NULL)
		printf("List Empty");
	else
	{
		for(q = start; q != NULL; q = q->next, cQ++)
		{
			for(k = start, cK = 0; k != q; k = k->next, cK++);
			if(cK < cQ)
			{
				printf("Circullar Link Detected!");
				return;
			}
			
		}
		printf("List is Perfectly Linear"); 
	}
}

int main()
{
	Node *start = NULL;
	int x, choice;
	
	printf("\nEnter 1 to Insert");
	printf("\nEnter 2 to Delete");
	printf("\nEnter 3 to Display");
	printf("\nEnter 4 to Create Circullar Link");
	printf("\nEnter 5 to check");
	printf("\nEnter 6 to Quit");
	do
	{
		printf("\nEnter your choice = ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1: printf("Enter a No. = ");
				scanf("%d", &x);
				if(!insert(&start, x))
					printf("Insertion Failed");
				break;
			case 2: if(!delete(&start, &x))
					printf("Deletion Failed");
				printf("\nDeleted = %d", x);
				break;
			case 3: display(start);
				break;
			case 4: if(!makeNewLink(start))
					printf("Link Not made");
				else
					printf("Link Created");
				break;
			case 5: check(start);
				break;
			case 6: break;
				
		}
	}
	while(choice != 6);
	return 1;
}