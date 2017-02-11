#include<iostream>
#include<cstdio>
using namespace std;
int a[1005][1005]={0},lv[1005][1005]={0},ln[1005][1005]={0},pv[1005][1005]={0},pn[1005][1005]={0};
int main(){
	int n,m,i,j,k,x1,y1,x2,y2,rez;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			lv[i][j]=a[i][j];
			ln[i][j]=a[i][j];
			pv[i][j]=a[i][j];
			pn[i][j]=a[i][j];
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			lv[i][j]+=(lv[i-1][j]+lv[i][j-1]-lv[i-1][j-1]);
		}	
	}
	for(i=n;i>=1;i--){
		for(j=1;j<=m;j++){
			ln[i][j]+=(ln[i+1][j]+ln[i][j-1]-ln[i+1][j-1]);
		}	
	}
	for(i=1;i<=n;i++){
		for(j=m;j>=1;j--){
			pv[i][j]+=(pv[i][j+1]+pv[i-1][j]-pv[i-1][j+1]);
		}	
	}
	for(i=n;i>=1;i--){
		for(j=m;j>=1;j--){
			pn[i][j]+=(pn[i+1][j]+pn[i][j+1]-pn[i+1][j+1]);
		}	
	}
	for(i=1;i<=k;i++){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		swap(x1,y1);
		swap(x2,y2);
		rez=lv[n][m]-lv[y2][x1-1]-ln[y2+1][x2]-pn[y1][x2+1]-pv[y1-1][x1];
		printf("%d\n",rez);
	}
return 0;	
}	