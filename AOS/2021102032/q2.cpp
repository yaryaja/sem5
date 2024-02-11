#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define forn for (int i = 0; i < n; i++)
const ll m = 1 << 8;
int find(vector<int> &A, vector<vector<int>> &dp, int ind, int sum, int tsum)
{
	int n = A.size();
	if (ind == n)
	{
		return abs((tsum - sum) - sum);
	}
	if (dp[ind][sum] != -1)
	{
		return dp[ind][sum];
	}
	int take = find(A, dp, ind + 1, sum + A[ind], tsum);
	int n_take = find(A, dp, ind + 1, sum, tsum);

	return dp[n][sum] = min(take, n_take);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// your code goes here
	int n;
	ll T;
	T = 1;

	while (T-- && cin >> n)
	{
		int W;
		cin>>W;
		vi wieght(n), value(n);
		int sum = 0;
		forn
		{
			cin >> wieght[i];
		}
		forn
		{
			cin >> value[i];
		}
		vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
		int ans = INT_MIN;
		for (int i = 0; i <= n; i++)
		{
			dp[i][0] = 0;
		}
		for (int i = 0; i <=W; i++)
		{
			dp[0][i] = 0;
		}
		
		for (int i = 1; i <=n; i++)
		{
			for (int j = 1; j <= W; j++)
			{
				
				if(wieght[i-1]<=j){
					dp[i][j]=max(value[i-1]+dp[i-1][j-wieght[i-1]],dp[i-1][j]);
				}
				else{
					dp[i][j]=dp[i-1][j];

				}
			}
		}
		// for(auto it:dp){
		// 	for(auto i:it){
		// 		cout<<i<<" ";
		// 	}cout<<endl;
		// }
		cout<<dp[n][W];
	}

	return 0;
}
