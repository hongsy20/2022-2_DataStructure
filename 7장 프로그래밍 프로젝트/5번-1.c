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
