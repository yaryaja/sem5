#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define pii pair<ll,ll>
#define forn for (ll i = 0; i < n; i++)
const ll m = 1 << 8;



ll find(vector<ll>& A,ll k,ll mid){
    ll op=0;
    ll n=A.size();
    // ll temp;
    for(ll i=0;i<n;i++){
        if(A[i]>mid){
            ll temp=ceil(A[i]/mid)+1;
            temp--;
            op+=temp;

        }
    }
    return op>k?0:1;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // your code goes here
    ll n;
    ll k;
    cin>>n>>k;
    vector<ll>A(n);forn cin>>A[i];
    ll l=1;
    ll r=INT_MAX;
    ll ans;
    while(l<=r){
        ll mid=(l+r)/2;

        if(find(A,k,mid)){
            ans=mid;
            r=mid-1;

        }
        else{
            l=mid+1;
        }

    }
    cout<<ans;
    return 0;
}
