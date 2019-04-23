#include<stdio.h>

int N = 9;
int Heap[9] = { 7, 6, 5, 8, 3, 5, 9, 1, 6 };

int main()
{
	int i;

	//전체 트리 구조를 최대 힙으로 구성
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

	//크기를 줄여가며 반복적으로 힙을 구성한다.
	for (i = N - 1; i >= 0; i--)
	{
		//루트 노드와 트리의 마지막 노드를 교환한다.
		int tmp = Heap[0];
		Heap[0] = Heap[i];
		Heap[i] = tmp;

		//힙 조건에 위배되지 않게 하기 위해 새롭게 Heap 구조를 구성

		int root = 0;
		int c = 1;

		do
		{
			c = 2 * root + 1;

			//자식 노드 중에 더 큰 값을 찾기
			if (Heap[c] < Heap[c + 1] && c < i - 1)
			{
				c++;
			}
			//루트보다 자식 노드가 더 크다면 교환한다.
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