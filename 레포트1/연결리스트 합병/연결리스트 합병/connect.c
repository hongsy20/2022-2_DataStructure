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
Node* concat(Node* a, Node* b)
{
	Node* first, * second;
	first = a;
	second = first;
	a = a->link;
	while (a != NULL && b != NULL)
	{
		second->link = a;
		second = a;
		a = a->link;
	}
	if (a == NULL)
		second->link = b;

	return first;
}
void concat_print_list(Node* h)
{
	Node* p = h;
	int i = 0;
	for (p = h; p != NULL; p = p->link, i++)
	{
		printf("노드 #%d 데이터 : %d\n", (i + 1), p->data);
	}
}
void main()
{
	init_list();
	insert(0, 10);
	insert(1, 20);
	insert(2, 30);
	printf("*** 연결 리스트 a ***\n");
	print_list();
	Node* a = head;

	init_list();
	insert(0, 40);
	insert(1, 50);
	insert(2, 60);
	printf("\n*** 연결 리스트 b ***\n");
	print_list();
	Node* b = head;

	printf("\n*** 두 개의 연결 리스트 합병 ***\n");
	Node* result = concat(a, b);
	concat_print_list(result);

}