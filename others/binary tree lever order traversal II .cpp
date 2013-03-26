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
   vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > sol;
        list<int> coadaN;
        vector<int> lista;
        list<TreeNode *> coadaT;
        if(root ==NULL) 
            return sol;
        int nr = 1;
        
        //lista.push_back(root->val);
        coadaT.push_back(root);
        coadaN.push_back(1);
        while(coadaT.empty()== false){
            int auxn = coadaN.front(); coadaN.pop_front();
            TreeNode * aux = coadaT.front(); coadaT.pop_front();
            if(auxn!=nr){
                nr++;
                sol.push_back(lista);
                lista.erase(lista.begin(),lista.end());
                lista.push_back(aux->val);
            }else{
                lista.push_back(aux->val);
            }
            if(aux ->left!=NULL){
                coadaN.push_back(nr+1);
                coadaT.push_back(aux->left);
            }
            
            if(aux ->right!=NULL){
                coadaN.push_back(nr+1);
                coadaT.push_back(aux->right);
            }   
        }
        sol.push_back(lista);
        reverse(sol.begin(),sol.end());
        return sol;
    }
};
