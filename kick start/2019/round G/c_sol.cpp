#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[1<<20];
ll a[20], b[20];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  int cc = 1;
  while (t--) {
    cout << "Case #" << cc++ << ": ";
    ll n, h;
    cin >> n >> h;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    fill_n(dp, 1<<n, 0);
    for (int i = 0; i < 1<<n; i++) {
      ll sum = 0;
      for (int j = 0; j < n; j++) {
      	if (i>>j&1)
      	  sum += b[j];
      }
      if (sum >= h)
        dp[i]++;
    }
    for (int j = 0; j < n; j++)
      for (int i = 0; i < 1<<n; i++)
      	if (i>>j&1)
      	  dp[i^1<<j] += dp[i];
    ll ans = 0;
    for (int i = 0; i < 1<<n; i++) {
      ll sum = 0;
      for (int j = 0; j < n; j++) {
      	if (i>>j&1)
      	  sum += a[j];
      }
      if (sum >= h)
        ans += dp[(1<<n)-1-i];
    }
    cout << ans << endl;
  }
}
