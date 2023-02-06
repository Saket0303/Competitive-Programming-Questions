#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int t[4 * N];

void build(int a[], int v, int tl, int tr){
    if(tl == tr){
        t[v] = a[tl];
    }
    else{
        int tm = (tl + tr) / 2;
        build(a,2*v,tl,tm);
        build(a,2*v + 1,tm+1,tr);
        t[v] = max(t[2*v],t[2*v+1]);
    }
}

int atleast_x(int v, int tl, int tr, int l, int r, int x){
    // If current range does
    // not lie in query range
    if(l > tr || r < tl){
        return -1;
    }

    // If current range is inside
    // of query range
    if(l <= tl && tr <= r){

        // Maximum value in this
        // range is less than x
        if(t[v] <= x) return -1;

        // Finding index of first
        // value in this range
        while(tl != tr){
            int tm = tl + (tr - tl) / 2;

            // Update the value of
            // the minimum index
            if(t[2*v] > x){
                v = 2*v;
                tr = tm;
            }
            else{
                v = 2*v + 1;
                tl = tm + 1;
            }
        }
        return tl;
    }

    // Find mid of the current range
    int tm = tl + (tr - tl) / 2;

    // Left subtree
    int val = atleast_x(2*v,tl,tm,l,r,x);
    if(val != -1) return val;

    // If it does not lie in
    // left subtree
    return atleast_x(2*v+1,tm+1,tr,l,r,x);
}

void update(int v, int tl, int tr, int pos, int new_val){
    if(tl == tr){
        t[pos] = new_val;
    }
    else{
        int tm = tl + (tr - tl) / 2;
        if(pos <= tm){
            update(2*v, tl, tm, pos, new_val);
        }
        else{
            update(2*v+1, tm+1, tr, pos, new_val);
        }
        t[v] = max(t[2*v],t[2*v+1]);
    }
}
