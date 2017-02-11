#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;    
long long a,b,x,y,zn,k;
int nod(int v,int c){
	return c ? nod(c,v%c) : v;
}       
long long bin_search(){
	long long l,r,z;
	l=1;
	r=2000000000;
    while(l<r){
                z=(r+l)/2;
                if(x*z<=a && y*z<=b)l=z+1;else r=z;
        }
	return l-1;
}
int main(){
        cin>>a>>b>>x>>y;
        k=nod(x,y);
        x/=k;
        y/=k;
        zn=bin_search();
        if(zn*x>a || zn*y>b){
                cout<<0<<" "<<0;
                return 0;
        }       
	cout<<x*zn<<" "<<y*zn;  
return 0;       
}