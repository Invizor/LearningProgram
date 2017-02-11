#include<iostream>
using namespace std;
int a[405][405]={0};
const int MAXN=1000000005;
int c[100005]={0};
int ni[100005]={0};
int nj[100005]={0};
int absm(int z){
	if(z<0)return -z;else return z;
}
void qsort(int l,int r){
	int i,j,x,y;
	if(l<r){
	i=l;
	j=r;
	x=c[(l+r)/2];
	while(i<j){
		while(c[i]<x)i++;
		while(c[j]>x)j--;
		if(i<=j){
			swap(c[i],c[j]);
			swap(ni[i],ni[j]);
			swap(nj[i],nj[j]);
			i++;
			j--;
		}	
	}
	if(i<r)qsort(i,r);
	if(l<j)qsort(l,j);
	}
}	
int main(){
	int n,m,k,i,j,q=0,sum=0,mn=MAXN;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]!=0)sum++;
			if(mn>a[i][j] && a[i][j]!=0){
				mn=a[i][j];
				ni[0]=i;
				nj[0]=j;
			}	
			if(a[i][j]!=0){
				q++;
				ni[q]=i;
				nj[q]=j;
				c[q]=a[i][j];
			}	
		}
	}	
	if(sum-1!=k || mn==MAXN){
		cout<<"Wrong Board";
		return 0;
	}
	qsort(1,q);
	for(i=2;i<=q;i++){
		if(c[i]==c[i-1]){
			cout<<"Wrong Board";
			return 0;
		}
		if(ni[i]==ni[i-1] || nj[i]==nj[i-1] || absm(ni[i]-ni[i-1])==absm(nj[i]-nj[i-1]))k=1;else{
			cout<<"Wrong Board";
			return 0;
		}
		a[ni[i-1]][nj[i-1]]=i-1;
	}	
	a[ni[q]][nj[q]]=q;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
return 0;	
}	