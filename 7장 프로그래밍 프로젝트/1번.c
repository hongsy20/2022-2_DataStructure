#include <stdio.h>
#include <stdlib.h>

int count = 0; // count 전역 변수 선언 및 초기화

int fibo(int n) { 
	count++;
	
	if (n == 0) 
		return 0;
	else if (n == 1) 
		return 1;
	else return (fibo(n - 2) + fibo(n - 1));
}

int main(void) { 
	int num; // 입력받은 숫자를 저장하는 변수
	int result; // fibo함수를 실행한 결과값을 저장하는 변수
	count = 0; // 피보나치수열 재귀함수 호출 횟수 카운트 변수 초기화

	printf("숫자를 입력하세요. ");
	scanf_s("%d", &num);

	printf("n=%d을 넣었을 때\n", num);

	for (int i = 1; i <= num; i++) { 
		result = fibo(i);
		printf("Fibo(%d)=%d => %d번\n", i, result, count); 
		count = 0;
	}

	return 0;
