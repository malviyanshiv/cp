#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main(){
	IOS;
	int n, x;
	cin >> n >> x;
	int val[n];
	for(int i = 0; i < n; i++)
		cin >> val[i];

	vector<int> dp(x+1, -1);
	for(int i = 0; i < n; i++)
		if( val[i] <= x )
			dp[val[i]] = 1;

	for(int i = 1; i <= x; i++)
		for(int j = 0; j < n; j++)
			if( i - val[j] >= 0 && dp[i-val[j]] != -1 )
				dp[i] = dp[i] == -1 ? dp[i-val[j]]+1 : min(dp[i], dp[i-val[j]]+1);

	cout << dp[x] << endl;
	return 0;
}