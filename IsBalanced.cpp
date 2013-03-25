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
    int maxD(TreeNode * root) {
        if( root == NULL){ 
            return 0;
        }
        return 1 + max(maxD(root -> left),maxD(root->right ) ) ;
    }
public:
    bool isBalanced(TreeNode *root) {
        if( root == NULL) {
            return true;            
        }
        int aux =  maxD(root->left) - maxD(root->right);
        if( aux < 0 ) { aux = - aux;}
        if( aux > 1 ) {return false;}
        return isBalanced (root->left) & isBalanced (root->right);
    }
};