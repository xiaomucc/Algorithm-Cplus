#include <iostream>
using namespace std;
const int N = 100010;

int nums[N];
int n, k;

int quickSortFindK(int left, int right, int k)
{
	if (left >= right) return nums[left];
	int l = left - 1, r = right + 1, num = nums[right + left >> 1];
	while (l < r)
	{
		do l++; while (nums[l] < num);
		do r--; while (nums[r] > num);
		if (l < r) swap(nums[l], nums[r]);
	}
	int s = r - left + 1;
	if (s >= k) return quickSortFindK(left, r, k);
	return quickSortFindK(r + 1, right, k - s);
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> nums[i];
	cout << quickSortFindK(0, n - 1, k);
	return 0;
}
