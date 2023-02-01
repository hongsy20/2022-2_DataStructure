#include <stdio.h>
#include <stdlib.h>

int count = 0; // count 전역 변수 선언 및 초기화 (fibo 함수 호출 누적 변수)

int fibo(int n) { // fibo 함수 정의 (피보나치수열 계산 및 재귀호출 함수)
	count++; // count 1씩 증가 (함수가 호출될 때 마다  호출 횟수 누적)

	if (n == 0) // 만약 n이 0이면
		return 0; // 값을 0으로 반환
	else if (n == 1) // 만약 n이 1이면
		return 1; // 값을 1로 반환
	else return (fibo(n - 2) + fibo(n - 1)); // 그렇지 않으면 n의 값을 감소하여 재귀함수 호출
}

int main(void) { // main 함수 실행
	int num; // num: 입력받은 숫자를 저장하는 변수
	int result; // result: fibo함수를 실행한 결과값을 저장하는 변수

	count = 0; // count: 피보나치수열 재귀함수 호출 횟수 카운트 변수 초기화

	printf("숫자를 입력하세요. "); // 숫자를 입력받기 위한 문장 출력
	scanf_s("%d", &num); // 숫자 입력 받기

	printf("n=%d을 넣었을 때\n", num);  // 입력받은 값 출력

	for (int i = 1; i <= num; i++) { // i를 num까지 1씩 증가하여 반복문 수행
		result = fibo(i); // result에 fibo함수를 실행한 값 저장
		printf("Fibo(%d)=%d => %d번\n", i, result, count); // 함수의 계산값 및 횟수 출력
		count = 0; // 피보나치수열의 결과 값을 받았으므로 누적변수 count값 초기화
	}

	return 0; // 값을 0으로 반환하고 main 함수 종료

}