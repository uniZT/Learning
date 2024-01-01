//
// Created by unizh on 2023/12/27.
//
#include <vector>
#include <iostream>

using namespace std;

int search1(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;    //用.size()，别用sizeof()
    while (left <= right) {
        //int mid = (left + right) / 2;
        //这样不好，要注意防溢出
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

//做闭区间右开区间[left, right)
int search2(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size();    //和上面-1区别
    while (left < right) {        //在这里要left < right才是合法的范围
        int mid = left + (right - left) / 2;
        if (nums[mid] > target) {
            right = mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}