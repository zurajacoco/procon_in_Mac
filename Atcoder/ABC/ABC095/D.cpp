#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define repr(i,a,b) for(int i=(int)(a-1);i>=b;i--)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x" = " << x << endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt(x) bitset<32>(x).count()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define INF INT_MAX/3

int main() {
  cin.sync_with_stdio(false);
  ll n, c;
  cin >> n >> c;
  ll x[n + 2], v[n + 2];
  x[0] = v[0] = v[n + 1] = 0;
  x[n + 1] = c;
  repl(i, 1, n + 1) cin >> x[i] >> v[i];
  P r[n + 2], l[n + 2];
  r[0] = l[n + 1] = P(0, 0);
  repl(i, 1, n + 2) {
    r[i].fi = r[i - 1].fi + v[i] - (x[i] - x[i - 1]);
    l[n + 1 - i].fi = l[n + 2 - i].fi + v[n + 1 - i] - (x[n + 2 - i] - x[n + 1 - i]);
    r[i].se = l[i].se = i;
  }
  repl(i, 1, n + 2) {
    if (r[i].fi < r[i - 1].fi) {
      r[i] = r[i - 1];
    }
    if (l[n + 1 - i].fi < l[n + 2 - i].fi) {
      l[n + 1 - i] = l[n + 2 - i];
    }
  }
  ll ans = 0;
  rep(i, n + 1) {
    maxch(ans, r[i].fi + l[i + 1].fi - min(x[r[i].se], c - x[l[i + 1].se]));
  }
  cout << ans << endl;
  return 0;
}
