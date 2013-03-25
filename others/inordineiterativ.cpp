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
    vector<int> inorderTraversal(TreeNode *root) {
        TreeNode * p;            //folosind o stiva
        vector<TreeNode*> stiva;
        vector<int> sol;
        if(!root) { return sol;}
        p=root;
        while(p!=NULL || stiva.empty()==false){
            while(p!=NULL){
                stiva.push_back(p);
                p=p->left;
            }
        p = stiva.back();
        stiva.pop_back();
        sol.push_back(p->val);
        p=p->right;
        }        
    }
};