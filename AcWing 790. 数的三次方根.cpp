#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double x;
	cin >> x;
	double l = -10000, r = 10000;
	while (r - l > 1e-8)
	{
		double mid = (l + r) / 2;
		if (mid * mid * mid >= x) r = mid;
		else l = mid;
	}
	cout << fixed << setprecision(6) << l << endl;
	return 0;
}
