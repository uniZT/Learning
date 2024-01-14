# 二叉树part04
## ● 110.平衡二叉树 ● 257. 二叉树的所有路径 ● 404.左叶子之和

### 要注意的点


### 110
https://leetcode.cn/problems/balanced-binary-tree/

给定一个二叉树，判断它是否是高度平衡的二叉树。

=====
```c++
int getHeight(TreeNode* node){
        //终止条件
        if(node == NULL) return 0;
        //左右子树高
        int leftheight = getHeight(node->left);
        int rightheight = getHeight(node->right);
        //如果高为-1则返回-1
        if(leftheight == -1) return -1;
        if(rightheight == -1) return -1;
        //如果不平衡，返回-1
        if(abs(leftheight - rightheight) > 1){
            return -1;
        }
        //平衡则高度为最高子树+1
        else{
            return 1 + max(leftheight, rightheight);
        }
    }
    bool isBalanced(TreeNode* root) {
        if(getHeight(root) == -1){
            return false;
        }
        else{
            return true;
        }
    }
```


----
### 257
https://leetcode.cn/problems/binary-tree-paths/description/

给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。

=====
```c++
void traversal(TreeNode* cur, vector<int>& path, vector<string>& result){
        path.push_back(cur->val);
        //左右子树都为空
        if(cur->left == NULL && cur->right == NULL){
            string sPath;
            //最后一个后面没有->，所以这边处理要少一个
            for(int i = 0; i < path.size() - 1; i++){
                sPath += to_string(path[i]);
                sPath += "->";
            }
            //加上最后一个
            sPath += to_string(path[path.size() - 1]);
            result.push_back(sPath);
            return;
        }
        if (cur->left) { // 左 
            traversal(cur->left, path, result);
            path.pop_back(); // 回溯
        }
        if (cur->right) { // 右
            traversal(cur->right, path, result);
            path.pop_back(); // 回溯
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        if(root == NULL) return result;
        traversal(root, path, result);
        return result;
    }
```

-----
### 404
https://leetcode.cn/problems/sum-of-left-leaves/description/

给定二叉树的根节点 root ，返回所有左叶子之和。

=====

```c++
int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 0;
        
        int leftvalue = sumOfLeftLeaves(root->left);
        //如果root节点的左节点，左节点下面没有其他节点了
        if(root->left && !root->left->left && !root->left->right){
            leftvalue = root->left->val;
        }
        int rightvalue = sumOfLeftLeaves(root->right);
        //root的右节点不用直接判断
        int sum = leftvalue + rightvalue;
        return sum;
    }
```
