#include <stdio.h>
#include <stdlib.h>

void reverse(char s[100]);

int main(void)
{
	char user[100]; // 사용자로부터 입력받은 문자열을 저장할 배열
	gets(user); // scanf("%s", user); 로 사용해도 가능
	reverse(user); // 문자열을 뒤집는 함수 호출
	printf("\n");

	return 0;
}

void reverse(char *s)
{
	if (*s == '\0') // 문자열의 끝이라면,
		return; // 함수 종료
	reverse(s + 1); // reverse 함수를 호출하면서 문자의 끝으로 감
	printf("%c", *s); // 함수가 종료되고 실행->끝에서부터 한 문자씩 출력
}