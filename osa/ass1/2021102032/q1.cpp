#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define pii pair<ll,ll>
#define forn for (ll i = 0; i < n; i++)
const ll m = 1 << 8;
const ll M=1e9+7;

ll find(ll k,ll n){
    if(n==1){
        return k;
    }
    ll l=find(k,n/2);
    ll r=l;
    if(n%2)r=(r%M* k%M)%M;
    return(l%M * r%M)%M;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // your code goes here
    ll n;
    ll T;
    cin >> T;
    while (T-- )
    {
        ll k;
        cin>>k>>n;
        ll ans=1;
        cout<<find(k,n-1)<<endl;
        // cout<<ans<<endl;


        
        

    }

    return 0;
}
