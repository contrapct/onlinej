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
    int maxPathSum(TreeNode *root,int & chestie){
         if(root==NULL) return 0;
        int stg = maxPathSum(root->left,chestie);
        int drp = maxPathSum(root->right,chestie);
        int maxx = max(root->val,stg+root->val);
        maxx = max(maxx,drp+root->val);
        if(drp+stg+root->val > maxx){
            chestie = max(chestie, drp+stg+root->val);
            return maxx;
        }
        chestie = max(maxx,chestie);
        chestie = max(chestie,root->val);
        return maxx;
    }
    int maxPathSum(TreeNode *root) {
        int chestie = -1000;
        maxPathSum(root,chestie);
        return chestie;
    }
};