//
// Created by darion.yaphet on 2025/5/8.
//

#include <vector>
#include <queue>

using namespace std;

// https://leetcode.cn/problems/course-schedule-iii/
class Solution {
public:
    /**
     * 按照课程的截止时间 lastDay 进行排序，优先安排截止时间较早的课程。
     *
     * 使用一个最大堆（优先队列）来动态维护当前已选择课程的持续时间。
     */
    int scheduleCourse(vector<vector<int> > &courses) {
        // 按 lastDay 升序排序
        sort(courses.begin(), courses.end(),
             [](const vector<int> &a, const vector<int> &b) {
                 return a[1] < b[1];
             });

        // 最大堆，存储已选课程的 duration
        priority_queue<int> maxHeap;
        int currentTime = 0; // 当前时间

        for (const auto &course: courses) {
            int duration = course[0], lastDay = course[1];

            // 如果可以修读当前课程，直接加入
            if (currentTime + duration <= lastDay) {
                currentTime += duration;
                maxHeap.push(duration);
            } else if (!maxHeap.empty() && maxHeap.top() > duration) {
                // 否则尝试用当前课程替换堆中最长的课程
                currentTime += duration - maxHeap.top(); // 更新总时间
                maxHeap.pop();
                maxHeap.push(duration);
            }
        }

        // 堆中课程的数量即为最多可以修读的课程数
        return maxHeap.size();
    }
};
