#include <stdio.h>

long fibonacci(long n)
{
	if (n < 2)
		return n; 
	else
	{
		long a, b = 1, c = 0;
		for (long i = 2; i <= n; i++)
		{
			a = b;
			b += c;
			c = a;   
		}
		return b;
	}
}
int main(void)
{
	long n = 0, result;  

	do
	{
		result = fibonacci(n); 
		printf("fibonacci = %d\n", result); 
		n++;
	} while (result >= 0); 
	
	return 0;
}
