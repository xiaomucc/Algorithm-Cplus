#include <iostream>
using namespace std;
const int N = 100010;

int nums[N];
int n;

void merge(int left, int middle, int right)
{
	int* arr = new int[right - left + 1];
	int l = left, r = middle + 1, i = 0;
	while (l <= middle && r <= right) arr[i++] = nums[l] < nums[r] ? nums[l++] : nums[r++];
	while (l <= middle) arr[i++] = nums[l++];
	while (r <= right) arr[i++] = nums[r++];
	for (i = left; i <= right; i++) nums[i] = arr[i - left];
	delete[] arr;
}

void mergeSort(int left, int right)
{
	if (left >= right) return;
	int middle = left + ((right - left) >> 1);
	mergeSort(left, middle);
	mergeSort(middle + 1, right);
	merge(left, middle, right);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> nums[i];
	mergeSort(0, n - 1);
	for (int i = 0; i < n; i++) cout << nums[i] << " ";
	return 0;
}
