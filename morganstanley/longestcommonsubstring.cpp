#include <iostream>
#include <vector>

using namespace std;

int longestCommonSubstring(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    // Create a table to store lengths of common suffixes
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    int result = 0;  // To store length of the longest common substring

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                result = max(result, dp[i][j]);
            } else {
                dp[i][j] = 0;  // Reset the length for non-matching characters
            }
        }
    }

    return result;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        string s1, s2;
        cin >> s1 >> s2;

        int result = longestCommonSubstring(s1, s2);
        cout << result << endl;
    }

    return 0;
}
