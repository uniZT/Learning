# 贪心算法 part05
## ● 435. 无重叠区间
## ● 763.划分字母区间
## ● 56. 合并区间




### 要注意的点


### 435. 无重叠区间
https://leetcode.cn/problems/non-overlapping-intervals/

给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回 需要移除区间的最小数量，使剩余区间互不重叠 。

=====
```c++
    //按左边界排序
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int result = 0;
        for(int i = 1; i < intervals.size(); i++){
            //后一个左边，小于，前一个右边
            if(intervals[i][0] < intervals[i - 1][1]){
                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);    //右边界更新为小的那个
                result++;
            }
        }
        return result;
    }
```



----
### 763.划分字母区间
https://leetcode.cn/problems/partition-labels/description/

给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。

注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。

返回一个表示每个字符串片段的长度的列表。

=====
````c++
vector<int> partitionLabels(string s) {
        int position[26] = {0}; //记录每个字符出现的最后位置
        for(int i = 0; i < s.size(); i++){
            position[s[i] - 'a'] = i;
        }
        vector<int> result;
        int left = 0;
        int right = 0;
        for(int i = 0; i < s.size(); i++){
            //右边界是大的那个
            right = max(right, position[s[i] - 'a']);
            if(right == i){
                result.push_back(right - left + 1);
                left = i + 1;   //更新左边界到当前截止的右边一个位置
            }
        }
        return result;
    }
````

-----
### 56. 合并区间
https://leetcode.cn/problems/merge-intervals/description/

以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

=====
```c++
static bool cmp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.size() == 0) return result;
        sort(intervals.begin(), intervals.end(), cmp);
        result.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(result.back()[1] >= intervals[i][0]){    //如果重叠  
                result.back()[1] = max(result.back()[1], intervals[i][1]);  //改变区间右端长度
            }
            else{   //如果不重叠
                result.push_back(intervals[i]); //把下一段加进去
            }
        }
        return result;
    }
```