#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int n,t[MAXN];

void build(int a[],int v,int tl,int tr){
    if(tl == tr){
        t[v] = a[tl]; 
    }
    else{
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2 + 1, tm + 1, tr);
        t[v] = t[v*2] + t[v*2 + 1];
    }
}

int sum(int v,int tl, int tr, int l, int r){
    if(l > r) return 0;
    if(l == tl && r == tr){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r,tm)) + sum(v*2 + 1, tm + 1, tr, max(l,tm + 1), r);
}

void update(int v, int tl, int tr, int pos, int new_val){
    if(tl == tr){
        t[v] = new_val;
    }
    else{
        int tm = (tl + tr) / 2;
        if(pos <= tm){
            update(v*2, tl, tm, pos, new_val);
        }
        else{
            update(v*2 + 1, tm + 1, tr, pos, new_val);
        }
        t[v] = t[v*2] + t[v*2 + 1];
    }
}

int query(int v, int l, int r, int K){
    if( l == r )
        return l;
    int mid = (l+r)/2;
    if( t[2*v] >= K ) // left child contains the required index
        return query(2*v, l, mid, K);
    else
        return query(2*v+1, mid+1, r, K-t[2*v]); // right segment don't have sum of left segment
}
int main(){
    // build(a,1,0,n-1);
    if( seg[1] < K ){
        // answer doesn't exist
    }else{
        ans = query(1, 0, n-1, K);
    }
}
