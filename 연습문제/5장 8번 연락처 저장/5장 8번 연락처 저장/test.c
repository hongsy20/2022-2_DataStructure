#include <stdio.h>
typedef struct address {
	char name[30];
	char phone[30];
}Friend;

void main()
{
	int num;
	scanf("%d", &num);
	Friend* a;
	a = (Friend*)malloc(sizeof(Friend) * num);

	for (int i = 0; i < num; i++)
	{
		printf("�̸� : ");
		scanf("%s", a[i].name);
		printf("��ȣ : ");
		scanf("%s", a[i].phone);
	}

	printf("-----------------------------\n");
	for (int i = 0; i < num; i++)
	{
		printf("%s %s \n", a[i].name, a[i].phone);
	}
}