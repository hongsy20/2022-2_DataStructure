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

int mark[65]; // 각 행을 저장하는 배열 선언

void draw_tree(int row, int left, int right); // draw_tree 함수 정의
void arrow(int* row, int left, int right); // arrow 함수 정의

int main(void) // main 함수 실행
{
	draw_tree(6, 1, 65); // draw_tree 함수에 각각의 파라미터에 값을 대입하여 draw_tree 함수 호출
	return 0; // 0으로 값 반환 및 메인함수 종료
}

void draw_tree(int row, int left, int right) // draw_tree 함수 구현
{
	if (row == 0) // 만약 row값이 0이면
		return; // 반환하는 값이 없으므로 draw_tree 종료
	for (int i = 0; i < 64; i++) // i가 0부터 63까지 1씩 증가하는 동안
		mark[i] = 0; // 배열 초기화
	int x = 32; // x = 32로 변수 선언 및 초기값 설정
	int next = 32; // next = 32로 변수 선언 및 초기값 설정
	for (int i = 0; i < 6 - row; i++) // for을 실행하는 동안
		x /= 2; // 초기 x 위치 설정
	for (int i = 0; i < 5 - row; i++) // for을 실행하는 동안
		next /= 2; // 다음 next 위치 설정
	mark[x] = 1; 
	while (x + next < 64) // 초기 위치 + 다음 위치 < 64일 동안 (즉 한 줄에 63개까지 mark 출력 가능)
	{
		x += next; // 초기 위치에 다음 위치를 더하여 계속 누적
		mark[x] = 1; // 다음 위치도 표시
	}
	arrow(mark, left, right); // arrow 함수 호출
	draw_tree(--row, left, right); // draw_tree 함수 호출
}

void arrow(int* row, int left, int right) // arrow 함수 구현
{
	for (int i = left; i < right; i++) // 왼쪽에서 시작해서 오른쪽 끝까지 가는 동안
		if (mark[i]) // 만약 mark[i] 가 0이 아니면
			printf("X"); // X 출력
		else // 그렇지 않으면
			printf("-"); // - 출력
	printf("\n"); // 줄바꿈
}
*/