#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 100005;
const int LOG = 17;
int a[N];
int st[N][LOG];
int bin_log[N];

int get_max(int L,int R){
    // if(L == R) return a[L];
    // if(L > R) return 0;
    int length = R - L + 1;
    int k = bin_log[length];
    return max(st[L][k],st[R - (1 << k) + 1][k]);
}
int main(){
    int n;
    cin>>n;
    bin_log[1] = 0;
    for(int i=2;i<=n;i++){
        bin_log[i] = bin_log[i/2] + 1;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        st[i][0] = a[i+1] - a[i];
    }
    for(int k=1;k<LOG;k++){
        for(int i=1;i + (1 << k) - 1 <= n;i++){
            st[i][k] = max(st[i][k-1],st[i + (1 << (k-1))][k-1]);
        }
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){   
        int t,d;
        cin>>t>>d;
        int low = 1;
        int high = n;
        int tmp = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(a[mid] <= t){
                tmp = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        low = 1, high = tmp;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(get_max(mid,tmp - 1) <= d){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        cout<<ans<<endl;
    }
}