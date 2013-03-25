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
   void Inordine(TreeNode * root , vector<int> & aux){
    if(root == NULL) return;
	Inordine(root->left,aux);
	aux.push_back(root->val);
	Inordine(root->right,aux);
}
void Inlocuieste(TreeNode * root,int &a,int &b,bool & oka, bool & okb){
	if(root == NULL) return;
	int ok = 0;
	if( oka == false && root->val == a  ) {root->val = b; oka= true;ok = 1;}
	if( ok == 0 && okb == false && root->val == b){root->val = a; okb = true;}
	if(oka == true && okb == true ) return;
	Inlocuieste(root->left,a,b,oka,okb);
	Inlocuieste(root->right,a,b,oka,okb);
}
void recoverTree(TreeNode *root) {
	vector<int> aux,aux1;
	Inordine(root,aux);
	
	int n = aux.size();
	for(int i=0;i<n;i++){
		aux1.push_back(aux[i]);
	}
	sort(aux1.begin(),aux1.end());
	int ok = 1;
	int a,b;
	for(int i=0;i<n;++i){
		if(aux[i]!=aux1[i]) {
			if(ok == 1) {a = aux[i];ok =2;}
			else { b = aux[i];break;}
		}
	}
	bool oka = false,okb=false;
	Inlocuieste(root,a,b,oka,okb);
}
};