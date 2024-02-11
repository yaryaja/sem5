#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define forn for (int i = 0; i < n; i++)
const ll m = 1 << 8;

int **dp; 
int find(int w, int h) {
    if (dp[w][h] != -1) return dp[w][h];
    dp[w][h] = w * h;
    int temp;
    for (int i = 1; i <= h / 2; i++) {
        temp = find(w, i);
        if (temp + find(w, h - i) < dp[w][h]) {
            dp[w][h]= temp + find(w, h - i);
        }
    }
    for (int i = 1; i <= w / 2; i++) {
        temp = find(i, h);
        if (temp + find(w - i, h) < dp[w][h]) {
            dp[w][h] = temp + find(w - i, h);
        }
    }
    return dp[w][h];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int W, H;
    cin >> W >> H;
    int n;
    cin >> n;

  
    dp = new int *[W + 1];
    for (int i = 0; i <= W; i++) {
        dp[i] = new int[H + 1];
        memset(dp[i], -1, sizeof(int) * (H + 1));
    }

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        dp[a][b] = 0;
    }

    cout << find(W, H);
    // for(int i=0;i<W+1;i++){
    //    for(int j=0;j<H+1;j++){
    //     cout<<dp[i][j]<<" ";
    //    }
    // }

   
    for (int i = 0; i <= W; i++) {
        delete[] dp[i];
    }
    delete[] dp;

    return 0;
}
