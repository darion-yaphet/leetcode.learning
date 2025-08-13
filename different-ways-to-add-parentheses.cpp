//
// Created by darion.yaphet on 2025/4/21.
//

#include <vector>

using namespace std;

// https://leetcode.cn/problems/different-ways-to-add-parentheses/
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;
        if (expression.empty()) {
            return result;
        }

        bool isNumber = true;
        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];

            if (c == '+' || c == '-' || c == '*') {
                isNumber = false;
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                for (int l: left) {
                    for (int r: right) {
                        switch (c) {
                            case '+': result.push_back(l + r);
                                break;
                            case '-': result.push_back(l - r);
                                break;
                            case '*': result.push_back(l * r);
                                break;
                            default: ;
                        }
                    }
                }
            }
        }

        if (isNumber) {
            result.push_back(stoi(expression));
        }
        return result;
    }
};
