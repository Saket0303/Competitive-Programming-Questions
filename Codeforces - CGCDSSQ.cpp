#include<bits/stdc++.h>
using namespace std;
#define ll long long
int gcd(int a,int b){
    if(a % b == 0) return b;
    return gcd(b, a % b);
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    map<int,ll> result;
    map<int,int> divisors;
    map<int,int> next_divisors;
    for(int i=0;i<n;i++){
        next_divisors.clear();
        for(auto &p:divisors){
            next_divisors[gcd(p.first,a[i])] += p.second;
        }
        next_divisors[a[i]]++;
        swap(next_divisors,divisors);
        for(auto &p : divisors){
            result[p.first] += p.second;
        }
    }
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        cout<<result[x]<<endl;
    }
}