//
// Created by darion.yaphet on 2025/5/17.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string curr = "1";

        for (int i = 2; i <= n; ++i) {
            string next;
            int count = 1;
            char digit = curr[0];

            for (int j = 1; j < curr.size(); ++j) {
                if (curr[j] == digit) {
                    count++;
                } else {
                    next += to_string(count) + digit;
                    digit = curr[j];
                    count = 1;
                }
            }

            // 处理最后一个数字组
            next += to_string(count) + digit;
            curr = next;
        }

        return curr;
    }
};
