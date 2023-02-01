#include <stdio.h>
#define ROW 6 // 행의 길이(=레벨)
#define WIDTH 70 // 가로 길이

char draw_X[ROW][WIDTH]; // X를 포함해 그려 저장할 배열

void init(); // 배열을 '-'로 초기화
void draw_tree(int row, int left, int right); // 일정 패턴에 맞게 그림
void display(char arr[ROW][WIDTH], int width); // 그려진 내용 출력

int main(void)
{
	init(); // 시작 전 초기화
	draw_tree(0, 0, 64); // draw_tree(행, 맨 처음, 맨 끝)
	display(draw_X, 64); // display(그린 배열, 가로 길이)

	return 0;
}

void init()
{
	// 모든 배열을 '-'로 초기화
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < WIDTH; j++)
			draw_X[i][j] = '-';
	}
}
void draw_tree(int row, int left, int right)
{
	// 만약, right-left < 2 이면 중간에 그릴 수 없음. 함수 종료
	if (right - left < 2) return;

	int mid = (right + left) / 2; // 중간 지점 찾기

	draw_X[row][mid] = 'X'; // 중간 지점을 X로 변경
	draw_tree(row + 1, left, mid); // 왼쪽 탐색
	draw_tree(row + 1, mid, right); // 오른쪽 탐색
 
}
void display(char arr[ROW][WIDTH], int width)
{
	// 모든 배열을 출력
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < width; j++)
			printf("%c", draw_X[i][j]);
		printf("\n");
	}
}