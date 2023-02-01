#include <stdio.h> 

int Ackermann(int m, int n)
{
	if (m == 0)
	{
		return (n + 1);
	}
	else if (m > 0 && n == 0)
	{
		return Ackermann(m - 1, 1);
	}
	else 
	{
		return Ackermann(m - 1,Ackermann(m,n-1));
	}
}
	
int main(void)
{
	for(int i=0; i<4; i++)
		for (int j = 0; j < 5; j++)
		{
			
			printf("A(%d,%d)ÀÇ °ª: %d\n", i, j, Ackermann(i,j));
			
		}
	return 0;
}