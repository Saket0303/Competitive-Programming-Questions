#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const int maxm = 10;
int n,m,f[maxm][maxm][maxn][maxn],lg[maxn];
void Build_2D_Sparse_Table(int n, int m){
    int i, j, k1, k2;

	for(i = 2; i < maxn; i++)
		lg[i] = 1 + lg[i/2];

	for(i = 1; i <= n; i++)
		for(k2 = 1; (1 << k2) <= m; k2++)
			for(j = 1; j <= m - (1 << k2) + 1; j++)
				f[0][k2][i][j] = max(f[0][k2 - 1][i][j], f[0][k2 - 1][i][j + (1 << (k2 - 1))]);

	for(k1 = 1; (1 << k1) <= n; k1++)
		for(i = 1; i <= n - (1 << k1) + 1; i++)
			for(k2 = 0; (1 << k2) <= m; k2++)
				for(j = 1; j <= m - (1 << k2) + 1; j++)
					f[k1][k2][i][j] = max(f[k1 - 1][k2][i][j], f[k1 - 1][k2][i + (1 << (k1 - 1))][j]);
}

int Query(int x1, int y1, int x2, int y2){
	int k1 = lg[x2 - x1 + 1], k2 = lg[y2 - y1 + 1];
	x2 = x2 - (1 << k1) + 1;
	y2 = y2 - (1 << k2) + 1;
	return max(max(f[k1][k2][x1][y1],f[k1][k2][x1][y2]),max(f[k1][k2][x2][y1],f[k1][k2][x2][y2]));
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int x;scanf("%d",&x);
            if(x){
                f[0][0][i][j]=min(f[0][0][i-1][j],min(f[0][0][i][j-1],f[0][0][i-1][j-1]))+1;
            }
        }
    }
    Build_2D_Sparse_Table(n,m);
    int q;scanf("%d",&q);
    while(q--)
    {
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        int l=0,r=min(x2-x1,y2-y1)+1,ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(Query(x1+mid-1,y1+mid-1,x2,y2)>=mid)l=mid+1,ans=mid;
            else r=mid-1;
        }
        cout<<ans<<endl;
    }
}
