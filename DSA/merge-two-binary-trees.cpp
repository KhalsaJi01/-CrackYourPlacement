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
void solve(TreeNode* root1,TreeNode*root2){
    if(root1==NULL&&root2==NULL)
    {
        return ;
    }
    if(root1!=NULL&&root2!=NULL)
    {
        root1->val=root1->val+root2->val;
    }
    else if(root1==NULL||root2==NULL)
    {
        return;
    }
    solve(root1->left,root2->left);
    if(root1->left==NULL&&root2->left!=NULL)
    {
        root1->left=root2->left;
    }
    solve(root1->right,root2->right);
    if(root1->right==NULL&&root2->right!=NULL)
    {
        root1->right=root2->right;
    }

}


    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL&&root2==NULL)
        {
            return root1;
        }
        if(root1==NULL&&root2!=NULL)
        {
            return root2;
        }
        else if (root2==NULL&&root1!=NULL)
        {
            return root1;
        }
        solve(root1,root2);
        return root1;
        
    }
};