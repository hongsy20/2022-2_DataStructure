#include <stdio.h>
#include <stdlib.h>

void reverse(char s[100]);

int main(void)
{
	char user[100]; 
	gets(user); // scanf("%s", user); 
	reverse(user); 
	printf("\n");

	return 0;
}

void reverse(char *s)
{
	if (*s == '\0')
		return;
	reverse(s + 1); 
	printf("%c", *s); 
}
