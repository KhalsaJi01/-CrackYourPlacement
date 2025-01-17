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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
        {
            return false;
        }
        if(root->left==NULL&&root->right==NULL)
        {
            targetSum-=root->val;
            if(targetSum==0)
            {
                return true;
            }
            return false;
        }
       bool lefte=hasPathSum(root->left,targetSum-root->val);
       bool righte = hasPathSum(root->right,targetSum-root->val);
       return lefte||righte;
    }
};