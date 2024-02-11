#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define forn for (int i = 0; i < n; i++)
const ll m = 1 << 8;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // your code goes here
   int n;
   cin>>n;
   vector<pair<int,int>>v(n);
   for(int i=0;i<n;i++){
    cin>>v[i].first;
    cin>>v[i].second;
   }
   sort(v.begin(),v.end());
   vector<pair<int,int>>ans;
   ans.push_back(v[n-1]);
   int ht=ans[0].second;
   for(int i=n-2;i>=0;i--){
        if(v[i].second>=ht){
            ans.push_back(v[i]);
            ht=max(ht,v[i].second);
        }
   }
   for(auto it:ans){
    cout<<it.first<<" "<<it.second<<endl;
   }

    return 0;
}
