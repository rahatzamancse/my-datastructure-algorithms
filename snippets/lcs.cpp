/// Name: LCS (Longest Common Subsequence)
/// Description: Calculates the longest common subsequence string
/// Detail: Takes O(mn) time, O(mn) space
/// Guarantee: string LCS(
string LCS(string s1, string s2) {
	vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, 0));
	int i, j;
	for (i = 1; i <= s1.length(); i++)
		for (j = 1; j <= s2.length(); j++)
			if (X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;
			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);

	// Getting the string
	int i = s1.length(), j = s2.length();
	string res;
	while(i > 0 && j > 0) {
		if(s1[i-1] == s2[j-1]) {
			res.push_back(s1[i-1]);
			i--; j--;
		}
		else if(L[i-1][j] > L[i][j-1])
			i--;
		else
			j--;
	}
	reverse(res.begin(), res.end());
	return res;
}