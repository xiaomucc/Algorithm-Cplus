#include <iostream>
using namespace std;
const int N = 100010;

int nums[N];
int n;

void quickSort(int left, int right)
{
	if (left >= right) return;
	int l = left - 1, r = right + 1, num = nums[left + ((right - left) >> 1)];
	while (l < r)
	{
		do l++; while (nums[l] < num);
		do r--; while (nums[r] > num);
		if (l < r) swap(nums[l], nums[r]);
	}
	quickSort(left, l);
	quickSort(l + 1, right);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> nums[i];
	quickSort(0, n - 1);
	for (int i = 0; i < n; i++) cout << nums[i] << " ";
	return 0;
}
