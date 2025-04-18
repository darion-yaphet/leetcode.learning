//
// Created by Chenguang Wang on 2024/2/13.
//
#include <vector>
#include <stack>
#include <queue>
#include <numeric>

using namespace std;

class Solution {
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches) {
        stack<int> sandwicheStack;
        queue<int> studentQueue;

        for (const auto student: students) {
            studentQueue.push(student);
        }

        for (const auto sandwiche: sandwiches) {
            sandwicheStack.push(sandwiche);
        }

        int size = students.size();
        while (!studentQueue.empty()) {

            int s = studentQueue.front();
            studentQueue.pop();

            if (sandwicheStack.top() == s) {
                sandwicheStack.pop();
                size -= 1;
            } else {
                studentQueue.push(s);
            }

            if (size == students.size()) {
                break;
            }
        }

        return studentQueue.size();
    }

    int countStudents2(vector<int> &students, vector<int> &sandwiches) {
        int s1 = std::accumulate(students.begin(), students.end(), 0);
        int s0 = students.size() - s1;
        for (int i = 0; i < sandwiches.size(); i++) {
            if (sandwiches[i] == 0 && s0 > 0) {
                s0--;
            } else if (sandwiches[i] == 1 && s1 > 0) {
                s1--;
            } else {
                break;
            }
        }
        return s0 + s1;
    }
};