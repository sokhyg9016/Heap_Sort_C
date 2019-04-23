#include<stdio.h>

int N = 9;
int Heap[9] = { 7, 6, 5, 8, 3, 5, 9, 1, 6 };

int main()
{
	int i;

	//��ü Ʈ�� ������ �ִ� ������ ����
	for (i = 1; i < N; i++)
	{
		int c = i;

		do
		{
			int root = (c - 1) / 2;
			if (Heap[root] < Heap[c])
			{
				int tmp = Heap[root];
				Heap[root] = Heap[c];
				Heap[c] = tmp;
			}
			c = root;
		} while (c != 0);
	}

	//ũ�⸦ �ٿ����� �ݺ������� ���� �����Ѵ�.
	for (i = N - 1; i >= 0; i--)
	{
		//��Ʈ ���� Ʈ���� ������ ��带 ��ȯ�Ѵ�.
		int tmp = Heap[0];
		Heap[0] = Heap[i];
		Heap[i] = tmp;

		//�� ���ǿ� ������� �ʰ� �ϱ� ���� ���Ӱ� Heap ������ ����

		int root = 0;
		int c = 1;

		do
		{
			c = 2 * root + 1;

			//�ڽ� ��� �߿� �� ū ���� ã��
			if (Heap[c] < Heap[c + 1] && c < i - 1)
			{
				c++;
			}
			//��Ʈ���� �ڽ� ��尡 �� ũ�ٸ� ��ȯ�Ѵ�.
			if (Heap[root] < Heap[c] && c < i)
			{
				int tmp = Heap[root];
				Heap[root] = Heap[c];
				Heap[c] = tmp;
			}
			root = c;
		} while (c < i);
	}

	for (i = 0; i < N; i++)
	{
		printf("%d, ", Heap[i]);
	}

	return 0;
}