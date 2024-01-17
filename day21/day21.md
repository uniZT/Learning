# 二叉树part07
## ● 530.二叉搜索树的最小绝对差 ● 501.二叉搜索树中的众数 ● 236. 二叉树的最近公共祖先


### 要注意的点


### 530.二叉搜索树的最小绝对差
https://leetcode.cn/problems/minimum-absolute-difference-in-bst/

给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。

=====

递归两种解法。第一种，二叉搜索树变换成数组，然后相减得到结果。第二种，递归中序遍历，前后指针。
```c++
vector<int> vec;
    //中序遍历
    void traversal(TreeNode* cur){
        if(cur == NULL) return;
        traversal(cur->left);
        vec.push_back(cur->val);
        traversal(cur->right);
    }
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        int result = INT_MAX;
        for(int i = 1; i < vec.size(); i++){
            result = min(result, vec[i] - vec[i - 1]);
        }

        return result;
    }
```

```c++
int result = INT_MAX;
    TreeNode* pre = NULL;
    //中序遍历
    void traversal(TreeNode* cur){
        if(cur == NULL) return;
        traversal(cur->left);
        if(pre != NULL){
            result = min(result, cur->val - pre->val);
        }
        pre = cur;
        traversal(cur->right);

    }
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return result;
    }
```


----
### 501.二叉搜索树中的众数
https://leetcode.cn/problems/find-mode-in-binary-search-tree/

给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。

=====

首先是中序遍历，中序遍历得到的顺序是单调的。count和maxCount的用法，就是，当前个数大于maxCount的话，那就送入结果数组；
但是如果有一个新的比最大的maxCount还大，那就要把结果数组清零，把新的最大的放进去。
```c++
private:
    int maxCount = 0;
    int count = 0;
    TreeNode* pre = NULL;
    vector<int> result;
    void traversal(TreeNode* cur){
        if(cur == NULL) return;

        traversal(cur->left);

        if(pre == NULL) count = 1;
        else if(pre->val == cur->val) count ++;
        else count = 1;
        pre = cur;

        if(count == maxCount) result.push_back(cur->val);
        if(count > maxCount){
            maxCount = count;
            result.clear();
            result.push_back(cur->val);
        }

        traversal(cur->right);
        return;
        
    }
public:
    vector<int> findMode(TreeNode* root) {
        count = 0;
        maxCount = 0;
        pre = NULL;
        result.clear();
        traversal(root);
        return result;
    }
```

-----
### 236. 二叉树的最近公共祖先
https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/

给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

=====

一个思路我觉得是，先拿一个层序遍历的数组出来。然后找到两个节点的位置index，index / 2就是父节点，当除以到一样就是公共祖先。

递归，后序遍历，

```c++
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == q || root == p) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left!=NULL && right == NULL) return left;
        else if(left == NULL && right != NULL) return right;
        else if(left != NULL && right != NULL) return root;
        else return NULL;
    }
```


