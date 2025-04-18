//
// Created by darion.yaphet on 2024/9/15.
//

#include "TreeNode.h"
#include <algorithm>
#include <queue>
#include <string>

class Solution {
public:
    int example(std::string str) {
        auto position = str.find(" ");
        std::string token;
        int start = 0;
        while (position != std::string::npos) {
            token = str.substr(start, position);
            start = position + 1;
            position = str.find(" ", start);
        }
        return token.size();
    }
};