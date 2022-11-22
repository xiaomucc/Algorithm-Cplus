#include <iostream>
using namespace std;
const int N = 100010;

int nums[N];
int n, m, x;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> nums[i];
	while (m--)
	{
		cin >> x;
		int l = 0, r = n - 1;
		while (l < r)
		{
			int mid = l + ((r - l) >> 1);
			if (nums[mid] >= x) r = mid;
			else l = mid + 1;
		}
		if (nums[l] != x) cout << "-1 -1" << endl;
		else
		{
			cout << l << " ";
			l = 0, r = n - 1;
			while (l < r)
			{
				int mid = l + ((r - l + 1) >> 1);
				if (nums[mid] <= x) l = mid;
				else r = mid - 1;
			}
			cout << l << endl;
		}
	}
	return 0;
}
