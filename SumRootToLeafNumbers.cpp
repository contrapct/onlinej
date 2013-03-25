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
    int sumNumbers(TreeNode * root, int sum){
        int stg=0,drp=0;
        if(root==NULL) return sum;
        if(root->left ==NULL && root->right == NULL) return sum*10+root->val;
        if(root->left!=NULL) stg = sumNumbers(root->left,sum*10+root->val);
        if(root->right!=NULL) drp = sumNumbers(root->right,sum*10+root->val);
        return stg+drp;        
    }
    int sumNumbers(TreeNode *root) {
        if(root==NULL) return 0;
       return sumNumbers(root,0);        
    }
};