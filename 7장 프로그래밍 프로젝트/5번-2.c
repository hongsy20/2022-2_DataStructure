#include <stdio.h>
#define ROW 6 
#define WIDTH 70 

char draw_X[ROW][WIDTH]; 

void init();
void draw_tree(int row, int left, int right); 
void display(char arr[ROW][WIDTH], int width);

int main(void)
{
	init(); 
	draw_tree(0, 0, 64); 
	display(draw_X, 64);

	return 0;
}

void init()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < WIDTH; j++)
			draw_X[i][j] = '-';
	}
}
void draw_tree(int row, int left, int right)
{
	if (right - left < 2) return;

	int mid = (right + left) / 2; 

	draw_X[row][mid] = 'X';
	draw_tree(row + 1, left, mid); 
	draw_tree(row + 1, mid, right); 
 
}
void display(char arr[ROW][WIDTH], int width)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < width; j++)
			printf("%c", draw_X[i][j]);
		printf("\n");
	}
}
