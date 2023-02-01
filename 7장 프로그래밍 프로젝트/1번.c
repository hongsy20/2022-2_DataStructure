#include <stdio.h>
#include <stdlib.h>

int count = 0;

int fibo(int n) {
	count++;
	if (n == 0)
		return 0;
	else if (n == 1) 
		return 1; 
	else return (fibo(n - 2) + fibo(n - 1)); 
}

int main(void) { 
	int num;
	int result; 

	count = 0;

	printf("숫자를 입력하세요. ");
	scanf_s("%d", &num);

	printf("n=%d을 넣었을 때\n", num);

	for (int i = 1; i <= num; i++) {
		result = fibo(i);
		printf("Fibo(%d)=%d => %d번\n", i, result, count);
		count = 0; 
	}

	return 0;

}
