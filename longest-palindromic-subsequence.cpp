//
// Created by Chenguang Wang on 2024/2/25.
//

#include <string>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size = s.size();
        int dp[size][size];

        for (int i = 0; i < size; i++) {
            dp[i][i] = 1;
        }

        for (int i = size - 1; i >= 0; i--) {
            for (int j = i + 1; j < size; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][size - 1];
    }
};