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
        string str;
        cin>>str;
        for(int i=0;i<n;i++){
            if(str[i]=='0'){
                str[i]='1';
            }
            else{
                str[i]='0';
            }
        }
        str+='1';
        cout<<str<<endl;


        
        

    }

    return 0;
}
