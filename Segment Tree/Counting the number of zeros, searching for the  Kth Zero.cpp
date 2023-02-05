#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int n,t[MAXN];

void build(int a[],int v,int tl,int tr){
    if(tl == tr){
        if(a[tl] == 0){
            t[v] = 1;
        }
        else{
            t[v] = 0;
        }
    }
    else{
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2 + 1, tm + 1, tr);
        t[v] = t[v*2] + t[v*2 + 1];
    }
}

int count_zero(int v,int tl, int tr, int l, int r){
    if(l > r) return 0;
    if(l == tl && r == tr){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return count_zero(v*2, tl, tm, l, min(r,tm)) + count_zero(v*2 + 1, tm + 1, tr, max(l,tm + 1), r);
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

int find_kth(int v, int tl, int tr, int k) {
    if (k > t[v])
        return -1;
    if (tl == tr)
        return tl;
    int tm = (tl + tr) / 2;
    if (t[v*2] >= k)
        return find_kth(v*2, tl, tm, k);
    else 
        return find_kth(v*2+1, tm+1, tr, k - t[v*2]);
}
int main(){
    int a[] = {1,2,0,0,0,2,0};
    build(a,1,0,7-1);
    cout<<count_zero(1,0,7-1,0,2)<<endl;
    cout<<count_zero(1,0,7-1,2,5)<<endl;
    cout<<find_kth(1,0,7-1,3)<<endl;
    cout<<find_kth(1,0,7-1,4)<<endl;
}
