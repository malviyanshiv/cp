#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main(){
	IOS;
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	vector<int> lis;
	lis.push_back(arr[0]);

	for(int i = 1; i < n; i++){
		auto ub = lower_bound(lis.begin(), lis.end(), arr[i]);
		if( ub == lis.end() )
			lis.push_back(arr[i]);
		else
			lis[ub-lis.begin()] = arr[i];
	}

	cout << lis.size() << endl;

	return 0;
}