//
// Created by Chenguang Wang on 2024/1/23.
//

class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        for (int i = 1; i <= n; i++) {
//            for (int n = i; n % 5 == 0; n /= 5) {
//                result += 1;
//            }

            int n = i;
            while (n != 0) {
                if (n % 5 == 0) {
                    result += 1;
                    n /= 5;
                } else {
                    break;
                }
            }
        }

        return
                result;
    }

};