#include <stdio.h> 
#include <stdlib.h>

int mark[65];

void draw_tree(int row, int left, int right);
void arrow(int* row, int left, int right);

int main(void)
{
	draw_tree(6, 1, 65);
	return 0;
}

void draw_tree(int row, int left, int right)
{
	if (row == 0)
		return;
	for (int i = 0; i < 64; i++)
		mark[i] = 0;
	int x = 32;
	int next = 32;
	for (int i = 0; i < 6 - row; i++)
		x /= 2;
	for (int i = 0; i < 5 - row; i++)
		next /= 2;
	mark[x] = 1;
	while (x + next < 64)
	{
		x += next;
		mark[x] = 1;
	}
	arrow(mark, left, right);
	draw_tree(--row, left, right);
}

void arrow(int* row, int left, int right)
{
	for (int i = left; i < right; i++)
		if (mark[i])
			printf("X");
		else
			printf("-");
	printf("\n");
}

/*
#include <stdio.h>
#include <stdlib.h>

int mark[65]; // �� ���� �����ϴ� �迭 ����

void draw_tree(int row, int left, int right); // draw_tree �Լ� ����
void arrow(int* row, int left, int right); // arrow �Լ� ����

int main(void) // main �Լ� ����
{
	draw_tree(6, 1, 65); // draw_tree �Լ��� ������ �Ķ���Ϳ� ���� �����Ͽ� draw_tree �Լ� ȣ��
	return 0; // 0���� �� ��ȯ �� �����Լ� ����
}

void draw_tree(int row, int left, int right) // draw_tree �Լ� ����
{
	if (row == 0) // ���� row���� 0�̸�
		return; // ��ȯ�ϴ� ���� �����Ƿ� draw_tree ����
	for (int i = 0; i < 64; i++) // i�� 0���� 63���� 1�� �����ϴ� ����
		mark[i] = 0; // �迭 �ʱ�ȭ
	int x = 32; // x = 32�� ���� ���� �� �ʱⰪ ����
	int next = 32; // next = 32�� ���� ���� �� �ʱⰪ ����
	for (int i = 0; i < 6 - row; i++) // for�� �����ϴ� ����
		x /= 2; // �ʱ� x ��ġ ����
	for (int i = 0; i < 5 - row; i++) // for�� �����ϴ� ����
		next /= 2; // ���� next ��ġ ����
	mark[x] = 1; 
	while (x + next < 64) // �ʱ� ��ġ + ���� ��ġ < 64�� ���� (�� �� �ٿ� 63������ mark ��� ����)
	{
		x += next; // �ʱ� ��ġ�� ���� ��ġ�� ���Ͽ� ��� ����
		mark[x] = 1; // ���� ��ġ�� ǥ��
	}
	arrow(mark, left, right); // arrow �Լ� ȣ��
	draw_tree(--row, left, right); // draw_tree �Լ� ȣ��
}

void arrow(int* row, int left, int right) // arrow �Լ� ����
{
	for (int i = left; i < right; i++) // ���ʿ��� �����ؼ� ������ ������ ���� ����
		if (mark[i]) // ���� mark[i] �� 0�� �ƴϸ�
			printf("X"); // X ���
		else // �׷��� ������
			printf("-"); // - ���
	printf("\n"); // �ٹٲ�
}
*/