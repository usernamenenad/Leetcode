#include <iostream>
#include <math.h>

class Solution {
    public:
        int reverse(int x) {
            bool is_positive = x > 0;
            x = is_positive ? x : std::abs(x);

            int i = 0, j = 0;
            int ret = 0;
            while(x / std::pow(10, i+1) > 1) {i++;}
            if(x == std::pow(10, i+1)) {x = 1; i = 0;}
            while(i >= 0) {
                ret += (x / (int) std::pow(10, i)) * std::pow(10, j++);
                x %= (int) std::pow(10, i--);
            }
            if(ret == INT_MAX || ret == INT_MIN) {return 0;}
            return is_positive ? ret : ret * -1;
        }
};

int main() {
    Solution s;
    std::cout << s.reverse(1534236469);
}