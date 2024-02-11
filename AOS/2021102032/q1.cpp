#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define forn for (int i = 0; i < n; i++)
const ll m = 1 << 8;
int find(vector<int>&A,vector<vector<int>>&dp,int ind,int sum,int tsum){
	int n=A.size();
	if(ind==n){
		return abs((tsum-sum)-sum);
	}
	if(dp[ind][sum]!=-1){
		return dp[ind][sum];

	}
	int take=find(A,dp,ind+1,sum + A[ind],tsum);
	int n_take=find(A,dp,ind+1,sum ,tsum);

	return dp[n][sum]=min(take,n_take);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// your code goes here
	int n;
	ll T;
	T=1;
	
	while (T-- && cin>>n)
	{
		vi A(n);
		int sum=0;
		forn {
			cin>>A[i];
			sum+=A[i];
		}
		vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
		int ans=INT_MAX;
		dp[0][0]=1;
		dp[0][A[0]]=1;
		for(int i=1;i<n;i++){
			for(int j=0;j<=sum;j++){
				if(dp[i-1][j]!=-1){
					dp[i][j]=1;
					dp[i][j+A[i]]=1;
					
				}
				
			}
		}
		for(int i=n-1;i<n;i++){
			for(int j=0;j<=sum;j++){
				if(dp[i][j]!=-1){
					// cout<<j<<" ";
					ans=min(ans,max(j,sum-j));
				}
			}
				cout<<endl;
		}
		// cout<<sum<<endl;
		cout<<ans<<endl;




		
		

	}

	return 0;
}
