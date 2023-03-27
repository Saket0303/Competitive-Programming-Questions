#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> moves{{-2,-1},{2,-1},{-2,1},{2,1},{1,2},{1,-2},{-1,2},{-1,-2}};
int bfs(int s1,int s2,int e1,int e2){
    queue<vector<int>> q;
    q.push({s1,s2,0});
    vector<vector<int>> vis(8,vector<int>(8,0));
    vis[s1][s2] = 1;
    while(!q.empty()){
        vector<int> top = q.front();
        q.pop();
        if(top[0] == e1 && top[1] == e2){
            return top[2];
        }
        for(auto move : moves){
            int m1 = top[0] + move[0];
            int m2 = top[1] + move[1];
            if(m1 >= 0 && m1 < 8 && m2 >= 0 && m2 < 8 && !vis[m1][m2]){
                vis[m1][m2] = 1;
                q.push({m1,m2,top[2] + 1});
            }
        }
    }
    return -1;
}
int solve(){
    string start,end;
    cin>>start>>end;
    int s1 = start[0] - 'a';
    int s2 = start[1] - '0' - 1;
    int e1 = end[0] - 'a';
    int e2 = end[1] - '0' - 1;
    // cout<<s1<<" "<<s2<<" "<<e1<<" "<<e2<<endl;
    int ans = 1e5;
    return bfs(s1,s2,e1,e2);
}
int main(){
    int t;
    cin>>t;
    vector<int> ans;
    while(t--){
        ans.push_back(solve());
    }
    for(auto it : ans){
        cout<<it<<endl;
    }
}