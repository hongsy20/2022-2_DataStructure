#include <stdio.h>

void main()
{
	int num;
	scanf("%d", &num);
	int* arr = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
		scanf("%d", arr + i); //arr + i == &arr[i]
	for (int i = 0; i < num; i++)
		printf("%d\n", *(arr + i)); //*(arr + i) == arr[i]
}