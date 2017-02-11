#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector < vector<int> > g(3000);
int n,m,i,j,k;
int bfs(int v){
	int ras[3000],x,zn=0;
	queue<int>q;
	for(i=1;i<=n;i++)ras[i]=0;
	ras[v]=1;
	q.push(v);
	while(!q.empty()){
		x=q.front();
		q.pop();
		for(i=0;i<g[x].size();i++){
			if(ras[g[x][i]]>ras[x]+1 || ras[g[x][i]]==0){
				q.push(g[x][i]);
				ras[g[x][i]]=ras[x]+1;
			}
		}	
	}
	for(i=1;i<=n;i++)if(ras[i]>zn)zn=ras[i];
	return zn;
}	
int main(){
	int x,y,mx=0,rez=0,p;
	cin>>n;
	for(i=1;i<=n-1;i++){
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}	
	for(p=1;p<=n;p++){
		if(g[p].size()==1){
			rez=bfs(p);
			if(rez>mx)mx=rez;
		}	
	}	
	cout<<mx;
return 0;		
}	