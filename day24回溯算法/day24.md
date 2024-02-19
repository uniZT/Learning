# 回溯算法part01
## ● 理论基础
## ● 77. 组合


### 要注意的点


### 理论基础
回溯法，一般可以解决如下几种问题：

组合问题：N个数里面按一定规则找出k个数的集合

切割问题：一个字符串按一定规则有几种切割方式

子集问题：一个N个数的集合里有多少符合条件的子集

排列问题：N个数按一定规则全排列，有几种排列方式

棋盘问题：N皇后，解数独等等

=====
```c++
void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}
```



----
### 77. 组合
https://leetcode.cn/problems/combinations/description/

给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。

=====
```c++
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int n, int k, int startIndex){
        if(path.size() == k){
            result.push_back(path);
            return;
        }
        //从1开始所以<=n
        for(int i = startIndex; i <= n; i++){
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();    //回溯
        }
    }
public:

    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
```


