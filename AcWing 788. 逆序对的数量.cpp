#include <iostream>
using namespace std;
const int N = 100010;

int nums[N], arr[N];
int n, num;

long long mergeSort(int left, int right)
{
	if (left >= right) return 0;
	int middle = left + ((right - left) >> 1);
	long long res = mergeSort(left, middle) + mergeSort(middle + 1, right);
	int l = left, r = middle + 1, i = 0;
	while (l <= middle && r <= right)
	{
		if (nums[r] >= nums[l]) arr[i++] = nums[l++];
		else
		{
			arr[i++] = nums[r++];
			res += middle - l + 1;
		}
	}
	while (l <= middle) arr[i++] = nums[l++];
	while (r <= right) arr[i++] = nums[r++];
	for (i = left; i <= right; i++) nums[i] = arr[i - left];
	return res;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> nums[i];
	cout << mergeSort(0, n - 1);
	return 0;
}
