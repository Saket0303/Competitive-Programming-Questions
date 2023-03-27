#include<bits/stdc++.h>
using namespace  std;

int main(){
    vector<vector<int>> adj;
    int n; // number of nodes
    int s; // source vertex
    queue<int> q;
    vector<bool> vis(n,false);
    q.push(s);
    vis[s] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        cout<<v<<" ";
        for(int u : adj[v]){
            if(!vis[u]){
                vis[u] = true;
                q.push(u);
            }
        }
    }
}