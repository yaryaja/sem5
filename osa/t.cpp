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
    ll T;
    cin >> T;
    while (T-- && cin>>n)
    {
        int k;
        cin>>k;
        vi A(n);
        int mul=1000;
        int ev=0;
        forn {
            cin>>A[i];
            if(!(A[i]%2))ev++;
            mul=min(mul,(k-(A[i]%k))%k);
           
        }
        ev=min(ev,2);
        if(k==4){
            cout<<min(mul,2-ev)<<endl;
        }
        else cout<<mul<<endl;
        

        



        
        

    }

    return 0;
}
