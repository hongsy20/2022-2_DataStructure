#include <stdio.h>
#define ROW 6 // ���� ����(=����)
#define WIDTH 70 // ���� ����

char draw_X[ROW][WIDTH]; // X�� ������ �׷� ������ �迭

void init(); // �迭�� '-'�� �ʱ�ȭ
void draw_tree(int row, int left, int right); // ���� ���Ͽ� �°� �׸�
void display(char arr[ROW][WIDTH], int width); // �׷��� ���� ���

int main(void)
{
	init(); // ���� �� �ʱ�ȭ
	draw_tree(0, 0, 64); // draw_tree(��, �� ó��, �� ��)
	display(draw_X, 64); // display(�׸� �迭, ���� ����)

	return 0;
}

void init()
{
	// ��� �迭�� '-'�� �ʱ�ȭ
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < WIDTH; j++)
			draw_X[i][j] = '-';
	}
}
void draw_tree(int row, int left, int right)
{
	// ����, right-left < 2 �̸� �߰��� �׸� �� ����. �Լ� ����
	if (right - left < 2) return;

	int mid = (right + left) / 2; // �߰� ���� ã��

	draw_X[row][mid] = 'X'; // �߰� ������ X�� ����
	draw_tree(row + 1, left, mid); // ���� Ž��
	draw_tree(row + 1, mid, right); // ������ Ž��
 
}
void display(char arr[ROW][WIDTH], int width)
{
	// ��� �迭�� ���
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < width; j++)
			printf("%c", draw_X[i][j]);
		printf("\n");
	}
}