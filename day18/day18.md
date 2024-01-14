# 二叉树part05
## ● 513.找树左下角的值 ● 112. 路径总和  113.路径总和ii ● 106.从中序与后序遍历序列构造二叉树 105.从前序与中序遍历序列构造二叉树


### 要注意的点


### 513.找树左下角的值
https://leetcode.cn/problems/find-bottom-left-tree-value/description/

给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。

=====
```c++
int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        if(root != NULL) que.push(root);
        int result = 0;
        while(!que.empty()){
            int size = que.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                if(i == 0) result = node->val;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return result;
    }
```


----
### 112. 路径总和
https://leetcode.cn/problems/path-sum/description/

给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。

=====
```c++
bool traversal(TreeNode* cur, int count){
        if(cur->left == NULL && cur->right == NULL && count == 0) return true;
        if(cur->left == NULL && cur->right == NULL && count != 0) return false;
        if(cur->left){
            count -= cur->left->val;
            if(traversal(cur->left, count)) return true;
            count += cur->left->val;    //回溯撤销减法
        }
        if(cur->right){
            count -= cur->right->val;
            if(traversal(cur->right, count)) return true;
            count += cur->right->val;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        return traversal(root, targetSum - root->val);
    }
```

-----
### 113路径总和ii
https://leetcode.cn/problems/path-sum-ii/description/

给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

=====
```c++
vector<vector<int>> result;
    vector<int> path;

    void traversal(TreeNode* cur, int count){
        if(cur->left == NULL && cur->right == NULL && count == 0){
            result.push_back(path);
            return;
        }
        if(cur->left == NULL && cur->right == NULL && count != 0) return;
        if(cur->left){
            path.push_back(cur->left->val);
            count -= cur->left->val;
            traversal(cur->left, count);
            count += cur->left->val;
            path.pop_back();
        }
        if(cur->right){
            path.push_back(cur->right->val);
            count -= cur->right->val;
            traversal(cur->right, count);
            count += cur->right->val;
            path.pop_back();
        }
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        result.clear();
        path.clear();
        if(root == NULL) return result;
        path.push_back(root->val);
        traversal(root , targetSum - root->val);
        return result;
    }
```
### 106. 从中序与后序遍历序列构造二叉树
https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。

好难，要重新回来开

=====
```c++
TreeNode* traversal (vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) return NULL;

        // 后序遍历数组最后一个元素，就是当前的中间节点
        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);

        // 叶子节点
        if (postorder.size() == 1) return root;

        // 找到中序遍历的切割点
        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue) break;
        }

        // 切割中序数组
        // 左闭右开区间：[0, delimiterIndex)
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        // [delimiterIndex + 1, end)
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end() );

        // postorder 舍弃末尾元素
        postorder.resize(postorder.size() - 1);

        // 切割后序数组
        // 依然左闭右开，注意这里使用了左中序数组大小作为切割点
        // [0, leftInorder.size)
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        // [leftInorder.size(), end)
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return NULL;
        return traversal(inorder, postorder);
    }
```





