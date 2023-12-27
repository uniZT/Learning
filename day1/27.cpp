//
// Created by unizh on 2023/12/27.
//
#include <vector>

using namespace std;

int removeElement(vector<int> &nums, int val) {
    int left = 0;
    for(int right = 0; right < nums.size(); right++){
        if(nums[right] != val){
            nums[left++] = nums[right];
        }
    }
    return left;
}


int removeElement2(vector<int> &nums, int val) {
    int left = 0;
    int right = nums.size() - 1;    //别忘了减1
    while(left <= right){
        // 找左边等于val的元素
        while(left <= right && nums[left] != val){
            left++;
        }
        // 找右边不等于val的元素
        while(left <= right && nums[right] == val){
            right--;
        }
        // 将右边不等于val的元素覆盖左边等于val的元素
        if(left < right){       //如果这里用了等号，left会多交换一次，导致长度出现问题
            nums[left++] = nums[right--];
        }
    }
    return left;
}
