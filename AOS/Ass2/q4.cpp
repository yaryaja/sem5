#include <bits/stdc++.h>
using namespace std;
#define ll int
#define vi vector<ll>
#define pii pair<ll, ll>
#define forn for (ll i = 0; i < n; i++)
const ll m = 1e9 + 7;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vector<ll> A(n);
    forn cin >> A[i];

    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    unordered_map<int, int> mp1, mp2;
    for (ll i = 0; i < n; i++)
    {

        dp[0][i] = 1;
        mp1[i] = 1;
    }
    ll ans = 0;

    for (ll ind = 0; ind < n - 1; ind++)
    {
        for (auto it : mp1)
        {

            ll temp = 0;
            for (ll i = it.first + 1; i < n; i++)
            {
                temp += A[i];
                if (temp % (ind + 2) == 0)
                {
                    mp2[i] += mp1[it.first];
                    if(i==n-1){
                        ans+=mp1[it.first];
                    }
                }
                
            }
        }
        mp1 = mp2;
        mp2.clear();
    }

    cout << ans+1 << endl;

    return 0;
}
