// 240528
// https://www.acmicpc.net/problem/11659

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    int n, m, i, j, temp;
    int dp[100001];
    
    cin >> n >> m;
    
    dp[0] = 0;
    
    for(int k = 1; k <= n; k++){
        cin >> temp;
        dp[k] = dp[k - 1] + temp;
    }
    
    for(int k = 0; k < m; k++){
        cin >> i >> j;
        cout << dp[j] - dp[i - 1] << "\n";
    }
    
    return 0;
}