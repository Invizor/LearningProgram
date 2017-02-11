#include<iostream>
#include<algorithm>
using namespace std;
int d[10000];
int pr[10000];
int a[10000],sum=0;
void restore(int i){
	if(i>0){
		restore(pr[i]);
		sum++;
	}
}	
void restv(int i){
	if(i>0){
		restv(pr[i]);
		cout<<a[i]<<" ";
	}
}	
int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
	int mx,bj,i,j,n,ind,zn;
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	d[0]=0;
	pr[0]=-1;
	for(i=1;i<=n;i++){
		mx=0;
		bj=-1;
		for(j=1;j<=i-1;j++){
			if(a[j]<a[i] && d[j]>mx){
				mx=d[j];
				bj=j;
			}	
		}	
		d[i]=mx+1;
		pr[i]=bj;
	}	
	mx=0;
	ind=0;
	for(i=1;i<=n;i++){
		sum=0;
		if(pr[i]>0)restore(i);
		if(sum>mx){
			mx=sum;
			ind=i;
		}	
	}
	restv(ind);
return 0;	
}	