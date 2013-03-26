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
    vector<int> SRDret,DRSret;
    void SRD(TreeNode *root){
        if(root == NULL) 
            return;
        SRD(root->left);
        SRDret.push_back(root->val);
        SRD(root->right);
    }
    void DRS(TreeNode *root){
        if(root == NULL) 
            return;
        DRS(root->right);
        DRSret.push_back(root->val);
        DRS(root->left);
    }
    bool Compare(){
        int n = SRDret.size();
        int m = DRSret.size();
        if(n!=m) return false;
        for(int i=0;i<m;++i){
            if(SRDret[i]!=DRSret[i]) 
                return false;
        }
        return true;
    }
    
    bool isSymmetric(TreeNode *root) {
        SRDret.erase(SRDret.begin(),SRDret.end());
        DRSret.erase(DRSret.begin(),DRSret.end());
        SRD(root);
        DRS(root);
        return Compare();
        
    }
};