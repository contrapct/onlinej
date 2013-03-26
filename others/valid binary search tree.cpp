/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode *root, int min,int max){
        if(root==NULL) return true;
        if(root->val < min || root->val > max)
            return false;
        bool ok = isValidBST(root->left,min,root->val-1);
        if( ok == false) return false;
        return isValidBST(root->right,root->val +1 ,max);
    }
    bool isValidBST(TreeNode *root) {
        if(root==NULL) return true;

        return isValidBST(root,-100000000,100000000);        
    }
};