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
    bool isSameTree(TreeNode* a, TreeNode* b)
    {
        if(a == NULL && b == NULL)
        return true;
        else if(a == NULL || b == NULL)
        return false;
        if(a->val == b->val)
        {
            return isSameTree(a->left, b->left) & isSameTree(a->right, b->right);
        }
        else
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return false;
        if(root->val == subRoot->val)
        {
            if(isSameTree(root, subRoot))
                return true;
            else return isSubtree(root->left, subRoot) | isSubtree(root->right, subRoot);
        }
        else return isSubtree(root->left, subRoot) | isSubtree(root->right, subRoot);
    }
};
