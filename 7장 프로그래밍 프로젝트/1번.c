#include <stdio.h>
#include <stdlib.h>

int count = 0; // count ���� ���� ���� �� �ʱ�ȭ (fibo �Լ� ȣ�� ���� ����)

int fibo(int n) { // fibo �Լ� ���� (�Ǻ���ġ���� ��� �� ���ȣ�� �Լ�)
	count++; // count 1�� ���� (�Լ��� ȣ��� �� ����  ȣ�� Ƚ�� ����)

	if (n == 0) // ���� n�� 0�̸�
		return 0; // ���� 0���� ��ȯ
	else if (n == 1) // ���� n�� 1�̸�
		return 1; // ���� 1�� ��ȯ
	else return (fibo(n - 2) + fibo(n - 1)); // �׷��� ������ n�� ���� �����Ͽ� ����Լ� ȣ��
}

int main(void) { // main �Լ� ����
	int num; // num: �Է¹��� ���ڸ� �����ϴ� ����
	int result; // result: fibo�Լ��� ������ ������� �����ϴ� ����

	count = 0; // count: �Ǻ���ġ���� ����Լ� ȣ�� Ƚ�� ī��Ʈ ���� �ʱ�ȭ

	printf("���ڸ� �Է��ϼ���. "); // ���ڸ� �Է¹ޱ� ���� ���� ���
	scanf_s("%d", &num); // ���� �Է� �ޱ�

	printf("n=%d�� �־��� ��\n", num);  // �Է¹��� �� ���

	for (int i = 1; i <= num; i++) { // i�� num���� 1�� �����Ͽ� �ݺ��� ����
		result = fibo(i); // result�� fibo�Լ��� ������ �� ����
		printf("Fibo(%d)=%d => %d��\n", i, result, count); // �Լ��� ��갪 �� Ƚ�� ���
		count = 0; // �Ǻ���ġ������ ��� ���� �޾����Ƿ� �������� count�� �ʱ�ȭ
	}

	return 0; // ���� 0���� ��ȯ�ϰ� main �Լ� ����

}