//
// Created by Chenguang Wang on 2024/2/7.
//

// https://leetcode.cn/problems/simplify-path

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    std::string simplifyPath(std::string path) {

        auto split = [](const string &s, char delim) -> vector<string> {
            vector<string> ans;
            string cur;
            for (char ch: s) {
                if (ch == delim) {
                    ans.push_back(move(cur));
                    cur.clear();
                } else {
                    cur += ch;
                }
            }
            ans.push_back(move(cur));
            return ans;
        };

        vector<string> names = split(path, '/');
        vector<string> stack;
        for (string &name: names) {
            if (name == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else if (!name.empty() && name != ".") {
                stack.push_back(move(name));
            }
        }

        string result;
        if (stack.empty()) {
            result = "/";
        } else {
            for (string &name: stack) {
                result += "/" + move(name);
            }
        }
        return result;
    }
};