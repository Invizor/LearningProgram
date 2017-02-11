#include<iostream>
#include<queue>
#include<string>
#include<cstdio>
using namespace std;
char a[105][105],b[105][105];
int ras[105][105];
int bfs(int x,int y){
	int zx,zy;
	queue<int>qx;
	queue<int>qy;
	qx.push(x);
	qy.push(y);
	ras[x][y]=0;
	b[x][y]='1';
	while(! qx.empty()){
		zx=qx.front();
		zy=qy.front();
		qx.pop();
		qy.pop();
		if(b[zx][zy]=='*'){
			while(!qx.empty())qx.pop(),qy.pop();
			return ras[zx][zy];
			break;
		}	
		if(b[zx-1][zy]=='0'||b[zx-1][zy]=='*'){
			if(b[zx-1][zy]=='0')b[zx-1][zy]='1';
			ras[zx-1][zy]=ras[zx][zy]+1;
			qx.push(zx-1);
			qy.push(zy);	
		}
		if(b[zx+1][zy]=='0'|| b[zx+1][zy]=='*'){
			if(b[zx+1][zy]=='0')b[zx+1][zy]='1';
			ras[zx+1][zy]=ras[zx][zy]+1;
			qx.push(zx+1);
			qy.push(zy);	
		}
		if(b[zx][zy-1]=='0'||b[zx][zy-1]=='*'){
			if(b[zx][zy-1]=='0')b[zx][zy-1]='1';
			ras[zx][zy-1]=ras[zx][zy]+1;
			qx.push(zx);
			qy.push(zy-1);	
		}
		if(b[zx][zy+1]=='0'|| b[zx][zy+1]=='*'){
			if(b[zx][zy+1]=='0')b[zx][zy+1]='1';
			ras[zx][zy+1]=ras[zx][zy]+1;
			qx.push(zx);
			qy.push(zy+1);	
		}
	}
return 100000;	
}
int main(){
	int n,m,i,j,k=0,x,y,zn=0,mzn=10001,q,p,ind=0;
	string s;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>s;
		for(j=0;j<m;j++){
			a[i][j+1]=s[j];
		}	
	}
	cin>>k;	
	for(j=1;j<=k;j++){
		for(q=1;q<=n;q++)
			for(p=1;p<=m;p++)b[q][p]=a[q][p],ras[q][p]=0;
		cin>>x>>y;
		zn=bfs(x,y);
			if(zn<mzn){
				mzn=zn;
				ind=j;
			}
	}	
	if(ind==0)cout<<-1;else cout<<ind;
return 0;	
}