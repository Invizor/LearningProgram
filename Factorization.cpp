#include<iostream>
#include<cmath>
using namespace std;
int main(){
	long long n,i,j=0,k;
	cin>>n;
	k=ceil(sqrt(n));
	for(i=2;i<=k;i++){
		if(n%i==0){
			while(n % i==0){
				cout<<i<<" ";
				n/=i;
			}
		}
	}
	if(n>1)cout<<n;
return 0;	
}	