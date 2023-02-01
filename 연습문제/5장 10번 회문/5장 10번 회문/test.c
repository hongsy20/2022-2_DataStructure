#include <stdio.h>
#include <string.h>
#define MAX 100
typedef int Element;
typedef struct LinkNode {
	Element data;
	struct LinkNode* link;
}Node;
Node* top = NULL;

void error(char* str)
{
	printf("%s", str);
	exit(1);
}
int is_empty() { return top == NULL; }
void init() { top = NULL; }
int size()
{
	Node* p;
	int counter = 0;
	for (p = top; p != NULL; p = p->link)
		counter++;
	return counter;
}
void push(Element e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->link = top;
	top = p;
}
Element pop()
{
	Node* p; Element e;
	if (is_empty())
		error("오류");
	p = top;
	top = p->link;
	e = p->data;
	free(p);
	return e;
}
Element peek()
{
	if (is_empty())
		error("오류");
	return top->data;
}
void destroy_stack()
{
	while (is_empty() == 0)
		pop();
}

void main()
{
	char user[100];
	gets(user);

	for (int i = 0; i < strlen(user); i++)
	{
		if (user[i] != ' ')
			push(user[i]);
	}

	for (int i = 0; i < strlen(user); i++)
	{
		if (pop() != user[i])
		{
			printf("회문 아님\n");
			return;
		}
	}
	printf("회문\n");
}