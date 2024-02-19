## 二叉树part01
### 144.二叉树的前序遍历  145.二叉树的后序遍历  94.二叉树的中序遍历

#### 一些要注意的点
vector不像数组，引用要记得加一个&，void xxxx(vector<int>& vec){}


#### 递归 144 145 94
前中后序递归遍历比较简单
```c++
//前序
void traversal1(TreeNode * tree, vector<int>& vec){
        if(tree == NULL){
            return;
        }
        vec.push_back(tree->val);
        traversal1(tree->left, vec);
        traversal1(tree->right, vec);
}
//中序
void traversal2(TreeNode* cur, vector<int>& result){
        if(cur == NULL) return;
        traversal2(cur->left, result);
        result.push_back(cur->val);
        traversal2(cur->right, result);
};
//后序
void traversal3(TreeNode* cur, vector<int>& result){
        if(cur == NULL) return;
        traversal3(cur->left, result);
        traversal3(cur->right, result);
        result.push_back(cur->val);
}
    
vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
```


=====


----
#### 非递归

前序后序逻辑相同。中序不一样

前序
```c++
vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if(root == NULL) return result;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return result;
    }
```

后序
```c++
vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->left) st.push(node->left); // 相对于前序遍历，这更改一下入栈顺序
            if (node->right) st.push(node->right);
        }
        reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
        return result;
    }
```

=====

中序
```c++
vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) { // 指针来访问节点，访问到最底层
                st.push(cur); // 将访问的节点放进栈
                cur = cur->left;                // 左
            } else {
                cur = st.top(); // 从栈里弹出的数据，就是要放进result里的
                st.pop();
                result.push_back(cur->val);     // 中
                cur = cur->right;               // 右
            }
        }
        return result;
    }
```



