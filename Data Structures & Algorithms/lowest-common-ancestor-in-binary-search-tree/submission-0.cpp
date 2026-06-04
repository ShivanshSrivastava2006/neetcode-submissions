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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return root;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        if((root->val > p->val) && (root->val > q->val))
            return lowestCommonAncestor(l, p, q);
        else if((root->val < p->val) && (root->val < q->val) )
            return lowestCommonAncestor(r, p, q);
        else
            return root;
    }
};
