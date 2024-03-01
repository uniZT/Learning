# 二叉树part09
## ● 669. 修剪二叉搜索树
## ● 108.将有序数组转换为二叉搜索树
## ● 538.把二叉搜索树转换为累加树


### 要注意的点


### 669. 修剪二叉搜索树
https://leetcode.cn/problems/trim-a-binary-search-tree/

=====
```c++
TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr ) return nullptr;
        if (root->val < low) {
            TreeNode* right = trimBST(root->right, low, high); // 寻找符合区间[low, high]的节点
            return right;
        }
        if (root->val > high) {
            TreeNode* left = trimBST(root->left, low, high); // 寻找符合区间[low, high]的节点
            return left;
        }
        root->left = trimBST(root->left, low, high); // root->left接入符合条件的左孩子
        root->right = trimBST(root->right, low, high); // root->right接入符合条件的右孩子
        return root;
    }
```



----
### 108.将有序数组转换为二叉搜索树


=====


-----
### 538.把二叉搜索树转换为累加树


=====