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
int counter(int num)
{
	Node* p = head;
	int count = 0;
	while (p != NULL)
	{
		if (p->data == num)
			count++;
		p = p->link;
	}
	return count;
}
void main()
{
	int user;
	init_list();

	insert(0, 5);
	insert(1, 5);
	insert(2, 7);

	printf("노드의 개수 : %d\n", size());
	print_list();
	printf("탐색할 값을 입력하시오: ");
	scanf("%d", &user);
	printf("%d는 연결 리스트에서 %d번 나타납니다.\n", user, counter(user));
}