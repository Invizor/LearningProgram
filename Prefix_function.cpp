#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> pik(50005);

void prefix_functionk(string s) {
  int n = s.length(), i, j;
  for (i = 1; i < n; i++) {
    j = pik[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = pik[j - 1];
    }
    if (s[i] == s[j]) {
      j++;
    }
    pik[i] = j;
  }
}

vector<int> pim(50005);

void prefix_functionm(string s) {
  int n = s.length(), i, j;
  for (i = 1; i < n; i++) {
    j = pim[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = pim[j - 1];
    }
    if (s[i] == s[j]) {
      j++;
    }
    pim[i] = j;
  }
}
int main() {
  //freopen("basis.in", "r", stdin);
  //freopen("basis.out", "w", stdout);
  string t, f;
  int i, m;
  cin >> t;
  //cin >> f;
  m=t.size()+f.size()+1;
  prefix_functionk(t);
  for(i=0;i<t.size();i++)cout<<pik[i]<<" ";
 // prefix_functionm(f+'#'+t);
 // cout<<endl;
  //for(i=0;i<m;i++)cout<<pim[i]<<" ";
  return 0;
}
/*
abracadabra
abrabracada
abracadabra
arbadacarba
*/