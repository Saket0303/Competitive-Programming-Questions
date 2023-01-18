#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
const int Q = 200005;
int parent[N];

int find_set(int v){
    if(v == parent[v]){
        return v;
    }
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a,int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        parent[b] = a;
    }
}
int main(){
    int n,q;
    cin>>n>>q;
    vector<int> ans(n+1,0);
    int query[q][3];
    for(int i=0;i<q;i++){
        int l,r,c;
        cin>>l>>r>>c;
        query[i][0] = l;
        query[i][1] = r;
        query[i][2] = c;
    }
    // cout<<"HI"<<endl;
    for(int i=1;i<=N;i++){
        parent[i] = i;
    }
    // cout<<"HI"<<endl;
    for(int i = q-1;i>=0;i--){
        int l = query[i][0];
        int r = query[i][1];
        int c = query[i][2];

        for(int v = find_set(l); v <= r; v = find_set(v)){
            // cout<<v<<endl;
            ans[v] = c;
            parent[v] = v + 1;
        }
        // for(int i=1;i<=n;i++){
        //     cout<<parent[i]<<" ";
        // }
        // for(int i=1;i<=n;i++){
        //     cout<<ans[i]<<" ";
        // }
    }
    // cout<<"HI"<<endl;
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }
}
