#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 100005;
const int M = 10;
const int LOG = 17;
int st[N][M][LOG];
int bin_log[N];
int a[N][M];
int get_max(int L,int R,int j){
    int length = R - L + 1;
    int k = bin_log[length];
    return max(st[L][j][k],st[R - (1 << k) + 1][j][k]);
}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    bin_log[1] = 0;
    for(int i=2;i<=n;i++){
        bin_log[i] = bin_log[i/2] + 1;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            st[i][j][0] = a[i][j];
        }
    }

    for(int k=1;k<LOG;k++){
        for(int j=0;j<m;j++){
            for(int i=0 ; i + (1 << (k-1)) - 1 < n ; i++){
                st[i][j][k] = max(st[i][j][k-1],st[i + (1 << (k-1))][j][k-1]);
            }
        }
    }

    vector<int> ans(m);
    int ans_len = 0;
    for(int i=0;i<n;i++){
        // bool flag = false;
        int low = i;
        int high = n-1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int cnt = 0;
            for(int j=0;j<m;j++){
                cnt += get_max(i,mid,j);
            }
            if(cnt <= k){
                if(ans_len < mid - i + 1){
                    ans_len = mid - i + 1;
                    for(int j=0;j<m;j++){
                        ans[j] = get_max(i,mid,j);
                    }
                }
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }   
    }
    for(int i=0;i<m;i++){
        cout<<ans[i]<<" ";
    }
}