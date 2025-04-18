//
// Created by Chenguang Wang on 2024/2/1.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int minDistance2(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i <= word1.size(); i++) {
            dp[i][0] = i;
        }

        for (int j = 0; j <= word2.size(); j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                }
            }
        }

        return dp[word1.size()][word2.size()];
    }

    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        if (n * m == 0) {
            return n + m;
        }

        int dp[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }

        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));
                }
            }
        }
        return dp[m][n];
    }
};