# 动态规划part02
## ● 62.不同路径
## ● 63. 不同路径 II



### 要注意的点


### 62.不同路径
https://leetcode.cn/problems/unique-paths/

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？

=====
```c++
int uniquePaths(int m, int n) {
        //注意题目是路径不是步数
        //初始化完之后，都是0
        vector<vector<int>> dp(m, vector<int>(n, 0));
        //需要再进行初始化，第一行第一列都是1
        //dp[i][j]应该为dp[i][j-1]+dp[i-1][j]
        for(int i = 0; i < m; i++){
            dp[i][0] = 1;
        }
        for(int j = 0; j < n; j++){
            dp[0][j] = 1;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[m - 1][n - 1];
    }
```



----
### 63. 不同路径 II
https://leetcode.cn/problems/unique-paths-ii/description/

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

网格中的障碍物和空位置分别用 1 和 0 来表示。

=====

初始化的时候，可以简化
```c++
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        //初始化第一行第一列的时候，遇到障碍物，它和后面的都置为0
//        for(int i = 0; i < m; i++){
//            if(obstacleGrid[i][0] == 0){
//                dp[i][0] = 1;
//            }
//            else{
//                break;
//            }
//        }
//        for(int j = 0; j < n; j++){
//            if(obstacleGrid[0][j] == 0){
//                dp[0][j] = 1;
//            }
//            else{
//                break;
//            }
//        }
        //简单写法，当遇到1的时候就结束循环
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j] == 1) continue;
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[m-1][n-1];
    }
```