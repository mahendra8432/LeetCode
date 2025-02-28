class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Fill the dp array with lengths of shortest common supersequences
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0)
                    dp[i][j] = j;
                else if (j == 0)
                    dp[i][j] = i;
                else if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // Backtrack to construct the shortest common supersequence
        string result;
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                result.push_back(s1[i - 1]);
                i--; j--;
            } else if (dp[i - 1][j] < dp[i][j - 1]) {
                result.push_back(s1[i - 1]);
                i--;
            } else {
                result.push_back(s2[j - 1]);
                j--;
            }
        }

        // Add remaining characters from the strings
        while (i > 0) {
            result.push_back(s1[i - 1]);
            i--;
        }
        while (j > 0) {
            result.push_back(s2[j - 1]);
            j--;
        }

        // The result is constructed in reverse order, so reverse it
        reverse(result.begin(), result.end());
        
        return result;
    }
};