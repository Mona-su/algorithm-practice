#include <iostream>

using namespace std;

int main() {
	double ans, temp = 5.0;
	ans = 1 / temp;
	cout << ans << endl;

	int i;
	if ((i = 3) != 5)
		cout << "**" << endl;

	int a[5] = {0};
	a[4]++;
	fill(a, a+5, 0);
	for (int i = 0; i < 5; ++i)
	{
		/* code */
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}