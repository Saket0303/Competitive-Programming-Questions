#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 50005;
const int LOG = 17;
int a[MAX_N];
int m[MAX_N][LOG]; // m[i][j] is minimum among a[i..i+2^j-1]
int bin_log[MAX_N];

int query(int L, int R) { // O(1)
	int length = R - L + 1;
	int k = bin_log[length];
	return max(m[L][k], m[R-(1<<k)+1][k]);
}

int main() {
	
	int n,q;
	cin >> n >> q;
	bin_log[1] = 0;
	for(int i = 2; i <= n; i++) {
		bin_log[i] = bin_log[i/2]+1;
	}
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		m[i][0] = a[i];
	}
	
	for(int k = 1; k < LOG; k++) {
		for(int i = 0; i + (1 << k) - 1 < n; i++) {
			m[i][k] = max(m[i][k-1], m[i+(1<<(k-1))][k-1]);
		}
	}

    int ans = 0;
	for(int i = 0; i < q; i++) {
		int L, R;
		cin >> L >> R;
        L--;
        R--;
        if(L == R){
            ans++;
            continue;
        }
        if(L > R) continue;
		int mx = query(L,R-1);
        // cout<<mx<<endl;
        if(a[L] >= mx) ans++;
	}
    cout<<ans<<endl;
}