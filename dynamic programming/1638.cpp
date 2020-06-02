#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define MOD 1000000007

int32_t main(){
	IOS;
	int n;
	cin >> n;
	vector<vector<char>> grid(n, vector<char>(n));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> grid[i][j];

	vector<vector<int>> dp(n, vector<int>(n, 0));

	//filling base case, i.e. first row and column
	dp[0][0] = grid[0][0] == '.' ? 1 : 0;
	for(int i = 1; i < n; i++)
		if( grid[0][i] == '.' )
			dp[0][i] = dp[0][i-1];

	for(int i = 1; i < n; i++)
		if( grid[i][0] == '.' )
			dp[i][0] = dp[i-1][0];

	for(int i = 1; i < n; i++)
		for(int j = 1; j < n; j++)
			if( grid[i][j] == '.' )
				dp[i][j] = (dp[i][j-1] + dp[i-1][j])%MOD;

	cout << dp[n-1][n-1] << endl;

	return 0;
}