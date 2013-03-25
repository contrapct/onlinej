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
  
    int minDepth(TreeNode *root) {
        if( root == NULL){ 
            return 0;
        }
        if(root->left == NULL && root->right == NULL) return 1;
        int m =10000 ;
        if(root ->left !=NULL) 
            m = minDepth(root->left);
        if(root->right!=NULL)
            m = min(m,minDepth(root->right));
        
        return 1 + m;
    }
    
};