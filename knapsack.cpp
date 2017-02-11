#include <vector>
#include <limits>
#include<iostream>
using namespace std;
int knapsack2(const std::vector<int>& wts, const std::vector<int>& cost, int W)
{
	size_t n=wts.size();
	std::vector<std::vector<int> > dp(W+1);
	for(int i=0;i<=W;i++)
	{
		dp[i].resize(n+1);
		dp[i][0]=0;
	}
	for(size_t i=0;i<=n;i++)dp[0][i]=0;
	for(size_t j=1;j<=n;j++)
	{
		for(int w=1;w<=W;w++)
		{
			if(wts[j-1]<=w)
			{
				dp[w][j]=std::max(dp[w][j-1],dp[w-wts[j-1]][j-1]+cost[j-1]);
			}else
			{
				dp[w][j]=dp[w][j-1];
			}
		}
	}
	return dp[W][n];
}
int main(){
	vector<int> c;
	vector<int> w;
	int n,i,j,k,r,x,y;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>x>>y;
		c.push_back(x);
		w.push_back(y);
	}
	cin>>r;
	k=knapsack2(w,c,r);
	cout<<k<<endl;
return 0;	
}	