#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef char Element;

Element data[MAX_STACK_SIZE];
int top;

void error(char str[])
{
	printf("%s", str);
	exit(1);
}
void init_stack() { top = -1; }
int is_empty() { return top == -1; }
int is_full() { return top == MAX_STACK_SIZE - 1; }
int size() { return top + 1; }
Element peek() { return top; }

void push(Element e)
{
	if (is_full())
		error("스택 오버플로우");
	data[++top] = e;
}
Element pop()
{
	if (is_empty())
		error("스택 오버플로우");
	return data[top--];
}

void main()
{
	char user[100];
	gets(user);
	int len = strlen(user);
	/*
	for (int i = 0; i < len; i++)
	{
		if (user[i] == ' ')
			continue;
		push(user[i]);
	}
	*/
	int i = 0;
	while (user[i] != '\0')
	{
		if (user[i] != ' ')
			push(user[i]);
		i++;
	}
	int result = 1;
	for (int i = 0; i < size() - 1; i++)
	{
		if (user[i] != pop())
		{
			result = 0;
		}
		break;
	}
	if (result == 1)
		printf("회문\n");
	else
		printf("회문 아님\n");
}