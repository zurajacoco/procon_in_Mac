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
typedef pair<int, int> P;

#define INF INT_MAX/3

int main() {
  cin.sync_with_stdio(false);
  int n, m, t;
  cin >> n >> m >> t;
  int v[t + 1];
  memset(v, 0, sizeof(v));
  rep(i, n) {
    int a;
    cin >> a;
    v[max(0, a - m)]++;
    v[min(t, a + m)]--;
  }
  int ans = 0;
  repl(i, 1, t + 1) {
    v[i] += v[i - 1];
    if (v[i] == 0) ans++;
  }
  cout << ans << endl;
  return 0;
}
