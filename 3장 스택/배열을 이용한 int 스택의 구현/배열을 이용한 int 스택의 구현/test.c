#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef int Element;

Element data[MAX_STACK_SIZE];
int top;

void error(char str[]) {
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
		error("스택 공백 에러");
	return data[top--];
}
Element peek()
{
	if (is_empty())
		error("스택 공백 에러");
	return data[top];
}

void print_stack(char msg[])
{
	printf("%s[%2d] = ", msg, size());
	
	for (int i = 0; i < size(); i++)
		printf("%2d ", data[i]);
	printf("\n");
}

int main(void)
{
	init();
	for (int i = 1; i < 10; i++)
		push(i);

	print_stack("스택 push 9회");

	printf("\tpop --> %d\n", pop());
	printf("\tpop --> %d\n", pop());
	printf("\tpop --> %d\n", pop());

	print_stack("스택 pop 3회");
	
	return 0;
}