#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
const int M = 10;
int st[N][N][M][M];
int bin_log[N];
void build(int n,int m){
    bin_log[1] = 0;
    for(int i=2;i<=n;i++){
        bin_log[i] = bin_log[i/2] + 1;
    }
    for(int i=1;i<=n;i++){
        for(int k2=1;(1 << k2) <= m;k2++){
            for(int j=1;j + (1 << k2) - 1 <= m ;j++){
                st[i][j][0][k2] = max(st[i][j][0][k2-1],st[i][j + (1 << (k2 - 1))][0][k2-1]);
            }
        }
    }
    for(int k1 = 1;(1 << k1) <= n;k1++){
        for(int i=1;i + (1 << k1) - 1 <= n;i++){
            for(int k2 = 0;(1 << k2) <= m; k2++){
                for(int j=1;j + (1 << k2) - 1 <= m ;j++){
                    st[i][j][k1][k2] = max(st[i][j][k1-1][k2],st[i + (1 <<  (k1 - 1))][j][k1-1][k2]);
                }
            }
        }
    }
}
int query(int x1,int y1,int x2,int y2){
    int k1 = bin_log[x2 - x1 + 1];
    int k2 = bin_log[y2 - y1 + 1];
    x2 = x2 - (1 << k1) + 1;
    y2 = y2 - (1 << k2) + 1;
    return max(max(st[x1][y1][k1][k2],st[x1][y2][k1][k2]),max(st[x2][y1][k1][k2],st[x2][y2][k1][k2]));
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;
            cin>>x;
            if(x){
                st[i][j][0][0] = min(st[i-1][j][0][0],min(st[i-1][j-1][0][0],st[i][j-1][0][0])) + 1;
            }
        }
    }
    build(n,m);
    int q;
    cin>>q;
    while(q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int start = 0;
        int end = min(x2 - x1, y2 - y1) + 1;
        int ans = 0;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(query(x1 + mid - 1,y1 + mid - 1,x2,y2) >= mid){
                start = mid + 1;
                ans = mid;
            }
            else{
                end = mid - 1;
            }
        }
        cout<<ans<<endl;
    }
}