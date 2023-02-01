#include <stdio.h>

void print_address(int* px);
int main(void)
{
	int num = 10;
	printf("%d, %d\n", num, &num);
	print_address(&num);

	return 0;
}

void print_address(int* px)
{
	printf("%d, %d\n", *px, px);
}