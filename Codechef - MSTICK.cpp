#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
const int LOG = 17;
int a[N];
int mn[N][LOG];
int mx[N][LOG];
int bin_log[N];

int get_min(int L,int R){
    if(L == R) return a[L];
    if(L > R) return 0;
    int length = R - L + 1;
    int k = bin_log[length];
    return min(mn[L][k],mn[R - (1 << k) + 1][k]);
}
int get_max(int L,int R){
    if(L == R) return a[L];
    if(L > R) return 0;
    int length = R - L + 1;
    int k = bin_log[length];
    return max(mx[L][k],mx[R - (1 << k) + 1][k]);
}
int main(){
    int n;
    cin>>n;
    bin_log[1] = 0;
    for(int i=2;i<=n;i++){
        bin_log[i] = bin_log[i/2] + 1;
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
        mn[i][0] = a[i];
        mx[i][0] = a[i];
    }
    for(int k=1;k<LOG;k++){
        for(int i=0;i + (1 << k) - 1 < n;i++){
            mn[i][k] = min(mn[i][k-1],mn[i+(1<<(k-1))][k-1]);
            mx[i][k] = max(mx[i][k-1],mx[i+(1<<(k-1))][k-1]);
        }
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int L,R;
        cin>>L>>R;
        double LR_min = (double)get_min(L,R);
        double ans = max(LR_min + ((double)get_max(L,R) - LR_min)/2 , max((double)get_max(0,L-1),(double)get_max(R+1,n-1)) + LR_min);
        cout<<fixed<<setprecision(1)<<ans<<endl;
    }
}