#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> dijkstra(vector<vector<pair<int,int>>>& adj,int src,int n){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    vector<int> dist(n+1,INT_MAX);
    
    pq.push({0,src});
    dist[src] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(auto it : adj[u]){
            int v = it.first;
            int weight = it.second;

            if(dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}
int main(){
    int n,e,t,m;
    cin>>n>>e>>t>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[v].push_back({u,w});
    }
    vector<int> dist = dijkstra(adj,e,n);
    int cnt = 0;
    for(int i=1;i<=n;i++){
        // cout<<dist[i]<<" ";
        if(dist[i] <= t) cnt++;
    }
    cout<<cnt;
}