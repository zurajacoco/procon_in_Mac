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

vector<int> edge[100001];
bool visited[100001];

set<int> bfs(int v) {
  set<int> ret;
  queue<int> q;
  q.push(v);
  while (q.size()) {
    int u = q.front();
    q.pop();
    if (visited[u]) continue;
    visited[u] = true;
    ret.insert(u);
    rep(i, edge[u].size()) if (!visited[edge[u][i]]) { q.push(edge[u][i]); }
  }
  return ret;
}

int main() {
  cin.sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  int p[n];
  rep(i, n) cin >> p[i];
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    edge[x].pb(y), edge[y].pb(x);
  }
  int ans = 0;
  repl(i, 1, n + 1) if (!visited[i]) {
    set<int> s = bfs(i);
    each(itr, s) if (s.count(p[itr - 1])) ans++;
  }
  cout << ans << endl;
  return 0;
}
