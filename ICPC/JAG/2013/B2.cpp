#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define repr(i, a, b) for (int i = (int)(a - 1); i >= b; i--)
#define rep(i, n) repl(i, 0, n)
#define each(itr, v) for (auto itr : v)
#define pb(s) push_back(s)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cout << #x " = " << x << endl
#define dbgv(i, a, v) \
  rep(i, a) { cout << v[i] << ((i == a - 1 ? '\n' : ' ')); }
#define maxch(x, y) x = max(x, y)
#define minch(x, y) x = min(x, y)
#define uni(x) x.erase(unique(all(x)), x.end())
#define exist(x, y) (find(all(x), y) != x.end())
#define bcnt(x) bitset<32>(x).count()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define INF INT_MAX / 3

int main() {
  cin.sync_with_stdio(false);
  int w;
  cin >> w;
  int a[w] = {}, r[w] = {}, l[w] = {};
  vector<int> in, ex, dr;
  ex.pb(-1);
  rep(i, w) {
    cin >> a[i];
    r[i] = l[i] = INF;
    if (a[i] > 0) in.pb(i);
    if (a[i] == 0) ex.pb(i);
    if (a[i] < 0) dr.pb(i);
  }
  if (ex.size() == 1) {
    cout << 0 << endl;
  } else {
    ex.pb(w);
    rep(i, ex[1]) l[i] = -1;
    repl(i, 1, ex.size() - 1) {
      l[ex[i]] = -1;
      int t = INF;
      repl(j, ex[i] + 1, ex[i + 1]) {
        if (a[j] < 0) {
          if (t >= abs(a[j])) t = abs(a[j]) - 1;
        }
        l[j] = t;
        t = max(t - 1, -1);
      }
    }
    repr(i, w, ex[ex.size() - 2] + 1) r[i] = -1;
    repr(i, ex.size() - 1, 1) {
      r[ex[i]] = -1;
      int t = INF;
      repr(j, ex[i], ex[i - 1] + 1) {
        if (a[j] < 0) {
          if (t >= abs(a[j])) t = abs(a[j]) - 1;
        }
        r[j] = t;
        t = max(t - 1, -1);
      }
    }
    int ans = 0;
    rep(i, w) {
      if (a[i] > 0) ans += min(a[i] - 1, max(r[i], l[i])) + 1;
    }
    cout << ans << endl;
  }
  return 0;
}
