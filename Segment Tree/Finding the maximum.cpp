#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int t[N];

void build(int a[],int v, int tl, int tr){
    if(tl == tr){
        t[v] = a[tl];
    }
    else{
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, 2*v + 1, tm + 1, tr);
        t[v] = max(t[2*v], t[2*v + 1]);
    }
}

int get_max(int v,int tl,int tr,int l,int r){
    if(l > r) return -INT_MIN;
    if(l == tl && r == tr){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(get_max(2*v, tl, tm, l, min(r,tm)), get_max(2*v+1, tm + 1, tr, max(l,tm + 1), r));
}

void update(int v, int tl, int tr, int pos, int new_val){
    if(tl == tr){
        t[v] = new_val;
    }
    else{
        int tm = (tl + tr) / 2;
        if(pos <= tm){
            update(2*v, tl, tm, pos, new_val);
        }
        else{
            update(2*v + 1, tm + 1, tr, pos, new_val);
        }
        t[v] = max(t[2*v], t[2*v + 1]);
    }
}
