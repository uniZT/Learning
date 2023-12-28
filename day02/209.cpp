//
// Created by unizh on 2023/12/28.
//
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;
int minSubArrayLen(int target, vector<int>& nums) {
    int result = INT32_MAX;
    int sum = 0;
    int length = 0;
    int begin = 0;
    for(int end = 0; end < nums.size(); end++){
        sum += nums[end];
        while(sum >= target){
            length = end - begin + 1;
            result = min(result, length);
            sum -= nums[begin++];
        }
    }
    return result == INT32_MAX ? 0:result;
}