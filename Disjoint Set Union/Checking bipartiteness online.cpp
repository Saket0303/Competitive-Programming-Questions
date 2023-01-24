#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
vector<pair<int,int>> parent(N);
vector<bool> bipartite(N);
vector<int> rank(N);
void make_set(int v){
    parent[v] = make_pair(v,0);
    bipartite[v] = true;
    rank[v] = 0;
}
pair<int,int> find_set(int v){
    if(v != parent[v].first){
        int parity = parent[v].second;
        parent[v] = find_set(parent[v].first);
        parent[v].second ^= parity;
    }
    return parent[v];
}
void add_edge(int a,int b){
    pair<int,int> pa = parent[a];
    pair<int,int> pb = parent[b];
    a = pa.first;
    b = pb.first;
    int x = pa.second;
    int y = pb.second;
    if(a == b){
        if(x == y){
            bipartite[a] = false;
        }
    }
    else{
        if(rank[a] < rank[b]){
            swap(a,b);
        }
        parent[b] = make_pair(a,x ^ y ^ 1);
        bipartite[a] &= bipartite[b];
        if(rank[a] == rank[b]) rank[a]++;
    }
}
bool is_bipartite(int v){
    return bipartite[find_set(v).first];
}

