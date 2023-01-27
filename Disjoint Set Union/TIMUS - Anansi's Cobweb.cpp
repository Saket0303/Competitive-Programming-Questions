#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
const int M = 100005;
int num_comp;
int parent[N],ranks[N];

void make_set(int n){
    for(int i=1;i<=n;i++){
        parent[i] = i;
        ranks[i] = 0;
    }
    num_comp = n;
}

int find_set(int v){
    if(v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a,int b){
    int pa = parent[a];
    int pb = parent[b];
    if(pa == pb) return;
    num_comp--;
    if(ranks[a] < ranks[b]) swap(a,b);
    parent[b] = a;
    if(ranks[a] == ranks[b]) ranks[a]++;
}

int main(){
    int n,m;
    cin>>n>>m;
    int Eu[m],Ev[m];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        Eu[i] = u;
        Ev[i] = v;
    }
    int q;
    cin>>q;
    vector<bool> add(m,true);
    int ans[q],ind[q];
    for(int i=0;i<q;i++){
        cin>>ind[i];
        add[--ind[i]] = false;
    }
    make_set(n);
    for(int i=0;i<m;i++){
        if(!add[i]) continue;
        union_sets(Eu[i],Ev[i]);
    }
    for(int i=q-1;i>=0;i--){
        ans[i] = num_comp;
        union_sets(Eu[ind[i]],Ev[ind[i]]);
    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<" ";
    }
}
