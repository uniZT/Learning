# 贪心算法 part01
## ● 455.分发饼干
## ● 376. 摆动序列
## ● 53. 最大子序和



### 要注意的点


### 455.分发饼干
https://leetcode.cn/problems/assign-cookies/description/

=====

就是小饼干给吃的少的，不行就下一个饼干，可以就下一个小朋友下一个饼干
```c++
int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int result = 0;
        for(int childIndex = 0, cakeIndex = 0; childIndex < g.size() && cakeIndex < s.size();){
            if(g[childIndex] <= s[cakeIndex]){
                result++;
                childIndex++;
                cakeIndex++;
            }
            else{
                cakeIndex++;
            }
        }
        return result;
    }
```



----
### 


=====


-----
### 


=====

-----
### 


=====

