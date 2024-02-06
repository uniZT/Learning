# 贪心算法 part06
## ● 738.单调递增的数字
## ● 968.监控二叉树

### 要注意的点

### 738.单调递增的数字
https://leetcode.cn/problems/monotone-increasing-digits/description/

当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。

给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增 。

=====

从后向前遍历，当前一个比当前小的时候，前一个数字-1，然后后面的都要变成9

比如322---299
```c++
int monotoneIncreasingDigits(int n) {
        string strNum = to_string(n);
        int flag = strNum.size();
        //i>0是因为循环里有i-1
        for(int i = strNum.size() - 1; i > 0; i--){
            //如果前一个比当前的大，那么flag要更新，前一个减1
            if(strNum[i - 1] > strNum[i]){
                strNum[i - 1]--;
                flag = i;
            }
        }
        //flag后的都要变成9
        for(int i = flag; i < strNum.size(); i++){
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
```


----
### 968.监控二叉树
https://leetcode.cn/problems/binary-tree-cameras/description/

给定一个二叉树，我们在树的节点上安装摄像头。

节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。

计算监控树的所有节点所需的最小摄像头数量。

=====

节点有3个状态：0.无覆盖 1.有摄像头 2.有覆盖

有4种情况：

1.左右都有覆盖，则父节点状态是0无覆盖；

2.左右至少1个无覆盖，则父节点应为状态1有摄像头；

3.左右至少1个有摄像头（不会有无覆盖情况，上面处理掉了），则父节点是状态2有覆盖

4.根节点无覆盖，该情况在主函数处理，如果最后root进函数返回0无覆盖，则处理
```c++
int result = 0;
    int traversal(TreeNode* cur){
        //后序遍历
        if(cur == NULL) return 2;   //NULL节点当成是有覆盖的
        int left = traversal(cur->left);
        int right = traversal(cur->right);
        //中的处理
        //左右都有覆盖
        if(left == 2 && right == 2) return 0;

        //左右至少有一个无覆盖
        if(left == 0 || right == 0){
            result++;
            return 1;
        }

        //左右至少有一个有摄像头，但不会出现无覆盖的情况，无覆盖上面已经返回不会到这里
        if(left == 1 || right == 1) return 2;

        //上面所有情况都已经出现，下面这个不会走到，只是为了能正常运作
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        result = 0;
        //如果根节点无覆盖
        if(traversal(root) == 0){
            result++;
        }
        return result;
    }
```


