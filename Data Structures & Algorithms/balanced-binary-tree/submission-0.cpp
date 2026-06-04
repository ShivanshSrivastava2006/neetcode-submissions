/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool istrue = true;
    int height(TreeNode* root)
    {
        if(root == NULL) return 0;
        int L = height(root->left);
        int R = height(root->right);
        if(abs(L-R) > 1) istrue = false;
        return 1 + max(L,R);
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return istrue;
    }
};
