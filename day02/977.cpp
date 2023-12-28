//
// Created by unizh on 2023/12/28.
//
#include <vector>
#include <algorithm>

using namespace std;

//暴力解
vector<int> sortedSquares(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++){
        nums[i] *= nums[i];
    }
    sort(nums.begin(), nums.end());
    return nums;
}

//交换解，用空间换时间
vector<int> sortedSquares2(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);
    for(int left = 0, right = n - 1, pivot = n - 1; left <= right;){
        if(nums[left] * nums[left] > nums[right] * nums[right]){
            result[pivot--] = nums[left] * nums[left];
            left++;
        }
        else{
            result[pivot--] = nums[right] * nums[right];
            right--;
        }
    }
    return result;
}