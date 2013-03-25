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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > sol;
        list<int> coadaN;
        vector<int> lista;
        list<TreeNode *> coadaT;
        if(root ==NULL) 
            return sol;
        int nr = 1;
        coadaT.push_back(root);
        coadaN.push_back(1);
        while(coadaT.empty()== false){
            int auxn = coadaN.front(); coadaN.pop_front();
            TreeNode * aux = coadaT.front(); coadaT.pop_front();
            if(auxn!=nr){
                if(nr % 2 == 0 ) { reverse(lista.begin(),lista.end());}
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
        if(nr % 2 == 0 ) { reverse(lista.begin(),lista.end());}
        sol.push_back(lista);
        return sol;
    }
};