## 哈希表part01
### 242.有效的字母异位词  349.两个数组的交集  202. 快乐数  1. 两数之和


| **集合**      | **底层实现** | **是否有序** | **数值是否可以重复** | **能否更改数值** | **查询效率** | **增删效率** |
| ------------- | ------------ | ------------ | -------------------- | ---------------- | ------------ | ------------ |
| set           | 红黑树       | 有序         | 否                   | 否               | O(log n)     | O(log n)     |
| multiset      | 红黑树       | 有序         | 是                   | 否               | O(log n)     | O(log n)     |
| unordered_set | 哈希表       | 无序         | 否                   | 否               | O(1)         | O(1)         |



| **映射**      | **底层实现** | **是否有序** | **数值是否可以重复** | **能否更改数值** | **查询效率** | **增删效率** |
| ------------- | ------------ | ------------ | -------------------- | ---------------- | ------------ | ------------ |
| map           | 红黑树       | key有序      | key不可重复          | key不可修改      | O(log n)     | O(log n)     |
| multimap      | 红黑树       | key有序      | key可重复            | key不可修改      | O(log n)     | O(log n)     |
| unordered_map | 哈希表       | key无序      | key不可重复          | key不可修改      | O(1)         | O(1)         |



#### 242
https://leetcode.cn/problems/valid-anagram/description/

给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

第一个比较简单
```c++
bool isAnagram(string s, string t) {
        int record[26] = {0};
        for(int i = 0; i < s.size(); i++){
            record[s[i] - 'a']++;
        }
        for(int j = 0; j < t.size(); j++){
            record[t[j] - 'a']--;
        }
        for(int k = 0; k < 26; k++){
            if(record[k] != 0){
                return false;
            }
        }
        return true;
    }
```
还有一个思路是通过sort对里面的元素进行排序。但是时间复杂度会更高。

----
#### 349
https://leetcode.cn/problems/intersection-of-two-arrays/description/

给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。

需要先了解的内容

unordered_set无序，不重复

上面的意思说是，把nums1的内容复制进nums_set里面
```c++
unordered_set<int> nums_set(nums1.begin(), nums1.end());
```
遍历nums2
```c++
for (int num : nums2){}
```
下面语句会返回的是迭代器
```c++
nums_set.find(num)
```
也就是说，如果想找元素在不在这个里面，就要这样写

如果num在num_set中，那么执行下面的语句，如果不在的话find会返回迭代器end
```c++
if (nums_set.find(num) != nums_set.end()) {     
                result_set.insert(num);
}
```
```c++
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> cmp_set(nums1.begin(), nums1.end());
        unordered_set<int> result_set;
        for(int num : nums2){
            if(cmp_set.find(num) != cmp_set.end()){
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
```

-----

#### 202
https://leetcode.cn/problems/happy-number/description/

编写一个算法来判断一个数 n 是不是快乐数。
```c++
int getsum(int n) {
    int sum = 0;
    while (n) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    unordered_set<int> nums;
    while (1) {
        int sum = getsum(n);
        if (sum == 1) {
            return true;
        }
        if (nums.find(sum) != nums.end()) {
            return false;
        } else {
            nums.insert(sum);
        }
        n = sum;
    }
}
```

-----
#### 1
https://leetcode.cn/problems/two-sum/description/

给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

第一题并不是最简单的，很久以前我看第一题被吓到了。

首先迭代器类型可以用auto，map是一个键值对，用pair
```c++
vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); i++){
            auto iter = map.find(target - nums[i]);
            if(iter != map.end()){
                return {iter->second, i};
            }
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
```