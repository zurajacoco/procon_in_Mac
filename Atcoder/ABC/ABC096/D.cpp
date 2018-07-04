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

bool p[55556];
vector<int> num;

void prime() {
  rep(i, 55556) p[i] = true;
  p[0] = p[1] = false;
  repl(i, 2, 55556) if(p[i]) {
    int j = i + i;
    while(j < 55556) {
      p[j] = false;
      j += i;
    }
  }
  rep(i, 55556) if(p[i] && i % 5 == 1) num.pb(i);
}

int main() {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  prime();
  rep(i, n) cout << num[i] << ((i == n - 1) ? '\n' : ' ');
  return 0;
}
