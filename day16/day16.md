# 二叉树part03
## ● 104.二叉树的最大深度  559.n叉树的最大深度 ● 111.二叉树的最小深度 ● 222.完全二叉树的节点个数

### 要注意的点


### 104
https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/

给定一个二叉树 root ，返回其最大深度。

二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。

=====
```c++
int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int leftheight = maxDepth(root->left);
        int rightheight = maxDepth(root->right);
        return 1 + max(leftheight, rightheight);
    }
```


----
### 559
https://leetcode.cn/problems/maximum-depth-of-n-ary-tree/description/

给定一个 N 叉树，找到其最大深度。

最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。

N 叉树输入按层序遍历序列化表示，每组子节点由空值分隔（请参见示例）。

=====
```c++
int maxDepth(Node* root) {
        if(root == NULL) return 0;
        int depth = 0;
        for(int i = 0; i < root->children.size(); i++){
            depth = max(depth, maxDepth(root->children[i]));
        }
        return 1 + depth;
    }
```

-----
### 111
https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/

给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

=====
```c++
int minDepth(TreeNode* root) {
        if(root == NULL)    return 0;
        int leftdepth = minDepth(root->left);
        int rightdepth = minDepth(root->right);
        //一边的子树为空，另一边非空的时候，空的那边并不是最低点，他不是叶节点。要排除这两种情况。
        if(root->left == NULL && root->right != NULL){
            return 1 + rightdepth;
        }
        if(root->left != NULL && root->right == NULL){
            return 1 + leftdepth;
        }
        //如果两边空，高度就是1+0，如果两边非空，高度就是 1 + 两个里最小的
        return  1 + min(leftdepth, rightdepth);
        
    }
```

-----
### 222
https://leetcode.cn/problems/count-complete-tree-nodes/description/

给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。

=====
```c++
int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int leftnum = countNodes(root->left);
        int rightnum = countNodes(root->right);
        return leftnum + rightnum + 1;
    }
```