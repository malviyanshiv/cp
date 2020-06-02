#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main(){
	IOS;
	int n;
	cin >> n;
	int list[n];
	for(int i = 0; i < n; i++)
		cin >> list[i];

	pair<int, int> score[n][n];

	// filling base case i.e. when we have only a single number left
	// first : represent the starting player from that position
	for(int i = 0; i < n; i++)
		score[i][i].first = list[i], score[i][i].second = 0;

	for(int i = 2; i <= n; i++){
		for(int l = 0, r = i-1; r < n; l++, r++){
			auto start = score[l+1][r], end = score[l][r-1];
			if( start.second+list[l] > end.second+list[r] ){
				score[l][r].first = start.second+list[l];
				score[l][r].second = start.first;
			}else{
				score[l][r].first = end.second+list[r];
				score[l][r].second = end.first;
			}
		}
	}

	cout << score[0][n-1].first << endl;
	return 0;
}