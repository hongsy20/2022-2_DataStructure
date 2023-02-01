#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100
typedef int Element;

Element data[MAX_QUEUE_SIZE];
int front, rear;

void error(char str[])
{
	printf("%s\n", str);
	exit(1);
}
void init_queue() { front = rear = 0; }
int is_empty() { return front == rear; }
int is_full() { return front == (rear + 1) % MAX_QUEUE_SIZE; }
int peek() { return data[(front + 1) % MAX_QUEUE_SIZE]; }
int size() { return (rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; }

void push_rear(Element e)
{
	if (is_full())
		error("큐 포화 에러");
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear] = e;
}
void push_front(Element e)
{
	if (is_full())
		error("큐 포화 에러");
	data[front] = e;
	front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}
Element delete_front()
{
	if (is_empty())
		error("큐 포화 에러");
	front = (front + 1) % MAX_QUEUE_SIZE;
	return data[front];
}
Element delete_rear()
{
	Element e = rear;
	if (is_empty())
		error("큐 포화 에러");
	rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return data[e];
}

void main()
{
	char user[100];
	gets(user);
	for (int i = 0; i < strlen(user); i++)
	{
		if (user[i] != ' ')
			push_rear(user[i]);
	}

	while (is_empty() == 0)
	{
		if (is_empty())
			break;
		int v1 = delete_front();
		if (is_empty())
			break;
		int v2 = delete_rear();
		
		if (v1 != v2)
		{
			printf("회문 아님\n");
			return;
		}
	}
	printf("회문\n");
}