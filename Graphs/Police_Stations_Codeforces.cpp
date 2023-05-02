#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,d;
    cin>>n>>k>>d;
    queue<int> q;
    vector<bool> vis(n+1,false);
    for(int i=0;i<k;i++){
        int ps;
        cin>>ps;
        q.push(ps);
        vis[ps] = 1;
    }
    vector<pair<int,int>> adj[n+1];
    set<int> roads;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(make_pair(v,i));
        adj[v].push_back(make_pair(u,i));
    }
    for(int i=1;i<n;i++){
        roads.insert(i);
    }
    while(!q.empty()){
        int par = q.front();
        q.pop();
        for(auto it : adj[par]){
            int child = it.first;
            int index = it.second;
            if(!vis[child]){
                roads.erase(index);
                vis[child] = true;
                q.push(child);
            }
        }
    }
    cout<<roads.size()<<endl;
    for(auto x : roads){
        cout<<x<<" ";
    }
}