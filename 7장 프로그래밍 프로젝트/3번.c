#include <stdio.h>
#include <stdlib.h>

void reverse(char s[100]);

int main(void)
{
	char user[100]; // ����ڷκ��� �Է¹��� ���ڿ��� ������ �迭
	gets(user); // scanf("%s", user); �� ����ص� ����
	reverse(user); // ���ڿ��� ������ �Լ� ȣ��
	printf("\n");

	return 0;
}

void reverse(char *s)
{
	if (*s == '\0') // ���ڿ��� ���̶��,
		return; // �Լ� ����
	reverse(s + 1); // reverse �Լ��� ȣ���ϸ鼭 ������ ������ ��
	printf("%c", *s); // �Լ��� ����ǰ� ����->���������� �� ���ھ� ���
}