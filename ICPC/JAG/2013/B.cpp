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
#define maxch(x, y) x = max(x, y)
#define minch(x, y) x = min(x, y)
#define uni(x) x.erase(unique(all(x)), x.end())
#define exist(x, y) (find(all(x), y) != x.end())
#define bcnt(x) bitset<32>(x).count()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define INF INT_MAX / 3

set<int> v[100000];
int minds[100000], mindt[100000];
ll cnt[2][100000];

int main() {
  cin.sync_with_stdio(false);
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  s--, t--;
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    v[x].insert(y);
    v[y].insert(x);
  }
  rep(i, n) minds[i] = mindt[i] = INF;
  queue<P> qs, qt;
  qs.push(P(s, 0));
  while (qs.size()) {
    P p = qs.front();
    qs.pop();
    if (minds[p.fi] < INF) continue;
    minds[p.fi] = p.se;
    each(itr, v[p.fi]) if (minds[itr] == INF) qs.push(P(itr, p.se + 1));
  }
  qt.push(P(t, 0));
  while (qt.size()) {
    P p = qt.front();
    qt.pop();
    if (mindt[p.fi] < INF) continue;
    mindt[p.fi] = p.se;
    each(itr, v[p.fi]) if (mindt[itr] == INF) qt.push(P(itr, p.se + 1));
  }
  int st = minds[t];
  rep(i, n) {
    if (minds[i] < st) cnt[0][minds[i]]++;
    if (mindt[i] < st) cnt[1][mindt[i]]++;
  }
  ll ans = 0;
  rep(i, st - 1) { ans += cnt[0][i] * cnt[1][st - 2 - i]; }
  cout << ans << endl;
  return 0;
}
