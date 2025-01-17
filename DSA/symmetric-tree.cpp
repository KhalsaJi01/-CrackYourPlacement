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
bool solve (TreeNode*head1,TreeNode*head2)
{
    if(head1==NULL&&head2==NULL)
    {
        return true;
    }
    if(head1&&head2&&head1->val==head2->val)
    {
        return solve(head1->left,head2->right)&&solve(head1->right,head2->left);
    }
    return false;
}
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        TreeNode* head1=root;
        TreeNode* head2=root;
        return solve(head1,head2);
    }
};