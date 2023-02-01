#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR_PER_LINE 1000

typedef struct Line {
	char str[MAX_CHAR_PER_LINE];
} Line;
typedef Line Element;

typedef struct LinkedNode {
	Element data;
	struct LinkedNode* link;
} Node;
Node* head;

void init_list() { head = NULL; }
int is_empty() { return head == NULL; }

Node* get_entry(int pos)
{
	Node* p = head;
	int i;
	for (i = 0; i < pos; i++, p = p->link)
		if (p == NULL)
			return NULL;
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

void replace(int pos, Element e)
{
	Node* node = get_entry(pos);
	if (node != NULL)
		node->data = e;
}

void insert_next(Node* prev, Node* node)
{
	if (node != NULL) {
		node->link = prev->link;
		prev->link = node;
	}
}

void insert(int pos, Element val)
{
	Node* new_node, * prev;
	new_node = (Node*)malloc(sizeof(Node));
	new_node->data = val;
	new_node->link = NULL;

	if (pos == 0) {
		new_node->link = head;
		head = new_node;
	}
	else {
		prev = get_entry(pos - 1);
		if (prev != NULL)
			insert_next(prev, new_node);
		else free(new_node);
	}
}

Node* remove_next(Node* prev)
{
	Node* removed = prev->link;
	if (removed != NULL)
		prev->link = removed->link;
	return removed;
}

void delete(int pos)
{
	Node* prev, * removed;
	if (pos == 0 && is_empty() == 0) {
		removed = head;
		head = head->link;
		free(removed);
	}
	else {
		prev = get_entry(pos - 1);
		if (prev != NULL) {
			removed = remove_next(prev);
			free(removed);
		}
	}
}

void display(FILE* fp)
{
	int i = 0;
	Node* p;
	for (p = head; p != NULL; p = p->link, i++) {
		fprintf(stderr, "%3d: ", i);
		fprintf(fp, "%s", p->data.str);
		printf("\n");
	}
}

void my_fflush() { while (getchar() != '\n'); }

// 데이터 검색하는 f 옵션 추가
void find(Element e)
{
	Node* p;
	int counter = 0;

	for (p = head; p != NULL; p = p->link)
	{
		if (strcmp(p->data.str, e.str) == 0)
		{
			printf("검색데이터: %s, 행 번호 : %d\n", e.str, counter);
			break;
		}
		counter++;
	}
	if (p == NULL)
	{
		printf("찾을 수 없음\n");
	}
}

void main()
{
	char command;
	int pos;
	char user;
	Line line;
	FILE* fp;

	init_list();

	do {
		// f-검색 옵션 추가
		printf("[메뉴선택] i-입력, d-삭제, r-변경, p-출력, f-검색, l-파일읽기, s-저장, q-종료=>");
		command = getchar();

		switch (command)
		{
		case 'i':
			printf(" 입력행 번호: ");
			scanf("%d", &pos);
			printf(" 입력행 내용: ");
			my_fflush();
			fgets(line.str, MAX_CHAR_PER_LINE, stdin);
			// 값을 받을 때, fgets() 함수에서 개행문자 제거
			line.str[strlen(line.str) - 1] = '\0';
			insert(pos, line);
			break;
		case 'd':
			printf(" 삭제행 번호: ");
			scanf("%d", &pos);
			delete(pos);
			break;
		case 'r':
			printf(" 변경행 번호: ");
			scanf("%d", &pos);
			printf(" 변경행 내용: ");
			my_fflush();
			fgets(line.str, MAX_CHAR_PER_LINE, stdin);
			replace(pos, line);
			break;
		case 'f':
			printf("  검색할 데이터: ");
			my_fflush();
			fgets(line.str, MAX_CHAR_PER_LINE, stdin);
			// 값을 받을 때, fgets() 함수에서 개행문자 제거
			line.str[strlen(line.str) - 1] = '\0';
			find(line);
			break;
		case 'l':
			fp = fopen("Test.txt", "r");
			if (fp != NULL) {
				while (fgets(line.str, MAX_CHAR_PER_LINE, fp))
					insert(size(), line);
				fclose(fp);
			}
			break;
		case 's':
			fp = fopen("Test.txt", "w");
			if (fp != NULL) {
				display(fp);
				fclose(fp);
			}
		case 'p':
			display(stdout);
		}
		my_fflush();
	} while (command != 'q');
}