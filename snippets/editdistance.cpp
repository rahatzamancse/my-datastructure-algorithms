/// Name: Edit Distance
/// Description: Calculate edit distance of two strings
/// Detail: Takes O(mn) time, O(mn) space
/// Guarantee: int editDist(
int editDist(string a, string b) {
	vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1));
	for(int i = 0; i<=a.length(); i++) {
		for(int j = 0; j<=b.length(); j++) {
			if(i == 0) 
				dp[i][j] = j;
			else if(j == 0) 
				dp[i][j] = i;
			else if(a[i-1] == b[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
		}
	}
	return dp[a.length()][b.length()];
}