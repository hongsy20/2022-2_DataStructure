#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct LinkedNode {
	Element data;
	struct LinkedNode* link;
}Node;
Node* head = NULL;

void init_list() { head = NULL; }
Node* get_entry(int pos)
{
	Node* p = head;
	int i;
	for (i = 0; i < pos; i++, p = p->link)
		if (p == NULL) return NULL;
	return p;
}
int size()
{
	Node* p;
	int count = 0;
	for (p = head; p != NULL; p = p->link)
		count++;
	return count;
}
void insert_next(Node* before, Node* node)
{
	if (node != NULL)
	{
		node->link = before->link;
		before->link = node;
	}
}
void insert(int pos, Element e)
{
	Node* new_node, * prev;

	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = e;
	new_node->link = NULL;

	if (pos == 0)
	{
		new_node->link = head;
		head = new_node;
	}
	else
	{
		prev = get_entry(pos - 1);
		if (prev != NULL)
			insert_next(prev, new_node);
		else
			free(new_node);
	}
}
void print_list()
{
	Node* p;
	int i = 0;
	for (p = head; p != NULL; p = p->link, i++)
	{
		printf("노드 #%d 데이터 : %d\n", (i + 1), p->data);
	}
}
int sum()
{
	Node* p = head;
	int sum = 0;
	while (p != NULL)
	{
		sum += p->data;
		p = p->link;
	}
	return sum;
}
void main()
{
	init_list();

	insert(0, 5);
	insert(1, 6);
	insert(2, 7);

	printf("노드의 개수 : %d\n", size());
	print_list();
	printf("연결 리스트의 데이터 합 : %d\n", sum());
}