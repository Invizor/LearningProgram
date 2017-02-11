#include <iostream>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cassert>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxN = 150005;
int k, m, n, qw;
int p[maxN], u[maxN], v[maxN], ans[maxN], x[maxN], y[maxN], z[maxN];
char buf[maxN];
int up[maxN];
int w[maxN];

int find(int x) {
  int y = x;
  while(up[y] != y)y = up[y];
  int tmp;
  while (x != y) {
    tmp = up[x];
    up[x] = y;
    x = tmp;
  }
  return y;
}

void unionx(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y) {
    if (w[x]>w[y]) {
      up[y] = x; 
      w[x] += w[y];
    } else {
      up[x] = y;
      w[y] += w[x];
    }
  }
}

int main ()
{
  int i, j, kolvo = 0;
  //freopen ("cutting.in", "r", stdin);
 // freopen ("cutting.out", "w", stdout);
  scanf (" %d %d %d", &n, &k);
  for (i = 0; i < n; i++) {
    w[i] = 0;
    up[i] = i;
  } 
  for (i = 0; i < k; i++)
  {
    scanf (" %s %d %d", buf, &x[i], &y[i]);
    if (buf[0] == 'c') {
      unionx (x[i], y[i]);
    } else {
      if(find(x[i]) == find(y[i]))cout<<"yes"<<endl;else cout<<"no"<<endl;
    }
  }
  return 0;
}