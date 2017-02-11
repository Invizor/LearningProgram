#include<iostream>
using namespace std;
int a[105][105]={0};
int main(){
	int n,m,i,j,q,k=0,x,y,z;
	cin>>n>>m;
	for(i=0;i<=n+1;i++)
		for(j=0;j<=n+1;j++)a[i][j]=1000000;
	for(i=1;i<=m;i++){
		cin>>x>>y>>z;
		a[x][y]=z;
		a[y][x]=z;
	}

	for(q=1;q<=n;q++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(a[i][q]+a[q][j]<a[i][j])a[i][j]=a[i][q]+a[q][j];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(k<a[i][j] && a[i][j]<1000000 && i!=j)k=a[i][j];
	cout<<k;
return 0;		
}	