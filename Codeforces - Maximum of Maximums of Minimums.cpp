#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = (int)1e5;
 
int a[MAXN];
int n, k;
int suf_min[MAXN];
 
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	if (k == 1)
	{
		int ans = a[0];
		for (int i = 0; i < n; ++i)
			ans = min(ans, a[i]);
		cout << ans << endl;
	}
	else
	if (k == 2)
	{
		suf_min[n - 1] = a[n - 1];
		for (int i = n - 2; i >= 0; --i)
			suf_min[i] = min(a[i], suf_min[i + 1]);
		int pref_min = a[0];
		int ans = max(pref_min, suf_min[1]);
		for (int i = 1; i < n - 1; ++i)
		{
			pref_min = min(pref_min, a[i]);
			ans = max(ans, max(suf_min[i + 1], pref_min));
		}
		cout << ans << endl;
	}
	else
	{
		int ans = a[0];
		for (int i = 0; i < n; ++i)
			ans = max(ans, a[i]);
		cout << ans << endl;
	}
	return 0;
}
