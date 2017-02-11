#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long ll;
const ll maxN = 2005;
const ll P = 31;
ll p[maxN];
ll n, m, k;
vector<ll> h;

int main() {
  freopen("bacon.in", "r", stdin);
  freopen("bacon.out", "w", stdout);
  ll hash, i, j;
  string s;
  cin >> s;
  n = s.size();
  p[0] = 1;
  for (i = 1; i <= n; i++) {
    p[i] = p[i - 1] * P;
  }
  for (i = 0; i < n; i++) {
    hash = 0;
    for (j = 0; j + i < n; j++) {
      hash += (s[j + i] - 'a' + 1) * p[j];
      h.push_back(hash);
    }
  }
  sort(h.begin(), h.end());
  int sum = 0;
  for (i = 0; i < h.size(); i++) {
    if (h[i] != h[i + 1]) {
      sum++;
    }
  }
  cout << sum << endl;
  return 0;	
}