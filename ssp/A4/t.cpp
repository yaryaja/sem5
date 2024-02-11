//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        int ans=0;
        vector<int>vis(V+1,0);
        while(pq.size()){
            auto it=pq.top();
            pq.pop();
            if(vis[it.second])continue;
            vis[it.second]=1;
            ans+=it.first;
            for(auto node:adj[it.second]){
                int adjnode=node[0];
                int adw=node[1];
                if(vis[adjnode]==0){
                    pq.push({adw,adjnode});

                }
            }
        }
        return ans;
    }
    
    

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

    	cout << spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends