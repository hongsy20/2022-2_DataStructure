#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef int Element;

Element data[MAX_STACK_SIZE];
int top;

void error(char str[])
{
	printf("%s\n", str);
	exit(1);
}

void init() { top = -1; }
int is_empty() { return top == -1; }
int is_full() { return top == MAX_STACK_SIZE - 1; }
int size() { return top + 1; }

void push(Element e)
{
	if (is_full())
		error("스택 포화 에러");
	data[++top] = e;
}
Element pop()
{
	if (is_empty())
		error("스택 포화 에러");
	return data[top--];
}
Element peek()
{
	if (is_empty())
		error("스택 포화 에러");
	return data[top];
}
void print_stack(char str[])
{	
	printf("%s\n", str);
	for (int i = 0; i < size(); i++)
		printf("%d ", data[i]);
	printf("\n");
}

int main(void)
{
	init();
	char user[50];
	
	for (int i = 0; i < 10; i++)
	{
		scanf("%s", user);
		if (strcmp("push", user) == 0)
		{
			int num;
			scanf("%d", &num);
			push(num);
		}
		else if (strcmp("pop", user) == 0)
			pop();
	}
	print_stack("최종결과\n");

	return 0;
}