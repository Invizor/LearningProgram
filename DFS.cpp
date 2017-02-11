#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

vector<vector<int> >g(100005);

int us[100005];

int tIn[100005], tOut[100005], tim=0, zap, q, p;

void dfs (int ver){
  int i, j;
  us[ver] = 1;
  tIn[ver] = tim++;
  for (i = 0; i < g[ver].size(); i++) {
    if (us[g[ver][i]] == 0){
      dfs (g[ver][i]);
    }
  }
  tOut[ver] = tim++;
} 

int main(){
  int n, j, k, z, m;
  freopen("ancestor.in", "r", stdin);
  freopen("ancestor.out", "w", stdout);
  cin >> n;
  for ( j = 1; j <= n; j++) {
    us[j] =  0;
  }
  us[0] = 1;
  for (j = 1; j <= n; j++) {
    cin >> z;
    if (z == 0){
      zap = j;
    }
    g[z].push_back(j);
  }
  dfs(zap);
  cin >> m;
  for (j = 1; j <= m; j++) {
    cin >> q >> p;
    if (tIn[q] < tIn[p] && tOut[q] > tOut[p]) {
      cout << 1 << endl;
    }
    else {
      cout << 0 << endl;
    }
  }
  return 0;
}