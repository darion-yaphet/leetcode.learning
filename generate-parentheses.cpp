//
// Created by Chenguang Wang on 2024/1/22.
//

//https://leetcode.cn/problems/generate-parentheses

#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    bool valid(const string &str) {
        int balance = 0;
        for (char c: str) {
            if (c == '(') {
                ++balance;
            } else {
                --balance;
            }
            if (balance < 0) {
                return false;
            }
        }
        return balance == 0;
    }

    void generate_all(string &current, int n, vector<string> &result) {
        if (n == current.size()) {
            if (valid(current)) {
                result.push_back(current);
            }
            return;
        }

        current += '(';
        generate_all(current, n, result);
        current.pop_back();

        current += ')';
        generate_all(current, n, result);
        current.pop_back();
    }

    string track = "";
    vector<string> res;

    void backtrack(int left, int right) {
        if (right < left) {
            return;
        }

        if (left < 0 || right < 0) {
            return;
        }

        if (left == 0 && right == 0) {
            res.push_back(track);
            return;
        }

        track.push_back('(');
        backtrack(left - 1, right);
        track.pop_back();

        track.push_back(')');
        backtrack(left, right - 1);
        track.pop_back();
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        generate_all(current, n * 2, result);
        return result;
    }

    vector<string> generateParenthesis2(int n) {
        if (n == 0) {
            return res;
        }

        backtrack(n, n);
        return res;
    }
};
