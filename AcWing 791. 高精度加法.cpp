#include <iostream>
#include <vector>
using namespace std;

vector<int> arrAdd(vector<int>& a, vector<int>& b)
{
	vector<int> ans;
	int t = 0;
	for (int i = 0; i < a.size() || i < b.size(); i++)
	{
		if (i < a.size()) t += a[i];
		if (i < b.size()) t += b[i];
		ans.push_back(t % 10);
		t /= 10;
	}
	if (t) ans.push_back(1);
	return ans;
}

int main()
{
	string a, b;
	vector<int> A, B;
	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
	for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
	auto ans = arrAdd(A, B);
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
	return 0;
}
