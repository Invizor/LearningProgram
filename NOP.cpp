#include<iostream>
using namespace std;
int  n,m,i,j,a[1005],b[1005],q=0,z[1005];
int c[1005][1005];
int v[1005][1005];
void lcs(){
for(i=1;i<=n;i++){
	for(j=1;j<=m;j++){
		if(a[i]==b[j]){
			c[i][j]=c[i-1][j-1]+1;
			v[i][j]=3;
		}
		if(a[i]!=b[j]){
			c[i][j]=max(c[i-1][j],c[i][j-1]);
			if(c[i-1][j]>c[i][j-1])v[i][j]=1;else v[i][j]=2;
		}
	}
}	

}	
int main(){
	int sum=0;
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	cin>>m;
	for(i=1;i<=m;i++)cin>>b[i];
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++)c[i][j]=0;
	lcs();
		i=n;
		j=m;
	while(i>0 && j>0){
		if(v[i][j]==3){
			q++;
			z[q]=b[j];
			i--;
			j--;
		}else
		if(v[i][j]==1)i--;else
		if(v[i][j]==2)j--;
	}
		for(i=q;i>=1;i--)cout<<z[i]<<" ";
return 0;	
}	