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
  rep(i, a) { cout << v[i] << ((i < a - 1) ? ' ' : '\n'); }
#define maxch(x, y) x = max(x, y)
#define minch(x, y) x = min(x, y)
#define uni(x) x.erase(unique(all(x)), x.end())
#define exist(x, y) (find(all(x), y) != x.end())
#define bcnt(x) bitset<32>(x).count()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define INF INT_MAX / 3

string toArray(string a, string b) {
  if (a.size() == 0 || b.size() == 0) return "";
  int pr, qr, pi, pj, qi, qj;
  {
    int l = 1, i = 1;
    string s = a;
    while (l > 0 && i < s.size()) {
      if (s[i] == '(')
        l++;
      else if (s[i] == ')')
        l--;
      i++;
    }
    int j = i + 1, r = 0;
    while ('0' <= s[j] && s[j] <= '9') {
      r = r * 10 + (s[j] - '0');
      j++;
    }
    pr = r, pi = i, pj = j;
  }
  {
    int l = 1, i = 1;
    string s = b;
    while (l > 0 && i < s.size()) {
      if (s[i] == '(')
        l++;
      else if (s[i] == ')')
        l--;
      i++;
    }
    int j = i + 1, r = 0;
    while ('0' <= s[j] && s[j] <= '9') {
      r = r * 10 + (s[j] - '0');
      j++;
    }
    qr = r, qi = i, qj = j;
  }
  string ret = "(";
  ret += toArray(a.substr(1, pi - 2), b.substr(1, qi - 2));
  ret += ")[" + to_string(pr + qr) + "](";
  ret += toArray(a.substr(pj + 2, a.size() - pj - 3),b.substr(qj + 2, b.size() - qj - 3));
  return ret + ")";
}

int main() {
  cin.sync_with_stdio(false);
  string a, b;
  cin >> a >> b;
  cout << toArray(a, b) << endl;
  return 0;
}
