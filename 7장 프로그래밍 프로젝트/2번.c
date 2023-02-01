#include <stdio.h>

long fibonacci(long n)  //피보나치 수열 함수
{
	if (n < 2)
		return n;  //n이 2보다 작으면 n을 반환
	else
	{
		long a, b = 1, c = 0; //피보나치 수열에서 첫번째와 두번째 수는 1부터 시작
		for (long i = 2; i <= n; i++)
		{
			a = b;
			b += c;
			c = a;   //피보나치 수열 계산 식
		}
		return b;  //i 값에 따른 첫번째수와 두번째 수가 더해진 세번째 수 b를 반환
	}
}
int main(void)
{
	long n = 0, result;  //n=0, 0번째 부터 시작

	do
	{
		result = fibonacci(n); //fibonacci() 함수의 반환값 b를 result에 저장
		printf("fibonacci = %d\n", result); //n번째 result 출력
		n++;
	} while (result >= 0); //result가 양수일 때까지만 출력
	//long 자료형의 가장 큰 피보나치 수를 넘어가면 오버플로우가 발생하여 음수가 됨
	return 0;
}