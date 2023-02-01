#include <stdio.h>

void print_array(int a[], int len);

void main()
{
	int array[10] = { 1,2,3,4,5,6,7,8,9,10 };
	print_array(array, 10);
}

void print_array(int a[], int len)
{
	for(int i = 0; i<len; i++)
		printf("%d\n", &a[i]);
}