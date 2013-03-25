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
    bool isSymmetric(TreeNode *x, TreeNode *y){
        if(x == NULL && y==NULL)return true;
        if(x == NULL || y==NULL) 
            return false;
        if(x->val!=y->val) 
            return false;
        bool stdr ;
        bool drst;
        stdr = isSymmetric(x->left,y->right);
        drst = isSymmetric(x->right,y->left);
        if( stdr == true && drst == true){
            return true;
        }
        return false;
        
    }
    bool isSymmetric(TreeNode *root) {
        if(root==NULL) return true;
        return isSymmetric(root->left,root->right);
        
    }
};