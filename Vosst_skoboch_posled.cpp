#include<iostream>
using namespace std;
int main(){
 long long a[100],b[100]={0},n,k,i,j,l,m,sum=0,q,p;
 string s;
	cin>>s;
	n=s.size();
   if(n%2==1){
	   cout<<0;
	   return 0;
   } 
   for(i=0;i<s.size();i++){
	   if(s[i]=='?')sum++;
	   b[i]=0;
	   a[i]=0;
   }
   if(sum==0){
	   cout<<0;
	   return 0;
	} 
   a[0]=1;
   for(i=0;i<n;i++){
	   p=i+1;
      for(j=0;j<=p;j++){
         if((p+j)%2==0){
				b[j]=0;
				if((s[i]==')')||((j==0) && (s[i]=='?')))b[j]=a[j+1];
				else
				 if((s[i]=='(')||((j==i) and (s[i]=='?')))b[j]=a[j-1];
				else
				b[j]=a[j-1]+a[j+1];
			}
		}
      for(q=0;q<=n;q++)a[q]=b[q];
	}
   cout<<b[0];
  return 0; 
}