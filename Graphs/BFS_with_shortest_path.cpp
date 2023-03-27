#include<bits/stdc++.h>
using namespace std;
void display_shortest_path_from_source_to_node(vector<int>& vis,vector<int>& parent,int u){
    if(!vis[u]){
        cout<<"No Path";
    }
    else{
        vector<int> path;
        for(int v = u; v != -1; v = parent[u]){
            path.push_back(v);
        }
        reverse(path.begin(),path.end());
        cout<<"Path : ";
        for(auto it : path) cout<<it<<" ";
    }
}
int main(){
    vector<vector<int>> adj;
    int n;
    int s;
    queue<int> q;
    vector<int> vis(n);
    vector<int> dist(n);
    vector<int> parent(n);
    q.push(s);
    vis[s] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int u : adj[v]){
            if(!vis[u]){
                vis[u] = true;
                q.push(u);
                dist[u] = dist[v] + 1;
                parent[u] = v;
            }
        }
    }
}