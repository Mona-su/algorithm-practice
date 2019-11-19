// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;

const int N = (int) 505, mod = (int) 0;
string s[N];
int a[N][N];
int main() {
	int tc;
	cin >> tc;
	for (int tt = 1; tt <= tc; ++tt) {
		cout << "Case #" << tt << ": ";
		int n, res = 1e9;
		cin >> n;
		for (int j = 0; j < n; ++j) {
			cin >> s[j];
		}
		for (int st0 = 0; st0 <= 1; ++st0) {
			for (int st1 = 0; st1 <= 1; ++st1) {
				for (int j = 0; j < n; ++j) {
					for (int i = 0; i < n; ++i)
						a[j][i] = (s[j][i] == '#');
				}
				int cur = st0 + st1;
				if (st0) for (int j = 0; j < n; ++j) a[j][j] ^= 1;
				if (st1) for (int j = 0; j < n - 1; ++j) a[j][j + 1] ^= 1;
				for (int sum = 0; sum < 2 * n - 1; ++sum) {
					if (!a[sum / 2][sum / 2 + (sum & 1)]) {
						++cur;
					
						for (int j = 0; j <= sum; ++j) {
							int x = j, y = sum - j;
							if (x >= 0 && y >= 0 && x < n && y < n) {
								a[x][y] ^= 1;
							}
						}
					}
				}
				for (int row = 1; row < n; ++row) {
					if (!a[row][0]) {
						for (int j = 0; j < n; ++j) {
							int x = row + j, y = j;
							if (x >= n) break;
							a[x][y] ^= 1;
						}
						++cur;
					}
				}
				for (int col = 2; col < n; ++col) {
					if (!a[0][col]) {
						for (int j = 0; j < n; ++j) {
							int x = j, y = col + j;
							if (y >= n) break;
							a[x][y] ^= 1;
						}
						++cur;
					}
				}
				int found = 1;
				for (int x = 0; x < n; ++x)
					for (int y = 0; y < n; ++y)
						found &= a[x][y];
				if (found) {
					res = min(res, cur);	
				}
			}
		}
		cout << res << '\n';
	}
}

















