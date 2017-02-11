#include<iostream>
#include<string>
using namespace std;
int n,i,j,x[100];
string s;
void Generate(int k)
{
	    int i,j;
		if(k==n){
	      for(i=1;i<=n;i++) cout<<s[x[i]-1];cout<<endl;
	    }
	      for(j=k+1;j<=n;j++){
				swap(x[k+1],x[j]);
				Generate(k+1);
				swap(x[k+1],x[j]);
		  }
}
int main(){
	cin>>s;
	n=s.size();
	for(i=1;i<=n;i++)x[i]=i;
	Generate(0);
return 0;	
}	