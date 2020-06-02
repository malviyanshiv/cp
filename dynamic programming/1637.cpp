#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main(){
	IOS;
	int n;
	cin >> n;
	vector<int> step(n+1, n+1);
	step[0] = 0;
	for(int i = 1; i <= n; i++){
		int cstep = n+1, cur = i;
		while( cur ){
			cstep = min(cstep, step[i - cur%10]+1);
			cur = cur/10;
		}
		step[i] = cstep;
	}

	cout << step[n] << endl;
	return 0;
}