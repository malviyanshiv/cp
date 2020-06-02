#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define MOD 1000000007
 
int32_t main(){
	IOS;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> dp(n, vector<int>(m+1, 0));
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
 
	int ans = 0;
	if (!arr[0]) {
		for(int i = 1; i <= m; i++)
			dp[0][i] = 1;
	}else{
		dp[0][arr[0]] = 1;
	}
 
	for(int i = 1; i < n; i++){
		if( !arr[i] ){
			for(int j = 1; j <= m; j++){
				ans = dp[i-1][j];
				if( j-1 > 0 )
					ans += dp[i-1][j-1];
				if( j+1 <= m )
					ans += dp[i-1][j+1];
				dp[i][j] = ans%MOD;
			}
		}else{
			int j = arr[i];
			ans = dp[i-1][j];
			if( j-1 > 0 )
				ans += dp[i-1][j-1];
			if( j+1 <= m )
				ans += dp[i-1][j+1];
			dp[i][j] = ans%MOD;
		}
	}
 
	ans = 0;
	for(int i = 1; i <= m; i++)
		if( dp[n-1][i] > 0 )
		ans = (ans + dp[n-1][i])%MOD;
 
	cout << ans << endl;
 
	return 0;
}