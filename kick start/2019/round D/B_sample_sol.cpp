#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int h[N], n, g, m;
char c[N];

void read_input() {
  scanf("%d %d %d", &n, &g, &m);
  for (int i = 0; i < g; ++i) {
    scanf("%d %s", h+i, c+i);
    h[i] %= n;
  }
}
int lef[N], rig[N];
int cntl[N], cntr[N];

void solve() {
//初始化，将最后一分钟每个group的位置放进去
  fill(lef, lef+n, -1);
  fill(rig, rig+n, -1);
  for (int i = 0; i < g; ++i) {
    if (c[i] == 'C') {
      int now = (h[i] + m) % n;
      rig[now] = m;
    }
    else {
      int now = (h[i] - m) % n;
      if (now < 0)
        now += n;
      lef[now] = m;
    }
  }
//更新经过的点，找到不是最后一分钟访问的点在第几分钟存下来了记忆
  int cur = -1;
  for (int i = 0; i < 2 * n; ++i) {
    cur = max(cur-1, lef[i % n]);
    lef[i % n] = cur;
  }
  cur = -1;
  for (int i = 2 * n-1; i >= 0; --i) {
    cur = max(cur-1, rig[i % n]);
    rig[i % n] = cur;
  }
//找到哪些（初始位置+方向）的group被记住了，被记住就+1
  fill(cntl, cntl+n, 0);
  fill(cntr, cntr+n, 0);
  for (int i = 0; i < n; ++i) {
    int res = max(lef[i], rig[i]);
    if (res < 0) continue;
    if (lef[i] == res) {
      int pos = (i + res) % n;
      ++cntl[pos];
    }
    if (rig[i] == res) {
      int pos = (i - res) % n;
      if (pos < 0)
        pos += n;
      ++cntr[pos];
    }
  }
//每个顾客看他的初始位置和方向就可以找到他
  for (int i = 0; i < g; ++i) {
    int ans = 0;
    if (c[i] == 'C') {
      ans = cntr[h[i] % n];
    }
    else {
      ans = cntl[h[i] % n];
    }
    printf("%d%c", ans, i+1 == g ? '\n' : ' ');
  }
}

int main() {
#ifdef LOCAL
  time_t starttime = clock();
#endif
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    printf("Case #%d: ", tc);
    read_input();
    solve();
#ifdef LOCAL
    cerr << "~ TC#" << tc << " done! execution time: " <<
      (double)(clock()-starttime) / CLOCKS_PER_SEC << " s" << endl;
#endif
  }
  return 0;
}
