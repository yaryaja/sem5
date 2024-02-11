#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
#define vi vector<ll>
#define pii pair<ll, ll>
#define forn for (ll i = 0; i < n; i++)
const ll m = 1 << 8;
ll inversion=0;


    void merge(ll arr[], ll l, ll m, ll r)
    {
        ll A[m-l+1];
        for(ll i=l;i<=m;i++){
            A[i-l]=arr[i];
        }
        ll B[r-m];
        for(ll i=m+1;i<=r;i++){
            B[i-m-1]=arr[i];
        }
        
        ll s=m-l+1;
        ll t=r-m;
        ll j=0,k=0;
        while(j<s && k<t){
            if(A[j]<B[k]){
                arr[l++]=A[j++];
            }
            else{
                arr[l++]=B[k++];
                inversion+=(s-j);
            }
        }
        while(j<s){
            arr[l++]=A[j++];
          
        }
        while(k<t){
            arr[l++]=B[k++];
        }
    }
    
    void mergeSort(ll *arr, ll l, ll r)
    {
        //code her
        if(l==r){
            return ;
        }
        ll mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
        
    
    }



signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // your code goes here
    
    cin>>n;
    vector<pair<ll,ll>>A(n);
    for(ll i=0;i<n;i++){
        cin>>A[i].first;
    }
    for(ll i=0;i<n;i++){
        cin>>A[i].second;
    }
    sort(A.begin(),A.end());
    ll arr[n];
    for(ll i=0;i<n;i++){
        arr[i]=A[i].second;
    }
    mergeSort(arr,0,n-1);
   
    // for(auto it:A){
    //     cout<<it.first;
    // }cout<<endl;
    // mergeSort(A,0,n-1);
    // for(auto it:A){
    //     cout<<it.second;
    // }
    cout<<inversion;
    //  for(ll i=0;i<n;i++){
    //     cout<<arr[i];
    //  }
    inversion=0;

    return 0;
}