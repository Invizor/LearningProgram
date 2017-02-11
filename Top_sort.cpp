#include<vector>
#include<iostream>
#include<iterator>
using namespace std;

vector < vector<int> > g(1000); // граф
int n; // число вершин

vector<bool> used;

vector<int> ans;

void dfs (int v)
{
	used[v] = true;
	for (vector<int>::iterator j=g[v].begin(); j!=g[v].end(); ++j)
		if (!used[*j])
			dfs (*j);
	ans.push_back (v);
}

void topological_sort (vector<int> & result)
{
	used.assign (n, false);
	for (int i=1; i<=n; ++i)
		if (!used[i])
			dfs (i);
	result = ans;
}
int main(){
	int m,i,j,k,x,y;
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>x>>y;
		g[x].push_back(y);
	}	
	topological_sort(ans);
	for(i=ans.size()-1;i>=0;i--)cout<<ans[i]<<" ";
return 0;	
}