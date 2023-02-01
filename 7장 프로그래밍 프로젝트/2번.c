#include <stdio.h>

long fibonacci(long n)  //�Ǻ���ġ ���� �Լ�
{
	if (n < 2)
		return n;  //n�� 2���� ������ n�� ��ȯ
	else
	{
		long a, b = 1, c = 0; //�Ǻ���ġ �������� ù��°�� �ι�° ���� 1���� ����
		for (long i = 2; i <= n; i++)
		{
			a = b;
			b += c;
			c = a;   //�Ǻ���ġ ���� ��� ��
		}
		return b;  //i ���� ���� ù��°���� �ι�° ���� ������ ����° �� b�� ��ȯ
	}
}
int main(void)
{
	long n = 0, result;  //n=0, 0��° ���� ����

	do
	{
		result = fibonacci(n); //fibonacci() �Լ��� ��ȯ�� b�� result�� ����
		printf("fibonacci = %d\n", result); //n��° result ���
		n++;
	} while (result >= 0); //result�� ����� �������� ���
	//long �ڷ����� ���� ū �Ǻ���ġ ���� �Ѿ�� �����÷ο찡 �߻��Ͽ� ������ ��
	return 0;
}