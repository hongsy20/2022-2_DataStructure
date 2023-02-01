#include <stdio.h>
#include <string.h>
typedef int Element;
typedef struct num {
	Element number;
	struct num* link;
}Node;
Node* front = NULL;
Node* rear = NULL;

void error(char* str)
{
	printf("%s", str);
	exit(1);
}
int is_empty() { return front == NULL; }
void init() { front = rear = NULL; }
int size()
{
	Node* p; int counter = 0;
	for (p = front; p != NULL; p = p->link)
		counter++;
	return counter;
}
void enqueue(Element e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->number = e;
	p->link = NULL;
	if (is_empty())
		front = rear = p;
	else
	{
		rear->link = p;
		rear = p;
	}
}
Element dequeue()
{
	Node* p; Element e;
	if (is_empty())
		error("완료");
	p = front;
	front = front->link;
	if (front == NULL)
		rear = NULL;
	e = p->number;
	free(p);
	return e;
}
Element peek()
{
	if (is_empty())
		error("오류");
	return front->number;
}
void destroy_queue()
{
	while (is_empty() == 0)
		dequeue();
}

void main()
{
	int counter = 0;
	while (1)
	{
		printf("양의 정수를 입력하세요(종료는 -1): ");
		int num;
		scanf("%d", &num);
		if (num == -1)
			break;
		enqueue(num);
		counter++;
	}
	for (int i = 0; i < counter; i++)
	{
		printf("%d", dequeue());
		printf(" -> ");
	}
	printf("NULL");
}