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

int dd[] = {1, 0, -1, 0, 1};
int h, w;
char s[50][50];

bool range(int y, int x) {
  return 0 <= y && y < h && 0 <= x && x < w;
}

int main() {
  cin.sync_with_stdio(false);
  cin >> h >> w;
  rep(i, h)rep(j, w) cin >> s[i][j];
  bool ok = true;
  rep(i, h)rep(j, w)if(s[i][j] == '#') {
    int cnt = 0;
    rep(k, 4) {
      int y = i + dd[k], x = j + dd[k + 1];
      if (range(y, x) && s[y][x] == '#') cnt++;
    }
    if (cnt == 0) ok = false;
  }
  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
