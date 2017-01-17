#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#define int long long
using namespace std;
 
int n, stren;
int *s;
int *e;
int **dp;

int sum_cubed(int num){
	int dig = log10(num);
	int s = 0;
	for (int i=dig; i>=0; --i){
		int cur = num/pow(10, i);
		s += (cur%10);
	}

	return s*s*s;
}
 
int ans(int i, int s_i){
	// s_i represents index of strength value
	// i is index

	if (dp[i][s_i]!=-1){
		return dp[i][s_i];
	}

	if (i!=n-1){
		dp[i][s_i] = max(s[s_i]*e[i] + ans(i+1, s_i), ans(i+1, s_i+1));
	}
	else {
		dp[i][s_i] = s[s_i]*e[i];
	}
	
	return dp[i][s_i];
}
 
signed main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n >> stren;
	s = new int[n];
	e = new int[n];
	s[0] = stren;
 
	for (int i=1; i<n; ++i){
		s[i] = s[i-1] + sum_cubed(s[i-1]);
	}
 
	for (int i=0; i<n; ++i){
		cin >> e[i];
	}

	dp = new int*[n];
	for (int i=0; i<n; ++i){
		dp[i] = new int[n];
		for (int j=0; j<n; ++j){
			dp[i][j] = -1;
		}
	}

	cout << ans(0, 0) << endl;
	return 0;
 
} 