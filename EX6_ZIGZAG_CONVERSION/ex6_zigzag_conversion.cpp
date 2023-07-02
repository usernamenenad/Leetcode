#include <iostream>
#include <string>

class Solution {
    
    public:

        std::string convert(std::string s, int numRows) {
            if(numRows <= 1 || s.length() == 0) {return s;}
            
            std::string ret;
            int dist_left = 2*numRows - 2;
            int dist_right = 0;

            for(int i = 0; i < numRows; i++) {
                int dist = dist_left > 0 ? dist_left : dist_right;
                int curr = i;
                while(curr < s.length()) {
                    ret.push_back(s[curr]);
                    curr += dist;
                    if(dist_left == 0 || dist_right == 0) {dist = std::max(dist_left, dist_right);}
                    else if(dist == dist_left) {dist = dist_right;}
                    else {dist = dist_left;}
                }
                dist_left -= 2;
                dist_right += 2;
            }
            return ret;
        }
};

int main(int argnum, char** args) {
    Solution s;
    std::cout << s.convert(std::string(args[1]), *args[2] - '0');
    return 0;
}