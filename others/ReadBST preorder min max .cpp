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
      TreeNode *buildTree(vector<int> &preorder, int &nr, int max, int min){
        if(nr == preorder.size() ){ return NULL;}      

        if(preorder[nr] <min || preorder[nr] > max)
        {
            return NULL;            
        }
        TreeNode * root = new TreeNode(preorder[nr]);
        ++nr;
        if( nr != preorder.size() && preorder[nr] <= root->val) {
                root->left = buildTree(preorder,nr,root->val, min);
            }
        if( nr != preorder.size() && preorder[nr] > root->val){
            root->right = buildTree(preorder,nr, max,root->val+1);
        }
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size()==0) return NULL;
        int n = preorder.size();
        int max = 20000;
        int k=0;
        return buildTree(preorder,k,max,-20000);        
    }
};