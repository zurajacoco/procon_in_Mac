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

int main() {
  cin.sync_with_stdio(false);
  int p, q;
  cin >> p >> q;
  int t = q / __gcd(p, q);
  int ans = 1, i = 2, s = t;
  while (i < (int)sqrt(t) + 2) {
    if (s % i == 0) {
      while (s % i == 0) s /= i;
      ans *= i;
    }
    i++;
  }
  cout << ans * s << endl;
  return 0;
}
