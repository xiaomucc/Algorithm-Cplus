#include <iostream>
using namespace std;
const int N = 100010;

int heap[N], hp[N], ph[N];//hp[k]是堆中第k个数是第几个插入的，ph[k]是第k个插入的数的下标
int m, n, k, x, length;

void heapSwap(int a, int b)//传入堆中下标
{
	swap(ph[hp[a]], ph[hp[b]]);
	swap(hp[a], hp[b]);
	swap(heap[a], heap[b]);
}

void heapUp(int idx)
{
	if (idx / 2 == 0 || heap[idx] >= heap[idx / 2]) return;
	heapSwap(idx, idx / 2);
	heapUp(idx / 2);
}

void heapInsert(int x)
{
	hp[++length] = ++m;
	ph[m] = length;
	heap[length] = x;
	heapUp(length);
}

void heapDown(int idx)
{
	int min = idx * 2;
	if (min > length) return;
	if (min + 1 <= length) min = heap[min] < heap[min + 1] ? min : min + 1;
	if (heap[min] > heap[idx]) return;
	heapSwap(idx, min);
	heapDown(min);
}

int main()
{
	cin >> n;
	string op;
	while (n--)
	{
		cin >> op;
		if (op == "I")
		{
			cin >> x;
			heapInsert(x);
		}
		else if (op == "PM")
		{
			cout << heap[1] << endl;
		}
		else if (op == "DM")
		{
			heapSwap(1, length);
			length--;
			heapDown(1);
		}
		else if (op == "D")
		{
			cin >> k;
			k = ph[k];
			heapSwap(k, length);
			length--;
			heapDown(k);
			heapUp(k);
		}
		else
		{
			cin >> k >> x;
			k = ph[k];
			heap[k] = x;
			heapDown(k);
			heapUp(k);
		}
	}
	return 0;
}
