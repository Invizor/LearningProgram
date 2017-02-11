#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n, k;
vector<vector<int> > g(600);
vector<int> mt;
vector<char> used;

bool kuhn (int v) {
  if (used[v])  return false;
  used[v] = true;
  for (size_t i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    if (mt[to] == -1 || kuhn (mt[to])) {
      mt[to] = v;
      return true;
    }
  }
  return false;
}

int main() {
  freopen("pairs.in", "r", stdin);
  freopen("pairs.out", "w", stdout);
  int x, i;
  cin>>n>>k;
  for (i = 0; i < n; i++) {
    x = 1;
    while (true) {
      cin >> x;
      if (x == 0){
        break;
      }
      g[i].push_back(x - 1);
    }
  }
  mt.assign (k, -1);
  for (int i = 0; i < n; i++) {
    used.assign (n, false);
    kuhn (i);
  }
  int sum = 0;
  for (int i = 0; i < k; i++) {
    if (mt[i] != -1) {
      sum++;
    }
  }
  cout << sum << endl;
  for (int i = 0; i < k; i++) {
    if (mt[i] != -1) {
      printf ("%d %d\n", mt[i] + 1, i + 1);
    }
  }
  return 0;
}