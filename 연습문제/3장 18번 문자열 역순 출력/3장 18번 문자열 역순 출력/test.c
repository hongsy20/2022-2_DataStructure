#include <stdio.h>
#define MAX_STACK_SIZE	100
typedef int Element;

Element data[MAX_STACK_SIZE];
int top;

void error(char str[])
{
	printf("%s\n", str);
	exit(1);
}
void init_stack() { top = -1; }
int is_empty() { return top == -1; }
int is_full() { return top == MAX_STACK_SIZE - 1; }
int size() { return top + 1; }
Element peek() { return data[top]; }

void push(Element e)
{
	if (is_full())
		error("스택오버플로우");
	data[++top] = e;
}
Element pop()
{
	if (is_empty())
		error("스택오버플로우");
	return data[top--];
}

void main()
{
	char user[100];
	scanf("%s", user);
	int i = 0;
	while (user[i] != '\0')
	{
		push(user[i]);
		i++;
	}
	while (is_empty() == 0)
	{
		printf("%c", pop());
	}
}