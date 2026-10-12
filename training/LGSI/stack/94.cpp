#include <bits/stdc++.h>
using namespace std;

/**
 * @author  breadOnLaptop
 * @date 2026-10-12
 *
 * TITLE: 94. Binary Tree Inorder Traversal
 * TOPIC: Stack based DFS
 */

class Solution {
    private:
    vector<int> res;

    void build_res(TreeNode* root) {
        if(root == nullptr) return;

        build_res(root->left);
        res.push_back(root->val);
        build_res(root->right);
    }

    public:
    vector<int> inorderTraversal(TreeNode* root) {
        build_res(root);

        return res;
    }
};
