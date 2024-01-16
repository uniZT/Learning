# 二叉树part06
## ● 654.最大二叉树 ● 617.合并二叉树 ● 700.二叉搜索树中的搜索 ● 98.验证二叉搜索树


### 要注意的点


### 654.最大二叉树
https://leetcode.cn/problems/maximum-binary-tree/description/

给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:

创建一个根节点，其值为 nums 中的最大值。
递归地在最大值 左边 的 子数组前缀上 构建左子树。
递归地在最大值 右边 的 子数组后缀上 构建右子树。
返回 nums 构建的 最大二叉树 。

=====
```c++
TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* node = new TreeNode(0);
        if(nums.size() == 1){
            node->val = nums[0];
            return node;
        }

        //寻找最大元素
        int maxValue = 0;
        int maxValueIndex = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > maxValue){
                maxValue = nums[i];
                maxValueIndex = i;
            }
        }
        node->val = maxValue;

        //左
        if(maxValueIndex > 0){
            vector<int> newVec(nums.begin(), nums.begin() + maxValueIndex);
            node->left = constructMaximumBinaryTree(newVec);
        }
        //右
        if(maxValueIndex < (nums.size() - 1)){
            vector<int> newVec(nums.begin() + maxValueIndex + 1, nums.end());
            node->right = constructMaximumBinaryTree(newVec);
        }
        return node;

    }
```


----
### 617.合并二叉树
https://leetcode.cn/problems/merge-two-binary-trees/description/

给你两棵二叉树： root1 和 root2 。

想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；否则，不为 null 的节点将直接作为新二叉树的节点。

返回合并后的二叉树。

=====
```c++
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL) return root2;
        if(root2 == NULL) return root1;
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
```

-----
### 700.二叉搜索树中的搜索
https://leetcode.cn/problems/search-in-a-binary-search-tree/description/

给定二叉搜索树（BST）的根节点 root 和一个整数值 val。

你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null 。

=====
```c++
TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL || root->val == val) return root;
        TreeNode* result = NULL;
        if(root->val > val) result = searchBST(root->left, val);
        if(root->val < val) result = searchBST(root->right, val);
        return result;
    }
```

-----
### 98.验证二叉搜索树
https://leetcode.cn/problems/validate-binary-search-tree/description/

给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。


=====

就是看中序遍历是否有序
```c++
long long maxVal = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;

        bool left = isValidBST(root->left);
        if(maxVal < root-> val) maxVal = root->val;
        else return false;
        bool right = isValidBST(root->right);

        return left && right;
    }
```