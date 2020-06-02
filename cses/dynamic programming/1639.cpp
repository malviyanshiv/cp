#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main(){
	IOS;
	int n, m, inf = 1000000;
	string a, b;

	cin >> a >> b;

	n = a.size(), m = b.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1, inf));
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++)
		dp[i][0] = i;
	for(int i = 1; i <= m; i++)
		dp[0][i] = i;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			if( a[i-1] == b[j-1] )
				dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
			else
				dp[i][j] = min(dp[i][j], min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))+1);
		}

	cout << dp[n][m] << endl;
	return 0;
}